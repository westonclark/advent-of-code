#include "../utils/read-input.cpp"
#include <cstddef>
#include <iostream>
#include <vector>

auto solvePartOne(std::vector<std::string> ranges) {
  long long total = 0;

  for (std::string range : ranges) {
    size_t dashLocation = range.find('-');
    auto start = std::stoll(range.substr(0, dashLocation));
    auto end = std::stoll(range.substr(dashLocation + 1));

    for (auto i = start; i <= end; i++) {
      std::string currentValue = std::to_string(i);

      if (currentValue.length() % 2 != 0) {
        continue;
      }

      std::string leftHalf = currentValue.substr(0, currentValue.length() / 2);
      std::string rightHalf = currentValue.substr(currentValue.length() / 2);

      if (leftHalf == rightHalf) {
        total += i;
      }
    }
  }
  return total;
}

auto solvePartTwo(std::vector<std::string> ranges) {
  long long total = 0;

  for (std::string range : ranges) {
    size_t dashLocation = range.find('-');
    auto start = std::stoll(range.substr(0, dashLocation));
    auto end = std::stoll(range.substr(dashLocation + 1));

    for (auto i = start; i <= end; i++) {
      std::string currentValue = std::to_string(i);

      int minChunkLength = 1;
      auto maxChunkLength = currentValue.length() / 2;
      for (auto j = minChunkLength; j <= maxChunkLength; j++) {
        int currentChunkLength = j;
        std::string currentChunk = currentValue.substr(0, currentChunkLength);

        std::string expectedResult;
        int numberOfRepeats = currentValue.length() / currentChunkLength;
        for (auto k = 0; k < numberOfRepeats; k++) {
          expectedResult += currentChunk;
        }

        if (expectedResult == currentValue) {
          total += i;
          break;
        }
      }
    }
  }
  return total;
}

int main() {
  std::vector<std::string> ranges = readInputCommas();

  auto solutionOne = solvePartOne(ranges);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(ranges);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
