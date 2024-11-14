//
// Created by robotics on 11/13/24.
//

#ifndef SDL2TEST_TRACKSCORES_H
#define SDL2TEST_TRACKSCORES_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

class trackScores {
public:
    trackScores(std::string & player_name , int&& score);
    ~trackScores();
    bool checkNameAlreadyExists(std::string & name1, const std::string & name2);
    bool compareScores(int& score1, const int& score2);
    static bool orderTheScoresFromLargest(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
    void savePlayerName();

private:
    std::string filename{"../src/highest_scores.txt"};

    std::vector<std::pair<std::string, int>> scores_vector;
    std::string line;

    std::string line_name{};
    int line_score{};

    bool name_found{false};

    const std::string player_name_;
    const int score_;

};


#endif //SDL2TEST_TRACKSCORES_H
