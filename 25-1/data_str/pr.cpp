#include <iostream>
#include <string>

using namespace std;

class GameEntry {
  private:
    string name;
    int score;

  public:
    GameEntry(const string &n = "", int s = 0);
    string getName() const;
    int getScore() const;
};

GameEntry::GameEntry(const string &n, int s)
: name(n), score(s) { }

string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }


