#include <iostream>
#include <vector>
#include <string>

class PQueue {
 public :
 virtual void enqueue(const std :: string& elem);
 virtual std :: string extractMin ();
 virtual const std :: string& min() const;
 static PQueue *merge(PQueue *one , PQueue *two);
 private :
 // implementation dependent member variables and helper methods
 };


// Question 7: Implementation 2: Binary Heap - HeapPQueue class
class HeapPQueue : public PQueue {
  public:
    HeapPQueue();
    ~HeapPQueue();

    static HeapPQueue* merge(HeapPQueue* one, HeapPQueue* two);

    void enqueue(const std::string& elem) override;
    std::string extractMin() override;
    const std::string& min() const override;

  private:
    // WRITE YOUR CODE (if necessary)
    std::vector<std::string> vec;
    void heapifyDown(std::vector<std::string>& vec, int idx);
    void heapifyUp(std::vector<std::string>& vec, int idx);
    void makeHeap(std::vector<std::string>& vec);
};

HeapPQueue::HeapPQueue() : PQueue() /* WRITE YOUR CODE (if necessary) */ {
  // WRITE YOUR CODE
  vec.push_back(""); // put "" in the 0th index
}

HeapPQueue::~HeapPQueue() {
  // WRITE YOUR CODE
  // code not neccessary
}

HeapPQueue* HeapPQueue::merge(HeapPQueue* one, HeapPQueue* two) {
  // WRITE YOUR CODE
  HeapPQueue* ptr = new HeapPQueue();
  
  for (int i = 0; i < one->vec.size(); ++i) {
    ptr->vec.push_back(one->vec[i]);
  }
  for (int i = 0; i < two->vec.size(); ++i) {
    ptr->vec.push_back(two->vec[i]);
  }

  one->vec.clear();
  two->vec.clear();

  //make heap
  ptr->makeHeap(ptr->vec);

  return ptr;
}

void HeapPQueue::enqueue(const std::string& elem) {
  // WRITE YOUR CODE
  vec.push_back(elem);

  // bottom up heapify
  heapifyUp(vec, vec.size() - 1);
}

std::string HeapPQueue::extractMin() {
  // WRITE YOUR CODE
  if (vec.size() <= 1) {
    throw std::logic_error("the queue is empty");
  }
  std::string min = vec[1]; //1-based
  
  vec[1] = vec[vec.size() - 1]; // copy the value from the last node to the root
  vec.pop_back(); //remove the last node

  //top down heapify
  heapifyDown(vec, 1);

  return min;
}

const std::string& HeapPQueue::min() const {
  // WRITE YOUR CODE
  if (vec.size() <= 1) {
    throw std::logic_error("the queue is empty");
  }
  return vec[1]; //1-based
}

void HeapPQueue::heapifyDown(std::vector<std::string>& vec, int idx){
  int smallest = idx;
  int leftIdx = idx * 2;
  int rightIdx = idx * 2 + 1;

  if (leftIdx < vec.size() && vec[smallest] > vec[leftIdx]) {
    smallest = leftIdx;
  }
  if (rightIdx < vec.size() && vec[smallest] > vec[rightIdx]) {
    smallest = rightIdx;
  }
  if (smallest != idx) {
    std::swap(vec[smallest], vec[idx]);
    heapifyDown(vec, smallest);
  }
}

void HeapPQueue::makeHeap(std::vector<std::string>& vec) {
  for (int i = static_cast<int>(vec.size() / 2); i > 0; --i) {
    heapifyDown(vec, i);
  }
}

void HeapPQueue::heapifyUp(std::vector<std::string>& vec, int idx) {
  int parent = static_cast<int>(idx / 2);
  if (vec[idx] < vec[parent]) {
    std::swap(vec[idx], vec[parent]);
    heapifyUp(vec, parent);
  }
}