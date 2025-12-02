#include "../utils/read-lines.cpp"
#include <iostream>
#include <vector>

class PartOneDial {
public:
  int currentValue = 50;
  int numberOfZeroes = 0;

  void increment(int amount) {
    for (int i = 0; i < amount; i++) {
      currentValue++;

      if (currentValue == 100) {
        currentValue = 0;
      }
    }
    if (currentValue == 0) {
      numberOfZeroes++;
    }
  };

  void decrement(int amount) {
    for (int i = 0; i < amount; i++) {
      currentValue--;

      if (currentValue == -1) {
        currentValue = 99;
      }
    }
    if (currentValue == 0) {
      numberOfZeroes++;
    }
  };
};

class PartTwoDial {
public:
  int currentValue = 50;
  int numberOfZeroes = 0;

  void increment(int amount) {
    for (int i = 0; i < amount; i++) {
      if (currentValue == 0) {
        numberOfZeroes++;
      }
      currentValue++;

      if (currentValue == 100) {
        currentValue = 0;
      }
    }
  };

  void decrement(int amount) {
    for (int i = 0; i < amount; i++) {
      if (currentValue == 0) {
        numberOfZeroes++;
      }
      currentValue--;

      if (currentValue == -1) {
        currentValue = 99;
      }
    }
  };
};

int solvePartOne(std::vector<std::string> lines) {
  PartOneDial dial;

  for (std::string line : lines) {
    char direction = line[0];
    line.erase(0, 1);

    if (direction == 'L') {
      dial.decrement(std::stoi(line));
    } else if (direction == 'R') {
      dial.increment(std::stoi(line));
    } else {
      std::cout << "could not parse direction: " << line;
    }
  }

  return dial.numberOfZeroes;
}

int solvePartTwo(std::vector<std::string> lines) {
  PartTwoDial dial;

  for (std::string line : lines) {
    char direction = line[0];
    line.erase(0, 1);

    if (direction == 'L') {
      dial.decrement(std::stoi(line));
    } else if (direction == 'R') {
      dial.increment(std::stoi(line));
    } else {
      std::cout << "could not parse direction: " << line;
    }
  }

  return dial.numberOfZeroes;
}

int main() {

  std::vector<std::string> lines = readInputLines();

  auto solutionOne = solvePartOne(lines);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(lines);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
