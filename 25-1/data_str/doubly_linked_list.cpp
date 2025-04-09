#include <iostream>
#include <string>

using namespace std;

struct node {
  int data;
  node* next;
  node* before;
};


class DLL {
  public:
  DLL();
  ~DLL();
  void pushfront(node n);
  void pushback(node n);
  void add(node n, int index);
  void remove(int index);

  
  private:
  node* front;
  node* back;
};

DLL::DLL() {
  node header;
  node trailer;
  header.before = nullptr;
  header.next = &trailer;
  header.data = 0;

  trailer.before = &header;
  trailer.next = nullptr;
  trailer.data = 0;

  front = header.next;
  back = header.before;
}

void DLL::add(node n, int index) {
  
}


int main() {

  return 0;
}