class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if not self.root:
            self.root = Node(data)
        else:
            self._insert(self.root, data)

    def _insert(self, node, data):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(node.left, data)
        elif data > node.data:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(node.right, data)

    def remove(self, data):
        self.root = self._remove(self.root, data)

    def _remove(self, node, data):
        if node is None: return node

        if data < node.data:
            node.left = self._remove(node.left, data)
        elif data > node.data:
            node.right = self._remove(node.right, data)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            
            min_larger_node = self._find_min(node.right)
            node.data = min_larger_node.data
            node.right = self._remove(node.right, min_larger_node.data)
        return node

    def _find_min(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def search(self, data):
        return self._search(self.root, data)

    def _search(self, node, data):
        if node is None or node.data == data:
            return node is not None
        if data < node.data:
            return self._search(node.left, data)
        return self._search(node.right, data)

    def print_inorder(self):
        self._inorder_traversal(self.root)
        print()

    def _inorder_traversal(self, node):
        if node:
            self._inorder_traversal(node.left)
            print(node.data, end=" ")
            self._inorder_traversal(node.right)
