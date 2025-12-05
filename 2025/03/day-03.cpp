#include "../utils/read-input.cpp"
#include <iostream>

auto solvePartOne(std::vector<std::string> lines) {
  int total = 0;

  for (auto line : lines) {
    int highValue = 0;
    int lowValue = 0;

    size_t highIndex = 0;

    for (size_t i = 0; i < line.length(); i++) {
      int currentValue = line[i] - '0';
      if (currentValue > highValue) {
        if (i == line.length() - 1) {
          break;
        }
        highValue = currentValue;
        highIndex = i;
      }
    }

    for (size_t i = highIndex + 1; i < line.length(); i++) {
      int currentNumber = line[i] - '0';
      if (currentNumber > lowValue) {
        lowValue = currentNumber;
      }
    }
    total += ((highValue * 10) + lowValue);
  }
  return total;
}

struct valueData {
  int highNumber;
  size_t highIndex;
};

valueData fingHighestValueInRange(std::string range, int startOfSearchRange,
                                  int endOfSearchRange) {
  int highValue = range[startOfSearchRange] - '0';
  size_t highIndex = startOfSearchRange;

  for (size_t i = startOfSearchRange; i <= endOfSearchRange; i++) {
    int currentValue = range[i] - '0';
    if (currentValue > highValue) {
      highValue = currentValue;
      highIndex = i;
    }
  }

  return {highValue, highIndex};
}

auto solvePartTwo(std::vector<std::string> lines) {
  const int MAX_NUMBER_OF_BATTERIES = 12;
  long long total = 0;

  for (auto line : lines) {
    std::string lineTotal = "";
    size_t currentIndex = 0;
    int maxSearchRange = line.length() - MAX_NUMBER_OF_BATTERIES;

    while (maxSearchRange < line.length()) {
      auto [highValue, highIndex] =
          fingHighestValueInRange(line, currentIndex, maxSearchRange);

      lineTotal += std::to_string(highValue);

      currentIndex = highIndex + 1;
      maxSearchRange++;
    }
    total += std::stoll(lineTotal);
  }
  return total;
}

int main() {
  std::vector<std::string> lines = readInputLines();

  auto solutionOne = solvePartOne(lines);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(lines);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
