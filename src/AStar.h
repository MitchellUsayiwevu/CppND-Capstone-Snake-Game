//
// Created by robotics on 11/15/24.
//

#ifndef SDL2TEST_AStar_H
#define SDL2TEST_AStar_H

#include <algorithm>  // for sort
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class State {kEmpty, kObstacle, kClosed, kPath,kStart,kFinish};

class AStar {

public:
    AStar(int init[2], int goal[2]);
    ~AStar();
    void PrintBoard(const std::vector<std::vector<State>> board);
    std::string CellString(State cell);
    std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]);
    void ExpandNeighbors(const std::vector<int> &current, int goal[2], std::vector<std::vector<State>> &grid);
    void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<State>> &grid);
    bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid);
    int Heuristic(int x1, int y1, int x2, int y2);
    void CellSort(std::vector<std::vector<int>> *v);
    static bool Compare(const std::vector<int> a, const std::vector<int> b);
    std::vector<std::vector<State>> ReadBoardFile(std::string path);
    std::vector<State> ParseLine(std::string line);
    void FindSolutionPath(const std::vector<std::vector<State>> board);


private:

// directional deltas
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    const int init_[2];
    const int goal_[2];
    std::vector<std::vector<int>> open {};
    std::vector<std::vector<State>> grid;
    std::vector<std::vector<int>> final_path;
};


#endif //SDL2TEST_AStar_H
