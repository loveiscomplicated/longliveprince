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

