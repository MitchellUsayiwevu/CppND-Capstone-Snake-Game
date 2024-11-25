#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <mutex>
#include <condition_variable>
#include <deque>
#include <vector>

class Controller;

class Game {
 public:

  Game(std::size_t grid_width, std::size_t grid_height, std::size_t kScreenWidth, std::size_t kScreenHeight, std::size_t kGridWidth, std::size_t  kGridHeight);
  //  void Run(Controller const &controller, Renderer &renderer,
//           std::size_t target_frame_duration);
  void Run(std::size_t target_frame_duration);
  void CheckEvents();
  std::vector<int> GetScore() const;
  std::vector<int> GetSize() ;
  bool running = true;

  std::deque<SDL_Event> eventQueue;
  std::mutex queueMutex;
  std::condition_variable queueCondition;

 private:
//  Snake snake;

  SDL_Point food;
  const int num_snakes{2};
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  std::shared_ptr<Snake> snake;
  std::vector<std::shared_ptr<Snake>> snakes;
  int score{0};
  std::vector<int>scores{0,0};
  std::vector<int>sizes;
  bool _destroyed = false;

  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<Controller> controller;

  void PlaceFood();
  void Update();
};

#endif