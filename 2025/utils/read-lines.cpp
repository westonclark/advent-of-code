#include <fstream>
#include <vector>

std::vector<std::string> readInputLines() {
  std::vector<std::string> lines;

  std::fstream file;
  file.open("./input.txt");

  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
      lines.push_back(line);
    }

    file.close();
  }

  return lines;
}
