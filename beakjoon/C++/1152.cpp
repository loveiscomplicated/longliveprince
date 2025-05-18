#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string line;
  std::getline(std::cin, line);
  line.push_back(' ');
  std::vector<std::string> vec;
  


  std::string temp = "";
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] != ' ') {
      temp.push_back(line[i]);
    } else {
      if (temp.size() != 0) {
        vec.push_back(temp);
        temp = "";
      }
    }
  }

  std::cout << vec.size() << std::endl;
  return 0;
}