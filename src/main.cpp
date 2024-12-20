#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "trackScores.h"
#include "AStar.h"

int main() {

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

//  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
//  Controller controller;

//  std::unique_ptr<Renderer> renderer  = std::make_unique<Renderer>(kScreenWidth,kScreenHeight,kGridWidth,kGridHeight);
//  std::unique_ptr<Controller> controller = std::make_unique<Controller>();

  Game game(kGridWidth, kGridHeight, kScreenWidth,kScreenHeight,kGridWidth,kGridHeight);
  game.Run(  kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Your Score: " << game.GetScore().at(0) << "\n";
  std::cout << "Computer Score: " << game.GetScore().at(1) << "\n";
  std::cout << "Your Size: " << game.GetSize().at(0) << "\n";
  std::cout << "Computer Size: " << game.GetSize().at(1) << "\n";

  std::string player_name{};
  std::cout<<"Enter player name: "<<std::endl;
  std::cin>>player_name;

  trackScores trackObj(player_name , game.GetScore().at(0));
  trackObj.savePlayerName();

//  int init[2]{0, 0};
//  int goal[2]{4, 5};

//    int init[2]{0, 15};
//    int goal[2]{4, 5};

//    int init[2]{8, 5};
//    int goal[2]{2, 15};         //Astar fails test

//    int init[2]{4, 5};
//    int goal[2]{0, 0};
//
//    AStar AStarObj(init,goal);
//    auto board = AStarObj.ReadBoardFile("../src/2.board");
//    auto solution = AStarObj.Search(board, init, goal);
//    AStarObj.FindSolutionPath(solution);
//    AStarObj.PrintBoard(solution);

    return 0;
}