//
// Created by robotics on 11/13/24.
//

#include "trackScores.h"

trackScores::trackScores(std::string & player_name , int& score):player_name_(player_name),score_(score){

}

trackScores::~trackScores(){

}

bool trackScores::checkNameAlreadyExists(std::string & name1,  const std::string & name2){

    if (name1 == name2){
        return true;
    }
    else{
        return false;
    }
}

bool trackScores::compareScores(int& score1,  const int& score2){

    if (score1>score2){
        return false;
    }
    else{
        return true;
    }
}

bool trackScores::orderTheScoresFromLargest(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b){
    return a.second > b.second;
}

void trackScores::savePlayerName(){

    std::ifstream inFile ;
    inFile.open(filename);

    if(inFile.is_open()){

            while (std::getline(inFile, line)) {
                std::istringstream linestream(line);
                linestream >> line_name >> line_score;
                bool existing_entry = checkNameAlreadyExists(line_name, player_name_);

                if (existing_entry) {

                    bool updateScore = compareScores(line_score, score_);
                    if (updateScore) {
                        // new score is higher score
                        std::cout<<"append existing file, existing entry, higher score"<<std::endl;
                        scores_vector.emplace_back(player_name_,score_);

                    } else {  // old score was the higher than the new one
                        std::cout<<"append existing file, existing entry, no score change"<<std::endl;
                        scores_vector.emplace_back(line_name,line_score);

                    }

                    name_found = true;

                } else {

                    std::cout << "appended existing file with line as is" << std::endl;
                    scores_vector.emplace_back(line_name,line_score);
                }
            }
            if(name_found==false){
                std::cout << "appended existing file - name_found_false" << std::endl;
                scores_vector.emplace_back(player_name_,score_);
            }

        inFile.close();
    }
    else{ /// file doesn't exist
        std::cout << "File doesn't exist" << std::endl;
        scores_vector.emplace_back(player_name_,score_);
    }

    std::sort(scores_vector.begin(),scores_vector.end(),orderTheScoresFromLargest);

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        std::cout << "Opening the file for writing." << std::endl;

/// Write the modified lines back to the file
        for (const auto& modifiedLine : scores_vector) {
            outFile<< modifiedLine.first<<" "<<modifiedLine.second<< std::endl;
        }

        outFile.close();
    }

}