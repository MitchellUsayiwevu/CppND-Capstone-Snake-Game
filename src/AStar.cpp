//
// Created by robotics on 11/15/24.
//

#include "AStar.h"

AStar::AStar(int init[2], int goal[2]):init_{init[0],init[1]},goal_{goal[0],goal[1]}{

}

AStar::~AStar(){

}

std::vector<State> AStar::ParseLine(std::string line) {
    std::istringstream sline(line);
    int n;
    char c;
    std::vector<State> row;
    while (sline >> n >> c && c == ',') {
        if (n == 0) {
            row.push_back(State::kEmpty);
        } else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}


std::vector<std::vector<State>> AStar::ReadBoardFile(std::string path) {
    std::ifstream myfile (path);
    std::vector<std::vector<State>> board{};
    if (myfile) {
        std::string line;
        while (std::getline(myfile, line)) {
            std::vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}


/**
 * Compare the F values of two cells.
 */
bool AStar::Compare(const std::vector<int> a, const std::vector<int> b) {
    int f1 = a[2] + a[3];
    int f2 = b[2] + b[3];
    return f1 > f2;
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void AStar::CellSort(std::vector<std::vector<int>> *v) {
    sort(v->begin(), v->end(), Compare);
}


// Calculate the manhattan distance
int AStar::Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}


/**
 * Check that a cell is valid: on the grid, not an obstacle, and clear.
 */
bool AStar::CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid) {
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());
    if (on_grid_x && on_grid_y)
        return grid[x][y] == State::kEmpty;
    return false;
}


/**
 * Add a node to the open list and mark it as open.
 */
void AStar::AddToOpen(int x, int y, int g, int h, std::vector<std::vector<State>> &grid) {
    // Add node to open vector, and mark grid cell as closed.
    open.push_back(std::vector<int>{x, y, g, h});
    grid[x][y] = State::kClosed;
}


/**
 * Expand current nodes's neighbors and add them to the open list.
 */
void AStar::ExpandNeighbors(const std::vector<int> &current, int goal[2], std::vector<std::vector<State>> &grid) {
    // Get current node's data.
    int x = current[0];
    int y = current[1];
    int g = current[2];

    // Loop through current node's potential neighbors.
    for (int i = 0; i < 4; i++) {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        // Check that the potential neighbor's x2 and y2 values are on the grid and not closed.
        if (CheckValidCell(x2, y2, grid)) {
            // Increment g value and add neighbor to open list.
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, grid);
        }
    }
}


/**
 * Implementation of A* search algorithm
 */
std::vector<std::vector<State>> AStar::Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]) {
    // Create the vector of open nodes.
    // Initialize the starting node.
    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0],goal[1]);

    AddToOpen(x, y, g, h, grid);

    while (open.size() > 0) {
        // Get the next node
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        grid[x][y] = State::kPath;

        // Check if we're done.
        if (x == goal[0] && y == goal[1]) {
            // TODO: Set the init grid cell to kStart, and
            // set the goal grid cell to kFinish before returning the grid.
            grid[init[0]][init[1]]=State::kStart;
            grid[x][y]=State::kFinish;
            return grid;
        }

        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(current, goal, grid);
    }

    // We've run out of new nodes to explore and haven't found a path.
    std::cout << "No path found!" << "\n";
    return std::vector<std::vector<State>>{};
}


std::string AStar::CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️   ";
        case State::kPath: return "🚗   ";
        case State::kStart: return "🚦   ";
        case State::kFinish: return "🏁   " ;
        default: return "0   ";
    }
}


void AStar::PrintBoard(const std::vector<std::vector<State>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << CellString(board[i][j]);
        }
        std::cout << "\n";
    }
}

std::vector<AstarDirection> AStar::FindSolutionPath(const std::vector<std::vector<State>> board){

    final_path.push_back({init_[0],init_[1]});

    if (init_[0]<goal_[0] && init_[1]<goal_[1]){

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == State::kPath ){
                    final_path.push_back({i,j});
                }
            }
        }
//        std::cout<<"case 1"<<std::endl;

    }

    else if (init_[0]<goal_[0] && init_[1]>goal_[1]){

        for (int i = 0; i < board.size(); i++) {
            for (int j = (board[i].size()-1); j > 0 ; j--) {
                if(board[i][j] == State::kPath ){
                    final_path.push_back({i,j});
                }
            }
        }

//        std::cout<<"case 2"<<std::endl;

    }

    else if (init_[0]>goal_[0] && init_[1]<goal_[1]){

        for (int i = (board.size() -1); i >0 ; i--) {
            for (int j = 0; j < board[i].size() ; j++) {
                if(board[i][j] == State::kPath ){
                    final_path.push_back({i,j});
                }
            }
        }

//        std::cout<<"case 3"<<std::endl;

    }
    else{
        for (int i = ( (board.size() ) -1); i >0; i--) {
            for (int j = ( ( board[i].size() ) - 1); j >0 ; j--) {
                if(board[i][j] == State::kPath ){
                    final_path.push_back({i,j});
                }
            }
        }

//        std::cout<<"case 4"<<std::endl;

    }

    final_path.push_back({goal_[0],goal_[1]});

    for (int i=0; i<( final_path.size() - 1 );i++){

        FirstDirection( final_path[i], final_path[i+1]);
    }

    return actions;
    // add part of picking which action to take

}

void AStar::FirstDirection(std::vector<int>& a, std::vector<int>& b){

    if (a[0]==b[0]){
        if (b[1]>a[1]){
            actions.push_back(AstarDirection::Right);
        }else if(a[1]>b[1]){
            actions.push_back(AstarDirection::Left);
        }
    }
    else if (a[1]==b[1]){
        if(a[0]>b[0]){
            actions.push_back(AstarDirection::Up);
        }
        else if(b[0]>a[0]){
            actions.push_back(AstarDirection::Down);
        }
    }
    else {
        actions.push_back(AstarDirection::Down);;    //default action
    }
}
