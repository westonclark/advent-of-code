#include "../utils/read-input.cpp"
#include <iostream>
#include <vector>

class Dial {
public:
  int currentValue = 50;

  void increment() {
    currentValue++;
    if (currentValue == 100) {
      currentValue = 0;
    };
  };

  void decrement() {
    currentValue--;
    if (currentValue == -1) {
      currentValue = 99;
    }
  }
};

int solvePartOne(std::vector<std::string> lines) {
  int numberOfZeroes = 0;
  Dial dial;

  for (std::string line : lines) {
    char direction = line[0];
    line.erase(0, 1);
    int amount = std::stoi(line);

    if (direction == 'L') {
      for (int i = 0; i < amount; i++) {
        dial.decrement();
      }
      if (dial.currentValue == 0) {
        numberOfZeroes++;
      }
    }

    if (direction == 'R') {
      for (int i = 0; i < amount; i++) {
        dial.increment();
      }
      if (dial.currentValue == 0) {
        numberOfZeroes++;
      }
    }
  }

  return numberOfZeroes;
}

int solvePartTwo(std::vector<std::string> lines) {
  int numberOfZeroes = 0;
  Dial dial;

  for (std::string line : lines) {
    char direction = line[0];
    line.erase(0, 1);

    if (direction == 'L') {
      int amount = std::stoi(line);
      for (int i = 0; i < amount; i++) {
        dial.decrement();
        if (dial.currentValue == 0) {
          numberOfZeroes++;
        }
      }
    }

    if (direction == 'R') {
      int amount = std::stoi(line);
      for (int i = 0; i < amount; i++) {
        dial.increment();
        if (dial.currentValue == 0) {
          numberOfZeroes++;
        }
      }
    }
  }

  return numberOfZeroes;
}

int main() {
  std::vector<std::string> lines = readInputLines();

  auto solutionOne = solvePartOne(lines);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(lines);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
