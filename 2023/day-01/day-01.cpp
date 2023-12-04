#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

void part1(std::vector<std::string> lines) {
    int total = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string value1 = "empty";
        std::string value2 = "empty";
        
        for(int left = 0, right = lines[i].size() - 1; left < lines[i].size(); left++, right--) {
            if( isdigit(lines[i][left]) && value1 == "empty") {
            value1 = lines[i][left];
            }
            if( isdigit(lines[i][right]) && value2 == "empty") {
            value2 = lines[i][right];
            };
        }
    total += stoi(value1 + value2);
    }
std::cout << "part one total calibration: " << total << std::endl;
}

void part2(std::vector<std::string> lines) {
    int total = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string value1 = "empty";
        std::string value2 = "empty";
        
        for(int left = 0, right = lines[i].size() - 1; left < lines[i].size(); left++, right--) {
            if( isdigit(lines[i][left]) && value1 == "empty") {
            value1 = lines[i][left];
            }
            if( isdigit(lines[i][right]) && value2 == "empty") {
            value2 = lines[i][right];
            };
        }
    total += stoi(value1 + value2);
    }
std::cout << "part two total calibration: " << total << std::endl;
}

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
    part2(lines);
    return 0;
}