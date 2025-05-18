#include <iostream>
#include <string>
#include <vector>

int main () {
  std::string input;
  std::cin >> input;

  std::vector<int> vec(26, -1);
  for (int i = 0; i < input.size(); ++i) {
    if (vec[(int)input[i] - 97] == -1) {
      vec[(int)input[i] - 97] = i;
    }
  }

  
  for (int i = 0; i < vec.size() - 1; ++i) {
    std::cout << vec[i] << ' ';
  }
  std::cout << vec[vec.size() - 1] << std::endl;
  


  return 0;
}
