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
    std::string* arr;
    int capacity;
    int size;
    void heapifyDown(std::string* arr, int idx);
    void heapifyUp(std::string* arr, int idx);
    void makeHeap(std::string* arr);
    void expand();
};

HeapPQueue::HeapPQueue() : PQueue() /* WRITE YOUR CODE (if necessary) */ {
  // WRITE YOUR CODE
  capacity = 4;
  size = 0;
  arr = new std::string[capacity + 1]; 
  arr[0] = ""; // put "" in the 0th index
}

HeapPQueue::~HeapPQueue() {
  // WRITE YOUR CODE
  delete[] arr;
}

HeapPQueue* HeapPQueue::merge(HeapPQueue* one, HeapPQueue* two) {
  // WRITE YOUR CODE
  HeapPQueue* result = new HeapPQueue();
  result->size = one->size + two->size;
  result->capacity = result->size + 10; // making space
  result->arr = new std::string[result->capacity + 1];

  for (int i = 1; i <= one->size; ++i) {
    result->arr[i] = one->arr[i];
  }
  for (int i = 1; i <= two->size; ++i) {
    result->arr[i + one->size] = two->arr[i];
  }

  result->makeHeap(result->arr);
  one->size = two->size = 0; // deleting the previous arrays
  return result;
}

void HeapPQueue::expand() {
  int newcap = capacity * 2;
  std::string* newArr = new std::string[newcap + 1];
  
  for (int i = 1; i <= size; ++i) {
    newArr[i] = arr[i];
  }

  delete[] arr;

  arr = newArr;
  capacity = newcap;
}

void HeapPQueue::enqueue(const std::string& elem) {
  // WRITE YOUR CODE
  if (size + 1 > capacity) {
    //expand
    expand();
  }
  ++size;
  arr[size] = elem;


  // bottom up heapify
  heapifyUp(arr, size);
}

std::string HeapPQueue::extractMin() {
  // WRITE YOUR CODE
  if (size <= 1) {
    throw std::logic_error("the queue is empty");
  }
  std::string min = arr[1]; //1-based
  
  arr[1] = arr[size]; // copy the value from the last node to the root
  --size; //remove the last node

  //top down heapify
  heapifyDown(arr, 1);

  return min;
}

const std::string& HeapPQueue::min() const {
  // WRITE YOUR CODE
  if (size == 0) {
    throw std::logic_error("empty");
  }
  return arr[1];
}

void HeapPQueue::heapifyDown(std::string* arr, int idx){
  int smallest = idx;
  int leftIdx = idx * 2;
  int rightIdx = idx * 2 + 1;

  if (leftIdx <= size && arr[smallest] > arr[leftIdx]) {
    smallest = leftIdx;
  }
  if (rightIdx <= size && arr[smallest] > arr[rightIdx]) {
    smallest = rightIdx;
  }
  if (smallest != idx) {
    std::swap(arr[smallest], arr[idx]);
    heapifyDown(arr, smallest);
  }
}

void HeapPQueue::makeHeap(std::string* arr) {
  for (int i = static_cast<int>(size / 2); i > 0; --i) {
    heapifyDown(arr, i);
  }
}

void HeapPQueue::heapifyUp(std::string* arr, int idx) {
  int parent = static_cast<int>(idx / 2);
  if (parent >= 1 && arr[idx] < arr[parent]) {
    std::swap(arr[idx], arr[parent]);
    heapifyUp(arr, parent);
  }
}