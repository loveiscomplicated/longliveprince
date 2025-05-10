// test_runner.cc

#include <gtest/gtest.h>
#include "library_code.cc"

TEST(findDuplicates, Question5) {
  std::vector<int> nums;
  std::vector<int> rhs;
    
  // Example 1
  nums = std::vector<int>{4,3,2,7,8,2,3,1};
  rhs = std::vector<int>{2,3};
  EXPECT_EQ(findDuplicates(nums), rhs);

  // Example 2
  nums = std::vector<int>{1,1,2};
  rhs = std::vector<int>{1};
  EXPECT_EQ(findDuplicates(nums), rhs);

  // Example 3
  nums = std::vector<int>{1};
  rhs = std::vector<int>{};
  EXPECT_EQ(findDuplicates(nums), rhs);

  // WRITE EXTRA TESTS
  nums = std::vector<int>{};
  rhs = std::vector<int>{};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{5,5};
  rhs = std::vector<int>{5};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{1,2,3,4,5,6,7,8,9};
  rhs = std::vector<int>{};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{10,10,20,20,30};
  rhs = std::vector<int>{10,20};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{2,3,4,5,6,7,8,8,9,2};
  rhs = std::vector<int>{2,8};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{100,200,300,100,400,500,300};
  rhs = std::vector<int>{100,300};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{9,9};
  rhs = std::vector<int>{9};
  EXPECT_EQ(findDuplicates(nums), rhs);

  nums = std::vector<int>{1,2,1,2,3,3,4,4,5,5};
  rhs = std::vector<int>{1,2,3,4,5};
  EXPECT_EQ(findDuplicates(nums), rhs);
}


TEST(resultsArray, Question6) {
  std::vector<std::vector<int>> queries;
  int k;
  std::vector<int> rhs;

  // Example 1
  queries = std::vector<std::vector<int>>{std::vector<int>{1,2},std::vector<int>{3,4},std::vector<int>{2,3},std::vector<int>{-3,0}};
  k = 2;
  rhs = std::vector<int>{-1,7,5,3};
  EXPECT_EQ(resultsArray(queries, k), rhs);

  // Example 2
  queries = std::vector<std::vector<int>>{std::vector<int>{5,5},std::vector<int>{4,4},std::vector<int>{3,3}};
  k = 1;
  rhs = std::vector<int>{10,8,6};
  EXPECT_EQ(resultsArray(queries, k), rhs);

  // WRITE EXTRA TESTS
  queries = std::vector<std::vector<int>>{std::vector<int>{1,1},std::vector<int>{2,2}};
  k = 5;
  rhs = std::vector<int>{-1,-1};
  EXPECT_EQ(resultsArray(queries, k), rhs);

  queries = std::vector<std::vector<int>>{std::vector<int>{1,2},std::vector<int>{-2,-1},std::vector<int>{0,3}};
  k = 2;
  rhs = std::vector<int>{-1,3,3};
  EXPECT_EQ(resultsArray(queries, k), rhs);

  queries = std::vector<std::vector<int>>{std::vector<int>{-1,-2},std::vector<int>{-3,-4},std::vector<int>{-5,-6}};
  k = 3;
  rhs = std::vector<int>{-1,-1,11};
  EXPECT_EQ(resultsArray(queries, k), rhs);

  queries = std::vector<std::vector<int>>{std::vector<int>{0,1},std::vector<int>{0,2},std::vector<int>{0,3},std::vector<int>{0,4}};
  k = 2;
  rhs = std::vector<int>{-1,2,2,2};
  EXPECT_EQ(resultsArray(queries, k), rhs);
}


TEST(VectorPQueue, Question7) {
  VectorPQueue q1;
  VectorPQueue q2;

  // Insert "ping" and then "pong" in q1.
  q1.enqueue(std::string("ping"));
  q1.enqueue(std::string("pong"));
  EXPECT_EQ(q1.extractMin(), std::string("ping"));
  EXPECT_EQ(q1.extractMin(), std::string("pong"));
  // Now, q1 should be empty

  // Insert "pong" and then "ping" in q2.
  q2.enqueue(std::string("ping"));
  q2.enqueue(std::string("pong"));
  EXPECT_EQ(q2.extractMin(), std::string("ping"));
  EXPECT_EQ(q2.extractMin(), std::string("pong"));
  // Now, q2 should be empty.

  // Test for VectorPQueue::merge
  q1.enqueue(std::string("ping"));
  q2.enqueue(std::string("pong"));
  VectorPQueue* q3 = VectorPQueue::merge(&q1, &q2);
  EXPECT_EQ(q3->extractMin(), std::string("ping"));
  EXPECT_EQ(q3->extractMin(), std::string("pong"));
  delete q3;
  // Do not use q3 after here.

  // WRITE EXTRA TESTS
  VectorPQueue pq1;
  pq1.enqueue("zebra");
  pq1.enqueue("apple");
  pq1.enqueue("monkey");
  EXPECT_EQ(pq1.min(), "apple");

  VectorPQueue pq2;
  pq2.enqueue("delta");
  pq2.enqueue("bravo");
  pq2.enqueue("alpha");
  EXPECT_EQ(pq2.extractMin(), "alpha");
  EXPECT_EQ(pq2.extractMin(), "bravo");
  EXPECT_EQ(pq2.extractMin(), "delta");

  VectorPQueue pq3;
  pq3.enqueue("singleton");
  EXPECT_EQ(pq3.extractMin(), "singleton");

  VectorPQueue* pq4_1 = new VectorPQueue();
  VectorPQueue* pq4_2 = new VectorPQueue();
  pq4_1->enqueue("dog");
  pq4_1->enqueue("zebra");
  pq4_2->enqueue("ant");
  pq4_2->enqueue("cat");

  VectorPQueue* merged = VectorPQueue::merge(pq4_1, pq4_2);
  EXPECT_EQ(merged->extractMin(), "ant");
  EXPECT_EQ(merged->extractMin(), "cat");
  EXPECT_EQ(merged->extractMin(), "dog");
  EXPECT_EQ(merged->extractMin(), "zebra");

  delete merged;
}

TEST(HeapPQueue, Question7) {
  HeapPQueue q1;
  HeapPQueue q2;

  // Insert "ping" and then "pong" in q1
  q1.enqueue(std::string("ping"));
  q1.enqueue(std::string("pong"));
  EXPECT_EQ(q1.extractMin(), std::string("ping"));
  EXPECT_EQ(q1.extractMin(), std::string("pong"));
  // Now, q1 is empty

  // Insert "pong" and then "ping" in q2
  q2.enqueue(std::string("ping"));
  q2.enqueue(std::string("pong"));
  EXPECT_EQ(q2.extractMin(), std::string("ping"));
  EXPECT_EQ(q2.extractMin(), std::string("pong"));
  // Now, q2 is empty

  // Test for HeapPQueue::merge
  q1.enqueue(std::string("ping"));
  q2.enqueue(std::string("pong"));
  HeapPQueue* q3 = HeapPQueue::merge(&q1, &q2);
  EXPECT_EQ(q3->extractMin(), std::string("ping"));
  EXPECT_EQ(q3->extractMin(), std::string("pong"));
  delete q3;
  // Do not use q3 after here.

  // WRITE EXTRA TESTS
  HeapPQueue pq1;
  pq1.enqueue("ccc");
  pq1.enqueue("aaa");
  pq1.enqueue("zzz");
  EXPECT_EQ(pq1.min(), "aaa");

  HeapPQueue pq2;
  pq2.enqueue("mon");
  pq2.enqueue("sun");
  pq2.enqueue("fri");
  EXPECT_EQ(pq2.extractMin(), "fri");
  EXPECT_EQ(pq2.extractMin(), "mon");
  EXPECT_EQ(pq2.extractMin(), "sun");

  HeapPQueue pq3;
  pq3.enqueue("wow");
  EXPECT_EQ(pq3.extractMin(), "wow");

  HeapPQueue* pq4_1 = new HeapPQueue();
  HeapPQueue* pq4_2 = new HeapPQueue();
  pq4_1->enqueue("x");
  pq4_1->enqueue("m");
  pq4_2->enqueue("a");
  pq4_2->enqueue("q");

  HeapPQueue* merged = HeapPQueue::merge(pq4_1, pq4_2);
  EXPECT_EQ(merged->extractMin(), "a");
  EXPECT_EQ(merged->extractMin(), "m");
  EXPECT_EQ(merged->extractMin(), "q");
  EXPECT_EQ(merged->extractMin(), "x");

  delete merged;
  
}

// Main entry for GoogleTest
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
