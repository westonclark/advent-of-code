#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

void part1(std::vector<std::string> lines) {
    // init acumulator count
    int total = 0;

    // loop through all lines 
    for(int i = 0; i < lines.size(); i++) {

        // init first and last variables set them to empty
        std::string value1 = "empty";
        std::string value2 = "empty";
        
        // loop thorugh each string from ftb and btf
        for(int left = 0, right = lines[i].size() - 1; left < lines[i].size() && right >= 0; left++, right--) {

            // if current character is a number and value isnt empty, assign that character to value
            if( isdigit(lines[i][left]) && value1 == "empty") {
            value1 = lines[i][left];
            }
            if( isdigit(lines[i][right]) && value2 == "empty") {
            value2 = lines[i][right];
            };
        }

        // concat values, convert to int, add to total 
        total += stoi(value1 + value2);
        }

    // print result    
    std::cout << "part one total calibration: " << total << std::endl;
}

void part2(std::vector<std::string> lines) {
    // init accumulator
    int total = 0;

    // create map of substrings of which to replace
    std::map <std::string, std::string> numbers;
    numbers["one"] = "one1one";
    numbers["two"] = "two2two";
    numbers["three"] = "three3three";
    numbers["four"] = "four4four";
    numbers["five"] = "five5five";
    numbers["six"] = "six6six";
    numbers["seven"] = "seven7seven";
    numbers["eight"] = "eight8eight";
    numbers["nine"] = "nine9nine";

    // loop through the lines
    for(int i = 0; i < lines.size(); i++) {

        // init first and last variables set them to empty
        std::string value1 = "empty";
        std::string value2 = "empty";

        // loop though each substring 
        for (const auto& pair : numbers) {
            // init index from which to replace from 
            size_t start = 0;

            // while the substring string exists in the string and index isnt infinity
            while((start = lines[i].find(pair.first, start)) != std::string::npos) {

                // replace the substring from the first character to the last with its corrisponding value
                lines[i].replace(start, pair.first.length(), pair.second);

                // set start index to end of newly replaced value
                start += pair.second.length();
            }
        }

        // loop thorugh each string from ftb and btf
        for(int left = 0, right = lines[i].size() - 1; left < lines[i].size(); left++, right--) {

            // if current character is a number and value isnt empty, assign that character to value
            if( isdigit(lines[i][left]) && value1 == "empty") {
            value1 = lines[i][left];
            }
            if( isdigit(lines[i][right]) && value2 == "empty") {
            value2 = lines[i][right];
            };
        }

        // concat values, convert to int, add to total 
        total += stoi(value1 + value2);
    }

    // print result    
    std::cout << "part two total calibration: " << total << std::endl;
}

int main() {

    // init vecotr to store input data
    std::vector<std::string> lines;

    // open input file
    std::fstream newfile;
    newfile.open("input.txt",std::ios::in);

    // if file is open
    if (newfile.is_open()) { 
    
        // loop through each line and push to vecotr 
        std::string line;
        while(getline(newfile, line)) { 
            lines.push_back(line);
        }

    // close file
    newfile.close(); 
    }

    // run parts 1 & 2
    part1(lines);   
    part2(lines);

    return 0;
}