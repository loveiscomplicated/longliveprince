#include <iostream>
#include <vector>


// Question 6: k-th nearest obstacle queries
std::vector<int> resultsArray(std::vector<std::vector<int>>& queries, int k) {
  // WRITE YOUR CODE
  std::vector<int> resultVector(queries.size());

  // make a vector that contains distances of each query
  std::vector<int> distanceArray = makeDistanceArray(queries);

  // make a vector that eventually become heap
  // do not become heap if the vector.size is less than k
  // always push -1 to the result vector if the vector.size is less than k
  std::vector<int> beforeHeap;
  
  int i = 0;
  while (beforeHeap.size() < k) {
    resultVector.push_back(-1);
    beforeHeap.push_back(distanceArray[i]);
    ++i;
  }

  // now the beforeHeap.size is k, we have to make it into heap
  makeHeap(beforeHeap);
  std::vector<int> &heap = beforeHeap; // in order to make the vaiable name clear

  for (; i < distanceArray.size(); ++i) {
    if (heap[0] < distanceArray[i]) {
      resultVector.push_back(heap[0]);
    } else {
      heapInsert(heap, distanceArray[i]);
      resultVector.push_back(heap[0]);
    }
  }

  return resultVector;
}

std::vector<int> makeDistanceArray(std::vector<std::vector<int> >& v) {
  std::vector<int> distanceArray(v.size() + 1);
  distanceArray.push_back(-1); // don't consider index 0 for convinence
  for (int i = 1; i <= v.size(); ++i) {
    int x = abs(v[i][0]);
    int y = abs(v[i][1]);
    distanceArray.push_back(x + y);
  }
  return distanceArray;
}


void heapify(std::vector<int> &array, int currentIndex) {
  int upperBound = array.size();
  int largest = currentIndex;
  int leftIdx = currentIndex * 2;
  int rightIdx = currentIndex * 2 + 1;
  
  if (leftIdx < upperBound && array[largest] < array[leftIdx]) {
    largest = leftIdx;
  }
  if (rightIdx < upperBound && array[largest] < array[rightIdx]) {
    largest = rightIdx;
  }
  if (largest != currentIndex) {
    // heapify()
    std::swap(array[largest], array[currentIndex]);
    heapify(array, largest);
  }
}

void makeHeap(std::vector<int> &array) {
  // bottom-up style makeHeap
  
  for (int i = static_cast<int>(array.size() / 2); i > 0; --i) {
    heapify(array, i);
  }
}

void heapInsert(std::vector<int> &array, int elem) {
  std::swap(elem, array[1]);
  heapify(array, 1);
}