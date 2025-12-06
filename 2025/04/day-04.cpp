#include "../utils/read-input.cpp"
#include <iostream>

auto solvePartOne(std::vector<std::string> &lines, bool replaceRoll) {
  int total = 0;

  char paperRoll = '@';
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].length(); j++) {
      int rollsFound = 0;

      char currentItem = lines[i][j];
      if (currentItem == paperRoll) {
        // up one
        if (i > 0 && lines[i - 1][j] == paperRoll) {
          rollsFound++;
        }
        // down one
        if (i < lines.size() - 1 && lines[i + 1][j] == paperRoll) {
          rollsFound++;
        }
        // left one
        if (j > 0 && lines[i][j - 1] == paperRoll) {
          rollsFound++;
        }
        // right one
        if (j < lines[i].length() - 1 && lines[i][j + 1] == paperRoll) {
          rollsFound++;
        }
        // top left
        if (i > 0 && j > 0 && lines[i - 1][j - 1] == paperRoll) {
          rollsFound++;
        }
        // top right
        if (i > 0 && j < lines[i].length() - 1 &&
            lines[i - 1][j + 1] == paperRoll) {
          rollsFound++;
        }
        // bottom left
        if (i < lines.size() - 1 && j > 0 && lines[i + 1][j - 1] == paperRoll) {
          rollsFound++;
        }
        // bottom right
        if (i < lines.size() - 1 && j < lines[i].length() - 1 &&
            lines[i + 1][j + 1] == paperRoll) {
          rollsFound++;
        }

        if (rollsFound < 4) {
          total++;
          // used in part 2
          if (replaceRoll) {
            lines[i][j] = '.';
          }
        }
      }
    }
  }
  return total;
}

auto solvePartTwo(std::vector<std::string> lines) {
  int total = 0;
  int linesRemoved = 0;

  do {
    linesRemoved = solvePartOne(lines, true);
    total += linesRemoved;
  } while (linesRemoved > 0);

  return total;
}

int main() {
  std::vector<std::string> lines = readInputLines();

  auto solutionOne = solvePartOne(lines, false);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(lines);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
