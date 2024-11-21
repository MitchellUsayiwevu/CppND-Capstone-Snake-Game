#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <memory>
#include <mutex>
#include <condition_variable>
#include <deque>
#include "game.h"

class Controller {
 public:
    Controller(Game& game);
//  void HandleInput(bool &running ) const;
    void HandleInput(bool &running, std::shared_ptr<Snake> &snake) const;
    void HandleInputAstar(bool &running, std::shared_ptr<Snake>& snake, SDL_Point& food ) const;

 private:
    Game& game_;
//    std::shared_ptr<Snake> snake;
    void ChangeDirection(std::shared_ptr<Snake> &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif