#include <iostream>
#include <string>

using namespace std;

class GameEntry {
  public:
    GameEntry(const string& n = "", int s = 0);
    string getName() const;
    int getScore() const;

  private:
    string name;
    int score;
};

GameEntry::GameEntry(const string &n, int s)
: name(n), score(s) {}

string GameEntry::getName() const {return name;}
int GameEntry::getScore() const {return score;}


class Scores{
  public:
  Scores(int maxEnt = 10); // constructor
  ~Scores();
  void add(const GameEntry& e);
  GameEntry remove(int i);
    //throw(IndexOutOfBounds); 이거 정의 따로 해줘야 함,
  
  private:
  int maxEntries;
  int numEntries;
  GameEntry* entries;
};

Scores::Scores(int maxEnt) {
  maxEntries = maxEnt;
  entries = new GameEntry[maxEntries];
  numEntries = 0;
}

Scores::~Scores() {
  delete[] entries;
}

void Scores::add(const GameEntry& e) {
  int newScore = e.getScore();
  if (numEntries == maxEntries) {
    if (e.getScore() <= entries[numEntries - 1].getScore()) {
      return;
    }
  }
  else numEntries ++;

  int i = numEntries - 2;
  while (i >= 0 && entries[i].getScore() < newScore) {
    entries[i + 1] = entries [i];
  }
  entries[i + 1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds) { // IndexOutOfBounds 정의 안 해서 오류 남
  if ((i < 0) || (i >= numEntries)) {
    throw IndexOutOfBound("Invalid index");
  GameEntry e = entries[i];
  for (int j = i + 1; j < numEntries; j++) {
    entries[j - 1] = entries[j];
  }
  numEntries--;
  return e;
  }
}

int main() {
  GameEntry a("Tom", 10);

  cout << a.getName() << endl;
  cout << a.getScore() << endl;
  
  return 0;
}