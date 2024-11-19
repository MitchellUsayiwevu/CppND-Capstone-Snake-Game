#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <memory>

class Controller {
 public:
    Controller(std::shared_ptr<Snake> snake_);
  void HandleInput(bool &running ) const;

 private:
    std::shared_ptr<Snake> snake;
  void ChangeDirection( Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif