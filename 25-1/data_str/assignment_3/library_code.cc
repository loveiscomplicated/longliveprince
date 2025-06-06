// library_code.cc
#include "library_code.h"

#include <unordered_map>

// --------------------------------------------
//                  Problem 3
// --------------------------------------------

void deleteTree(Node *node) {
  if (node == nullptr)
    return;
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}

/**
 * @brief Recursive helper function for reconstructBST.
 * Recursively constructs the tree using preorder and inorder traversal
 * information.
 * @param preorder Preorder traversal vector (const reference).
 * @param preorder_index Current index being processed in the preorder traversal
 * (reference). Will be modified during function call.
 * @param inorder Inorder traversal vector (const reference).
 * @param inorder_start Start index of the current subtree's inorder traversal.
 * @param inorder_end End index of the current subtree's inorder traversal.
 * @param inorder_map Hash map mapping inorder values to indices (reference).
 * @return Pointer to the root node of the constructed subtree. Returns nullptr
 * if the subtree is empty.
 */
Node *reconstructBSTHelper(const std::vector<int> &preorder,
                           int &preorder_index, const std::vector<int> &inorder,
                           int inorder_start, int inorder_end,
                           const std::unordered_map<int, int> &inorder_map) {
  if (preorder_index >= preorder.size() || inorder_start > inorder_end) {
    return nullptr;
  }

  int root_value{preorder.at(preorder_index++)};
  Node *root{new Node(root_value)};

  int inorder_index{inorder_map.at(root_value)};

  root->left =
      reconstructBSTHelper(preorder, preorder_index, inorder, inorder_start,
                           inorder_index - 1, inorder_map);
  root->right =
      reconstructBSTHelper(preorder, preorder_index, inorder, inorder_index + 1,
                           inorder_end, inorder_map);

  return root;
}

Node *reconstructBST(const std::vector<int> &preorder,
                     const std::vector<int> &inorder) {
  if (preorder.empty() || inorder.empty() ||
      preorder.size() != inorder.size()) {
    return nullptr;
  }
  std::unordered_map<int, int> inorder_map{};
  for (int i{}; i < inorder.size(); ++i) {
    inorder_map.emplace(inorder.at(i), i);
  }

  int preorder_index{0};

  return reconstructBSTHelper(preorder, preorder_index, inorder, 0,
                              inorder.size() - 1, inorder_map);
}

void getPreorder(const Node *node, std::vector<int> &result) {
  if (node == nullptr)
    return;
  result.push_back(node->value);
  getPreorder(node->left, result);
  getPreorder(node->right, result);
}

void getInorder(const Node *node, std::vector<int> &result) {
  if (node == nullptr)
    return;
  getInorder(node->left, result);
  result.push_back(node->value);
  getInorder(node->right, result);
}

// Question 3: Split BST function
// This function splits the given BST into two BSTs based on the target value.
// Nodes less than or equal to the target belong to the first tree, larger nodes
// to the second tree. The return value is a pair of root node
// pointers for the two subtrees.
std::pair<Node *, Node *> splitBST(Node *root, int target) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  if (!root) return {nullptr, nullptr};

  if (root->value <= target) {
    auto [l, r] = splitBST(root->right, target);
    root->right = l;
    return {root, r};
  } else {
    auto [l, r] = splitBST(root->left, target);
    root->left = r;
    return {l, root};
  }
}

SplitResult solveSplitBST(int target, const std::vector<int> &preorder,
                          const std::vector<int> &inorder) {
  Node *root{reconstructBST(preorder, inorder)};
  auto [left, right]{splitBST(root, target)};

  SplitResult result;
  getPreorder(left, result.preorder1);
  getInorder(left, result.inorder1);
  getPreorder(right, result.preorder2);
  getInorder(right, result.inorder2);

  deleteTree(left);
  deleteTree(right);

  return result;
}

// --------------------------------------------
//                  Problem 4
// --------------------------------------------

std::vector<int> getCDLLSuccessorTraversal(const Node *head) {
  std::vector<int> result;

  if (head == nullptr)
    return result;

  const Node *current{head};
  do {
    result.push_back(current->value);
    current = current->right;
  } while (current != head);

  return result;
}

std::vector<int> getCDLLPredecessorTraversal(const Node *head) {
  std::vector<int> result;

  if (head == nullptr)
    return result;

  const Node *current{head};
  do {
    result.push_back(current->value);
    current = current->left;
  } while (current != head);

  return result;
}

/**
 * @brief Recursive helper function for convertBSTToCDLL.
 * Constructs the CDLL by traversing the BST in inorder and modifying the
 * left/right pointers of the nodes.
 * @param root Pointer to the current node being processed.
 * @param head Pointer to the head node of the CDLL (reference). Will be
 * updated to point to the smallest node.
 * @param prev Pointer to the previously visited node during inorder traversal
 * (reference). Used for linking nodes.
 */
void convertBSTToCDLLHelper(Node *root, Node *&head, Node *&prev) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  if (root == nullptr) return;
                                                                                                                                                                                                                                                                                                            
  convertBSTToCDLLHelper(root->left, head, prev);
  if (prev == nullptr) {
    head = root;
  } else {
    prev->right = root;
    root->left = prev;
  }
  prev = root;
  convertBSTToCDLLHelper(root->right, head, prev);
}

// Question 4: Convert BST to CDLL
// This function converts the given BST into a circular doubly linked list and
// returns the head node.
Node *convertBSTToCDLL(Node *root) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  if (root == nullptr) return nullptr;
  Node* prev = nullptr;
  Node* head = nullptr;
  convertBSTToCDLLHelper(root, head, prev);
  
  head->left = prev;
  prev->right = head;
  
  return head;
}

CDLLResult solveBSTToCDLL(const std::vector<int> &preorder,
                          const std::vector<int> &inorder) {
  Node *root{reconstructBST(preorder, inorder)};
  Node *head{convertBSTToCDLL(root)};

  CDLLResult result;
  result.successor_traversal = getCDLLSuccessorTraversal(head);
  result.predecessor_traversal = getCDLLPredecessorTraversal(head);

  if (head != nullptr) {
    Node *current{head->right};
    while (current != head) {
      Node *next{current->right};
      delete current;
      current = next;
    }
    delete head;
  }

  return result;
}

// --------------------------------------------
//                  Problem 5
// --------------------------------------------

// inheriting struct node -> to include pointer of parent node
struct AVLNode : public Node {
  Node *parent{};
  explicit AVLNode(int x) : Node(x), parent(nullptr) {};
};

int max(int a, int b) {
  if (a >= b) {
    return a;
  } 
  return b;
}

int height(const Node *node) {
  if (node == nullptr)
    return 0;

  return node->height;
}

void updateHeight(Node *node) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  
  node->height = 1 + max(height(node->left), height(node->right));
}

int getBalance(const Node *node) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  int leftHeight = height(node->left);
  int rightHeight = height(node->right);

  return rightHeight - leftHeight;
}

Node *rotateRight(Node *y) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  Node *x = y->left;
  Node *temp = x->right;
  x->right = y;
  y->left = temp;

  updateHeight(y); // update lower one first
  updateHeight(x);
  
  return x;
}

Node *rotateLeft(Node *x) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************

  Node *y = x->right;
  Node *temp = y->left;
  y->left = x;
  x->right = temp;

  updateHeight(x);
  updateHeight(y);
  return y; // <<-- EDIT THIS LINE TOO!
}

Node *insertAVL(Node *node, int key) {
  // *****************
  // IMPLEMENT IT HERE
  // *****************
  if (node == nullptr) {
    return new Node(key);
  }
  // insert new node to the right position
  if (key < node->value) {
    node->left = insertAVL(node->left, key);
  } else {
    node->right = insertAVL(node->right, key);
  }

  // in the instance if recursion
  updateHeight(node);
  
  // rotate if necessary
  if (getBalance(node) < -1 && key < node->left->value) {
    // rotate right
    return rotateRight(node);
  
  } else if (getBalance(node) < -1 && key > node->left->value) {
    // left right
    node->left = rotateLeft(node->left);
    return rotateRight(node);
    
  } else if (getBalance(node) > 1 && key > node->right->value) {
    // left
    return rotateLeft(node);

  } else if (getBalance(node) > 1 && key > node->right->value) {
    // right left
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }
  return node;
}

AVLResult solveInsertAVL(const std::vector<int> &keys) {
  Node *root{nullptr};
  for (int key : keys) {
    root = insertAVL(root, key);
  }

  AVLResult result;
  getPreorder(root, result.preorder);
  getInorder(root, result.inorder);

  deleteTree(root);

  return result;
}