#include "../utils/read-input.cpp"
#include <iostream>

auto solvePartOne(std::vector<std::string> freshRanges,
                  std::vector<std::string> ingredients) {
  int total = 0;

  for (size_t i = 0; i < ingredients.size(); i++) {
    long long currentIngredient = std::stoll(ingredients[i]);
    bool ingredientFound = false;

    for (size_t j = 0; j < freshRanges.size(); j++) {
      if (ingredientFound) {
        break;
      }

      size_t dashLocation = freshRanges[j].find('-');
      long long start = stoll(freshRanges[j].substr(0, dashLocation));
      long long end = stoll(freshRanges[j].substr(dashLocation + 1));

      if (currentIngredient > start && currentIngredient < end) {
        total++;
        ingredientFound = true;
      }
    }
  }

  return total;
}

auto sortRangesByFirstValue(std::string &a, std::string &b) {
  size_t aDashLocation = a.find('-');
  size_t bDashLocation = b.find('-');
  long long aStart = stoll(a.substr(0, aDashLocation));
  long long bStart = stoll(b.substr(0, bDashLocation));

  return aStart < bStart;
}

auto solvePartTwo(std::vector<std::string> freshRanges) {
  long long total = 0;

  std::sort(freshRanges.begin(), freshRanges.end(), sortRangesByFirstValue);

  for (size_t i = 0; i < freshRanges.size(); i++) {
    size_t currentDash = freshRanges[i].find('-');
    long long currentStart = stoll(freshRanges[i].substr(0, currentDash));
    long long currentEnd = stoll(freshRanges[i].substr(currentDash + 1));

    while (i < freshRanges.size() - 1) {
      size_t nextDash = freshRanges[i + 1].find('-');
      long long nextStart = stoll(freshRanges[i + 1].substr(0, nextDash));
      long long nextEnd = stoll(freshRanges[i + 1].substr(nextDash + 1));

      // any overlap
      if (nextStart <= currentEnd) {
        // partial overlap, switch end values
        if (nextEnd > currentEnd) {
          currentEnd = nextEnd;
        }
        // full overlap, just skip the next
        i++;
      } else {
        // no overlap, continue on
        break;
      }
    }
    total += (currentEnd - currentStart + 1); // inclusive range
  }
  return total;
}

int main() {
  std::vector<std::string> lines = readInputLines();

  std::vector<std::string> freshRanges = {};
  std::vector<std::string> ingredients = {};

  for (auto line : lines) {
    if (line.find('-') != std::string::npos) {
      freshRanges.push_back(line);
    } else if (line != "") {
      ingredients.push_back(line);
    }
  }

  auto solutionOne = solvePartOne(freshRanges, ingredients);
  std::cout << "Part one solution: " << solutionOne << "\n";

  auto solutionTwo = solvePartTwo(freshRanges);
  std::cout << "Part two solution: " << solutionTwo << "\n";
}
