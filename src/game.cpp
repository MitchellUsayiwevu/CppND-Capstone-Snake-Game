#include "game.h"
#include <iostream>
#include "SDL.h"
#include <thread>
#include <future>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t kScreenWidth, std::size_t kScreenHeight, std::size_t kGridWidth, std::size_t  kGridHeight)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {

    for (int i=0;i<num_snakes;i++) {

        snakes.emplace_back(std::make_shared<Snake>(Snake(grid_width, grid_height,i)));

    }

    snake = snakes.at(0);
//    renderer  = std::make_unique<Renderer>( snakes.at(0) ,kScreenWidth,kScreenHeight,kGridWidth,kGridHeight);
//    controller = std::make_unique<Controller>(snakes.at(0));

    renderer  = std::make_unique<Renderer>( kScreenWidth,kScreenHeight,kGridWidth,kGridHeight);
    controller = std::make_unique<Controller>(*this);
    PlaceFood();

}

void Game::CheckEvents(){

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                // Notify the worker thread
                {
                    std::lock_guard<std::mutex> lock(queueMutex);
                    eventQueue.emplace_back(event);
                }
                queueCondition.notify_one();
            } else if (event.type == SDL_KEYDOWN) {
                // Forward the event to the worker thread
                {
                    std::lock_guard<std::mutex> lock(queueMutex);
                    eventQueue.emplace_back(event);
                }
                queueCondition.notify_one();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }

}

void Game::Run( std::size_t target_frame_duration){
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  std::thread eventThread(&Game::CheckEvents,this);

  std::vector<std::thread> Inputthreads;

    Inputthreads.emplace_back(&Controller::HandleInput, std::move(controller.get()),std::ref(running), std::ref(snakes.at(0)));   //add snake 0
    Inputthreads.emplace_back(&Controller::HandleInputAstar, std::move(controller.get()), std::ref(running),std::ref(snakes.at(1)), std::ref(food) ); //add snake1

  while (running) {

    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
//    controller->HandleInput(running, std::ref(snakes.at(0)) );
    Update();
    renderer->Render(std::ref(snakes),food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
//      renderer->UpdateWindowTitle(score, frame_count);
      renderer->UpdateWindowTitle(scores.at(0), scores.at(1),  frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }

  eventThread.join();
  for(auto &thread:Inputthreads){
      thread.join();
  }

}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake->SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
    for(int i=0; i<num_snakes; i++) {

        if (!snakes.at(i)->alive) return;

        snakes.at(i)->Update();

        int new_x = static_cast<int>(snakes.at(i)->head_x);
        int new_y = static_cast<int>(snakes.at(i)->head_y);

        // Check if there's food over here
        if (food.x == new_x && food.y == new_y) {
            scores.at(i)++;
            PlaceFood();
            // Grow snake and increase speed.
            snakes.at(i)->GrowBody();
            snakes.at(i)->speed += 0.02;
        }
    }
}

std::vector<int>Game::GetScore() const { return scores; }

std::vector<int> Game::GetSize() {

    for (auto &snake:snakes){
        sizes.emplace_back(snake->size);
    }
    return sizes;
}