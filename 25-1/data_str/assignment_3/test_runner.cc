// test_runner.cc
#include "library_code.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <random>

// Helper function to generate unique random integers within a range
std::vector<int> generateUniqueRandomKeys(int count, int min_val, int max_val) {
  std::set<int> unique_keys{};
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> distrib{min_val, max_val};

  // Ensure count does not exceed the possible range of unique values
  long long range_size{static_cast<long long>(max_val - min_val + 1)};
  if (count > range_size) {
    count = range_size;
  }
  if (count < 0)
    count = 0;

  while (unique_keys.size() < static_cast<size_t>(count)) {
    unique_keys.insert(distrib(gen));
  }

  std::vector<int> keys{unique_keys.begin(), unique_keys.end()};
  // Shuffle the unique keys to make the insertion order random for BST/AVL
  std::shuffle(keys.begin(), keys.end(), gen);

  return keys;
}

// Helper function to generate preorder and inorder traversals for a random BST
// Note: Random tree generation relies on a correctly implemented insertAVL.
bool generateRandomBSTTraversals(int node_count, int min_val, int max_val,
                                 std::vector<int> &preorder,
                                 std::vector<int> &inorder) {
  preorder.clear();
  inorder.clear();

  if (node_count <= 0)
    return false;

  std::vector<int> keys{generateUniqueRandomKeys(node_count, min_val, max_val)};
  if (keys.empty())
    return false; // Could not generate keys

  // Build a temporary BST
  Node *temp_root{nullptr};
  for (int key : keys) {
    temp_root = insertAVL(temp_root, key);
    if (!temp_root) {
      deleteTree(temp_root);
      return false;
    }
  }

  getPreorder(temp_root, preorder);
  getInorder(temp_root, inorder);

  deleteTree(temp_root);

  return !preorder.empty() && !inorder.empty();
}

// ---------------------------------------------
//                  Problem 3
// ---------------------------------------------

TEST(splitBST, Example1) {
  int target{2};
  std::vector<int> preorder{4, 2, 1, 3, 6, 5, 7};
  std::vector<int> inorder{1, 2, 3, 4, 5, 6, 7};

  std::vector<int> expected_preorder1{2, 1};
  std::vector<int> expected_inorder1{1, 2};
  std::vector<int> expected_preorder2{4, 3, 6, 5, 7};
  std::vector<int> expected_inorder2{3, 4, 5, 6, 7};

  SplitResult result{solveSplitBST(target, preorder, inorder)};
  EXPECT_EQ(result.preorder1, expected_preorder1);
  EXPECT_EQ(result.inorder1, expected_inorder1);
  EXPECT_EQ(result.preorder2, expected_preorder2);
  EXPECT_EQ(result.inorder2, expected_inorder2);
}

TEST(splitBST, Example2) {
  int target{4};
  std::vector<int> preorder{2, -3};
  std::vector<int> inorder{-3, 2};

  std::vector<int> expected_preorder1{2, -3};
  std::vector<int> expected_inorder1{-3, 2};
  std::vector<int> expected_preorder2{};
  std::vector<int> expected_inorder2{};

  SplitResult result{solveSplitBST(target, preorder, inorder)};
  EXPECT_EQ(result.preorder1, expected_preorder1);
  EXPECT_EQ(result.inorder1, expected_inorder1);
  EXPECT_EQ(result.preorder2, expected_preorder2);
  EXPECT_EQ(result.inorder2, expected_inorder2);
}

TEST(splitBST, RandomLarge) {
  const int NODE_COUNT{10000}; // Constraint: [1, 10000]
  const int MIN_VAL{-100000};  // Constraint: [-10^5, 10^5]
  const int MAX_VAL{100000};

  const int NUM_TESTS{100};

  for (int i{0}; i < NUM_TESTS; ++i) {
    std::vector<int> preorder{}, inorder{};
    ASSERT_TRUE(generateRandomBSTTraversals(NODE_COUNT, MIN_VAL, MAX_VAL,
                                            preorder, inorder));
    ASSERT_EQ(preorder.size(), NODE_COUNT);
    ASSERT_EQ(inorder.size(), NODE_COUNT);

    // Generate a random target value
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distrib{MIN_VAL, MAX_VAL};
    int target{distrib(gen)};

    ASSERT_NO_THROW({
      SplitResult result{solveSplitBST(target, preorder, inorder)};

      // Optional basic checks:
      EXPECT_EQ(result.preorder1.size(), result.inorder1.size());
      EXPECT_EQ(result.preorder2.size(), result.inorder2.size());
      EXPECT_EQ(result.inorder1.size() + result.inorder2.size(), NODE_COUNT);
    });
  }
}

// Add your own test cases here (Create a new test case under the test suite named splitBST)

// ---------------------------------------------
//                  Problem 4
// ---------------------------------------------

TEST(convertBSTToCDLL, Example1) {
  std::vector<int> preorder{4, 2, 1, 3, 5};
  std::vector<int> inorder{1, 2, 3, 4, 5};

  std::vector<int> expected_successor_traversal{1, 2, 3, 4, 5};
  std::vector<int> expected_predecessor_traversal{1, 5, 4, 3, 2};

  CDLLResult result{solveBSTToCDLL(preorder, inorder)};

  EXPECT_EQ(result.successor_traversal, expected_successor_traversal);
  EXPECT_EQ(result.predecessor_traversal, expected_predecessor_traversal);
}

TEST(convertBSTToCDLL, Example2) {
  std::vector<int> preorder{2, 1, 4, 3};
  std::vector<int> inorder{1, 2, 3, 4};

  std::vector<int> expected_successor_traversal{1, 2, 3, 4};
  std::vector<int> expected_predecessor_traversal{1, 4, 3, 2};

  CDLLResult result{solveBSTToCDLL(preorder, inorder)};

  EXPECT_EQ(result.successor_traversal, expected_successor_traversal);
  EXPECT_EQ(result.predecessor_traversal, expected_predecessor_traversal);
}

TEST(convertBSTToCDLL, RandomLarge) {
  const int NODE_COUNT{10000}; // Constraint: [1, 10000]
  const int MIN_VAL{-100000};  // Constraint: [-10^5, 10^5]
  const int MAX_VAL{100000};

  const int NUM_TESTS{100};

  for (int i{0}; i < NUM_TESTS; ++i) {
    std::vector<int> preorder{}, inorder{};
    ASSERT_TRUE(generateRandomBSTTraversals(NODE_COUNT, MIN_VAL, MAX_VAL,
                                            preorder, inorder));
    ASSERT_EQ(preorder.size(), NODE_COUNT);
    ASSERT_EQ(inorder.size(), NODE_COUNT);

    ASSERT_NO_THROW({
      CDLLResult result{solveBSTToCDLL(preorder, inorder)};

      // Optional basic checks:
      EXPECT_EQ(result.successor_traversal.size(), NODE_COUNT);
      EXPECT_EQ(result.predecessor_traversal.size(), NODE_COUNT);

      // Main checks:
      std::vector<int> sorted_inorder{inorder};
      EXPECT_EQ(result.successor_traversal, sorted_inorder);
      std::reverse(sorted_inorder.begin() + 1, sorted_inorder.end());
      EXPECT_EQ(result.predecessor_traversal, sorted_inorder);
    });
  }
}

// Add your own test cases here (Create a new test case under the test suite named convertBSTToCDLL)

// ---------------------------------------------
//                  Problem 5
// ---------------------------------------------

TEST(insertAVL, Example1) {
  std::vector<int> keys{10, 20, 30};
  std::vector<int> expected_preorder{20, 10, 30};
  std::vector<int> expected_inorder{10, 20, 30};

  AVLResult result{solveInsertAVL(keys)};

  EXPECT_EQ(result.preorder, expected_preorder);
  EXPECT_EQ(result.inorder, expected_inorder);
}

TEST(insertAVL, Example2) {
  std::vector<int> keys{9, 5, 10, 0, 6, 11, -1, 1, 2};
  std::vector<int> expected_preorder{9, 1, 0, -1, 5, 2, 6, 10, 11};
  std::vector<int> expected_inorder{-1, 0, 1, 2, 5, 6, 9, 10, 11};

  AVLResult result{solveInsertAVL(keys)};

  EXPECT_EQ(result.preorder, expected_preorder);
  EXPECT_EQ(result.inorder, expected_inorder);
}

TEST(insertAVL, RandomLarge) {
  const int KEY_COUNT{10000}; // Constraint: [1, 10000]
  const int MIN_VAL{-100000}; // Constraint: [-10^5, 10^5]
  const int MAX_VAL{100000};

  const int NUM_TESTS{100};

  for (int i{0}; i < NUM_TESTS; ++i) {
    std::vector<int> keys{
        generateUniqueRandomKeys(KEY_COUNT, MIN_VAL, MAX_VAL)};
    ASSERT_EQ(keys.size(), KEY_COUNT);

    ASSERT_NO_THROW({
      AVLResult result{solveInsertAVL(keys)};

      // Optional basic checks:
      EXPECT_EQ(result.preorder.size(), KEY_COUNT);
      EXPECT_EQ(result.inorder.size(), KEY_COUNT);

      // Main checks:
      std::vector<int> sorted_keys{keys};
      std::sort(sorted_keys.begin(), sorted_keys.end());
      EXPECT_EQ(result.inorder, sorted_keys);
    });
  }
}

// Add your own test cases here (Create a new test case under the test suite named insertAVL)
