#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> splitString(std::string input, char separator1, char separator2) {
    size_t pos;
    std::vector<std::string> text;

    while (!input.empty()) {
        pos = input.find(separator1);
        if (pos == std::string::npos) {
            text.push_back(input);
            break;
        }
        text.push_back(input.substr(0, pos));
        input = input.substr(pos + 1);
    }

    while (!input.empty()) {
        pos = input.find(separator2); //find separator character position
        if (pos == std::string::npos) {
            text.push_back(input);
            break;
        }
        text.push_back(input.substr(0, pos));
        input = input.substr(pos + 1);
    }
    return text; //returns a vector with all the strings
}

void part1(std::vector<std::string> lines) {
    int total = 0;
    std::map<std::string, int> counts;

    for(int i = 0; i < lines.size(); i++) {
        std::vector<std::string> split = splitString(lines[i], ':', ';');
        split.erase (std::next(split.begin()));

        for(int j = 0; j < split.size(); j++) {
            std::cout << split[j] << std::endl;
        }
    }
    // std::cout << "total sum of games: " << total << std::endl;
}

// void part2(std::vector<std::string> lines) {

// }

int main() {

    std::vector<std::string> lines;
    std::fstream newfile;
    newfile.open("input.txt",std::ios::in);

    if (newfile.is_open()) { 
    std::string line;
    while(getline(newfile, line)) { 
        lines.push_back(line);
    }
    newfile.close(); 
}

    part1(lines);   
    return 0;
}