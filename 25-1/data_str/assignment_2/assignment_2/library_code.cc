// library_code.cc

#include <iostream>
#include <vector>
#include <string>

// Question 5: Find all duplicates in an array
int countDigits(int n) {
  int count = 0;
  while (n != 0) {
    n /= 10;
    ++count;
  }
  return count;
}

int getDigit(int n, int digit) {
  int pow = 1;
  while (digit > 1) {
    pow *= 10;
    --digit;
  }
  return (n / pow) % 10;
}

// Radix Sort
void radixSort(std::vector<int>& nums) {
  std::vector<std::vector<int>> digit(10);

  int maxDigit = 1;
  for (int n : nums) {
    maxDigit = std::max(maxDigit, countDigits(n));
  }

  for (int i = 1; i <= maxDigit; ++i) {
    std::vector<int> temp = nums;
    nums.clear();

    for (int iter = temp.size() - 1; iter >= 0; --iter) {
      int elem = temp[iter];
      int n = getDigit(elem, i);

      switch (n) {
        case 0: digit[0].push_back(elem); break;
        case 1: digit[1].push_back(elem); break;
        case 2: digit[2].push_back(elem); break;
        case 3: digit[3].push_back(elem); break;
        case 4: digit[4].push_back(elem); break;
        case 5: digit[5].push_back(elem); break;
        case 6: digit[6].push_back(elem); break;
        case 7: digit[7].push_back(elem); break;
        case 8: digit[8].push_back(elem); break;
        case 9: digit[9].push_back(elem); break;
      }
    }

    for (int d = 0; d < 10; ++d) {
      for (int val : digit[d]) {
        nums.push_back(val);
      }
      digit[d].clear();
    }
  }
}

std::vector<int> findDuplicates(std::vector<int>& nums) {
  // WRITE YOUR CODE
  radixSort(nums);
  std::vector<int> result;

  for (size_t i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1]) {
      if (result.empty() || result.back() != nums[i]) {
        result.push_back(nums[i]);
      }
    }
  }

  return result;
}

// Question 6: k-th nearest obstacle queries

class MaxHeap {
  public:
  std::vector<int> vec;
  MaxHeap(std::vector<std::vector<int>>& queries, int k);
  void insert(int elem);

  private:
  void heapify(std::vector<int>& vec, int idx);
  void makeHeap(std::vector<int>& vec);
  int size;
};

MaxHeap::MaxHeap(std::vector<std::vector<int>>& queries, int k) {
  size = k;
  int limit = std::min(k, static_cast<int>(queries.size()));
  for (int i = 0; i < limit; ++i) {
    vec.push_back(std::abs(queries[i][0]) + std::abs(queries[i][1]));
  }
  makeHeap(vec);
}

void MaxHeap::heapify(std::vector<int>& vec, int idx) { // O(log k)
  int largest = idx;
  int left = idx * 2 + 1; // 0-based
  int right = idx * 2 + 2;

  if (left < vec.size() && vec[left] > vec[largest]) {
    largest = left;
  }
  if (right < vec.size() && vec[right] > vec[largest]) {
    largest = right;
  }
  if (largest != idx) {
    std::swap(vec[largest], vec[idx]);
    heapify(vec, largest);
  }
}

void MaxHeap::makeHeap(std::vector<int>& vec) { // O(k)
  for (int i = static_cast<int>((vec.size() - 1) / 2); i >= 0; --i) {
    heapify(vec, i);
  }
}

void MaxHeap::insert(int elem) {
  if (elem < vec[0]) {
    //Remove top element and insert new element from input array if current max is larger than this.
    vec[0] = elem; 
    heapify(vec, 0);
  }
}

std::vector<int> resultsArray(std::vector<std::vector<int>>& queries, int k) {
  // WRITE YOUR CODE
  if (queries.size() < k) {
  std::vector<int> result(queries.size(), -1);
  return result;
  }
  
  std::vector<int> result;
  MaxHeap H = MaxHeap(queries, k);
  
  for (int i = 0; i < k - 1; ++i) {
    result.push_back(-1);
  }
  
  result.push_back(H.vec[0]);

  for (int j = k; j < queries.size(); ++j) {
    H.insert(std::abs(queries[j][0]) + std::abs(queries[j][1]));
    result.push_back(H.vec[0]);
  }
  
  return result;
}
// Question 7: Priority queue implementation
class PQueue {
 public :
 virtual void enqueue(const std :: string& elem) = 0;
 virtual std :: string extractMin () = 0;
 virtual const std :: string& min() const = 0;
 static PQueue *merge(PQueue *one , PQueue *two);
 private :
 // implementation dependent member variables and helper methods
 };

// Question 7: Implementation 1: Unsorted Vector - VectorPQueue class
class VectorPQueue : public PQueue {
  public:
    VectorPQueue();
    ~VectorPQueue();

    static VectorPQueue* merge(VectorPQueue* one, VectorPQueue* two);

    void enqueue(const std::string& elem) override;
    std::string extractMin() override;
    const std::string& min() const override;

  private:
    // update the private section with the list of
    // data members and helper methods needed to implement
    // the vector-based version of the PQueue.
    std::vector<std::string> vec;    
};

VectorPQueue::VectorPQueue() : PQueue() /* WRITE YOUR CODE (if necessary) */ {
  // WRITE YOUR CODE
  // code not neccessary
}

VectorPQueue::~VectorPQueue() {
  // WRITE YOUR CODE
  // code not neccessary
}

VectorPQueue* VectorPQueue::merge(VectorPQueue* one, VectorPQueue* two) {
  // WRITE YOUR CODE
  VectorPQueue* ptr = new VectorPQueue();
  std::vector<std::string>::iterator iter1 = one->vec.begin();
  std::vector<std::string>::iterator iter2 = two->vec.begin();

  while (iter1 != one->vec.end()) {
    ptr->enqueue(*iter1);
    ++iter1;
  }
  while (iter2 != two->vec.end()) {
    ptr->enqueue(*iter2);
    ++iter2;
  }
  one->vec.clear();
  two->vec.clear();
  return ptr;
}

void VectorPQueue::enqueue(const std::string& elem) {
  // WRITE YOUR CODE
  vec.push_back(elem);
}

std::string VectorPQueue::extractMin() {
  // WRITE YOUR CODE
  if (vec.empty()) { // exception handling
    throw std::logic_error("empty priority queue");
  }
  std::string min = vec[0];
  int idx = 0;
  for (int i = 1; i < vec.size(); ++i) {
    if (std::lexicographical_compare(vec[i].begin(), vec[i].end(), min.begin(), min.end())) {
      min = vec[i];
      idx = i;
    }
  }
  vec.erase(vec.begin() + idx);
  return min;
}

const std::string& VectorPQueue::min() const {
  // WRITE YOUR CODE
  if (vec.empty()) { // exception handling
    throw std::logic_error("empty priority queue");
  }  
  int idx = 0;
  for (int i = 1; i < vec.size(); ++i) {
    if (std::lexicographical_compare(vec[i].begin(), vec[i].end(), vec[idx].begin(), vec[idx].end())) {
      idx = i;
    }
  }
  return vec[idx];
}

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
  if (size == 0) {
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