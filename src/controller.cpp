#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include "AStar.h"


Controller::Controller(Game& game): game_(game){

}

void Controller::ChangeDirection(std::shared_ptr<Snake> &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
    if (snake->direction != opposite || snake->size == 1) snake->direction = input;
  return;
}

void Controller::HandleInput(bool &running, std::shared_ptr<Snake>& snake) const {
//void Controller::HandleInput(bool &running) const {

  while(true){

    SDL_Event e;

    std::unique_lock<std::mutex> ulock(game_.queueMutex);
    game_.queueCondition.wait(ulock,[this]{return !game_.eventQueue.empty();});
    e = std::move(game_.eventQueue.back());
    game_.eventQueue.clear();

    if (e.type == SDL_QUIT) {
      running = false;

    } else if (e.type == SDL_KEYDOWN) {
      std::cout << "Worker thread received key press: ";

      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection( snake, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection( snake,Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection( snake,Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection( snake,Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
      }
    }
  }

}

void Controller::HandleInputAstar(bool &running, std::shared_ptr<Snake>& snake, SDL_Point& food ) const {

    while(true){

        int init[2]{static_cast<int>(snake->head_x), static_cast<int>(snake->head_y)};
        int goal[2]{static_cast<int>(food.x), static_cast<int>(food.y)};

        AStar AStarObj(init,goal);
        auto board = AStarObj.ReadBoardFile("../src/2.board");
        auto solution = AStarObj.Search(board, init, goal);
        std::vector<AstarDirection> actions =  AStarObj.FindSolutionPath(solution);

        for (auto &dir:actions) {

            switch (dir) {
                case AstarDirection::Up:
                    ChangeDirection(snake, Snake::Direction::kUp,
                                    Snake::Direction::kDown);
//                    std::cout << " astar up" << std::endl;
                    break;
                case AstarDirection::Down:
                    ChangeDirection(snake, Snake::Direction::kDown,
                                    Snake::Direction::kUp);
//                    std::cout << " astar down" << std::endl;
                    break;
                case AstarDirection::Left:
                    ChangeDirection(snake, Snake::Direction::kLeft,
                                    Snake::Direction::kRight);
//                    std::cout << "astar left" << std::endl;
                    break;
                case AstarDirection::Right:
                    ChangeDirection(snake, Snake::Direction::kRight,
                                    Snake::Direction::kLeft);
//                    std::cout << "astar right" << std::endl;
                    break;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        }
    }

}