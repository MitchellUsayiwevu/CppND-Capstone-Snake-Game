#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
//  Renderer(std::shared_ptr<Snake> snake_,const std::size_t screen_width, const std::size_t screen_height,
//             const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

//  void Render(std::shared_ptr<Snake> &snake, SDL_Point const &food);
    void Render(std::vector<std::shared_ptr<Snake>> & snakes, SDL_Point const &food);
//  void Render(SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;


//  std::shared_ptr<Snake> snake;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif