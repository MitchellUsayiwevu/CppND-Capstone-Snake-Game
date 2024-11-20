#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <memory>

class Controller {
 public:
//    Controller(std::shared_ptr<Snake> snake_);
//  void HandleInput(bool &running ) const;
    void HandleInput(bool &running, std::shared_ptr<Snake> &snake) const;
 private:
//    std::shared_ptr<Snake> snake;
    void ChangeDirection(std::shared_ptr<Snake> &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif