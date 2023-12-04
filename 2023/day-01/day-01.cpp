#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void part1(std::vector<std::string> lines) {
    int total = 0;

    for(int i = 0; i < lines.size(); i++) {
        std::string value1;
        std::string value2;
        bool value1found = false;

        for(int j = 0; j < lines[i].size(); j++) {
            if(isdigit(lines[i][j])) {
                if(!value1found) {
                    value1 = lines[i][j];
                    value1found = true;
                }
                value2 = lines[i][j];
            }
        }
        total += stoi(value1 + value2);
    }
    std::cout << "total calibration: " << total << std::endl;
}

void part2(std::vector<std::string> lines) {

    // for(int k = 0; k < lines.size(); k++) {
    //    if (lines[k].find("one") != std::string::npos) {
    //     std::cout << "found!" << ' ' << lines[k] << std::endl;
    //     }
    // }


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
    // part2(lines);
    return 0;
}