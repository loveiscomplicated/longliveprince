#include <iostream>
#include <map>
#include <string>
#include <vector>


int main() {
  
  std::map<std::string, std::string> map1 = {{"Algorithm", "204"}, {"DataAnalysis", "207"}, {"ArtificialIntelligence", "302"}, {"CyberSecurity", "B101"}, {"Network", "303"}, {"Startup", "501"}, {"TestStrategy", "105"}};
  int num;
  std::cin >> num;
  std::vector<std::string> vec;

  for (int i = 0; i < num; ++i) {
    std::string temp;
    std::cin >> temp;
    vec.push_back(temp);
  }

  for (std::string i : vec) {
    std::cout << map1[i] << std::endl;
  }

 
  
  return 0;
}