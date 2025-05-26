class BinaryTree:
    """BinaryTree class using list to represent a binary tree structure."""

    def __init__(self, root_e):
        """
        Initialize the binary tree with a root element.

        Parameters:
        root_e (str): The root node's value.
        """
        self.nodes = [root_e]

    def insert(self, e, parent, pos):
        """
        Insert a new node e as a left or right child of the given parent node.

        Parameters:
        e (str): The value of the node to insert.
        parent (str): The parent node's value.
        pos (str): 'l' for left, 'r' for right.

        Returns:
        None
        """
        if e in self.nodes:  # Check for duplicate node
            print(f"Insertion refused: Node '{e}' already exists")
            return
        if parent not in self.nodes:  # Check parent existence
            print(f"Insertion refused: Node '{parent}' does not exist")
            return

        parent_idx = self.nodes.index(parent)

        if pos == 'l':
            idx = parent_idx * 2 + 1
            if len(self.nodes) - 1 >= idx and self.nodes[idx] != None:
                print(f"Insertion˽refused: Left child of node '{parent}' already occupied by '{self.nodes[idx]}'")
                return
        if pos == 'r':
            idx = parent_idx * 2 + 2
            if len(self.nodes) - 1 >= idx and self.nodes[idx] != None:
                print(f"Insertion˽refused: Right child of node '{parent}' already occupied by '{self.nodes[idx]}'")
                return

        # Extend list if necessary
        if len(self.nodes) <= idx:
            self.nodes += [None] * (idx - len(self.nodes) + 1)

        self.nodes[idx] = e

    def isLeaf(self, e):
        """
        Check whether the given node is a leaf node (no children).

        Parameters:
        e (str): The node value to check.

        Returns:
        bool or None: True if leaf, False if not, None if node does not exist.
        """
        if e not in self.nodes:
            print(f"Error: Node '{e}' does not exist")
            return None

        idx = self.nodes.index(e)

        child_1 = idx * 2 + 1
        child_2 = idx * 2 + 2

        # Check left and right child presence
        child_1_flag = False
        child_2_flag = False

        if len(self.nodes) - 1 < child_1:
            child_1_flag = False
        elif self.nodes[child_1] == None:
            child_1_flag = False
        else:
            child_1_flag = True

        if len(self.nodes) - 1 < child_2:
            child_2_flag = False
        elif self.nodes[child_2] == None:
            child_2_flag = False
        else:
            child_2_flag = True

        return not child_1_flag and not child_2_flag

    def delete(self, e):
        """
        Delete the given node if it is a leaf node.

        Parameters:
        e (str): The node value to delete.

        Returns:
        None
        """
        if e not in self.nodes:
            print(f"Deletion refused: Node '{e}' does not exist")
            return

        idx = self.nodes.index(e)

        child_1 = idx * 2 + 1
        child_2 = idx * 2 + 2

        # Determine if node has children
        child_1_flag = False
        child_2_flag = False

        if len(self.nodes) - 1 < child_1:
            child_1_flag = False
        elif self.nodes[child_1] == None:
            child_1_flag = False
        else:
            child_1_flag = True

        if len(self.nodes) - 1 < child_2:
            child_2_flag = False
        elif self.nodes[child_2] == None:
            child_2_flag = False
        else:
            child_2_flag = True
        isLeaf = not child_1_flag and not child_2_flag

        if not isLeaf:
            print(f"Deletion refused: Node '{e}' is not a leaf node")
            return

        # Delete the node
        idx = self.nodes.index(e)
        self.nodes[idx] = None

    def editNode(self, e_old, e_new):
        """
        Rename an existing node to a new value if the new name is not used.

        Parameters:
        e_old (str): The existing node name.
        e_new (str): The new name to assign.

        Returns:
        None
        """
        if e_old not in self.nodes:
            print(f"Edit refused: Node '{e_old}' does not exist")
            return
        if e_new in self.nodes:
            print(f"Edit refused: Node '{e_new}' already exists")
            return

        idx = self.nodes.index(e_old)
        self.nodes[idx] = e_new

    def numOfChild(self, e):
        """
        Return the number of children of the given node.

        Parameters:
        e (str): The node value.

        Returns:
        int or None: Number of children, or None if node not found.
        """
        if e not in self.nodes:
            print(f"Error: Node '{e}' does not exist")
            return None

        idx = self.nodes.index(e)
        left_child = idx * 2 + 1
        right_child = idx * 2 + 2
        num = 0

        if len(self.nodes) > left_child and self.nodes[left_child] != None:
            num += 1
        if len(self.nodes) > right_child and self.nodes[right_child] != None:
            num += 1
        return num

    def isFull(self):
        """
        Check whether the tree is a full binary tree (0 or 2 children per node).

        Returns:
        bool: True if full, False otherwise.
        """
        for i in range(len(self.nodes)):
            if self.nodes[i] is None:
                continue

            left = 2 * i + 1
            right = 2 * i + 2
            left_exists = 0
            right_exists = 0

            if left < len(self.nodes):
                if self.nodes[left] is not None:
                    left_exists = 1

            if right < len(self.nodes):
                if self.nodes[right] is not None:
                    right_exists = 1

            child_count = left_exists + right_exists

            if child_count == 1:
                return False

        return True

    def height(self):
        """
        Return the height of the tree based on the number of nodes.

        Returns:
        int: Height of the binary tree.
        """
        h = 1
        while True:
            if len(self.nodes) <= 2**h - 1:
                break
            h += 1
        return h

    def __str__(self):
        """
        Return a formatted string that visually represents the tree.

        Returns:
        str: Visual representation of the tree levels.
        """
        h = self.height()
        lt = self.nodes[:]

        # Remove trailing empty nodes
        while True:
            if lt[-1] is not None:
                break
            del lt[-1]

        # Replace None with dot character
        for i in range(len(lt)):
            if self.nodes[i] is None:
                lt[i] = '\u00B7'

        ret = lt[0]
        for d in range(1, h):
            ret += '\n' + ('\u00B7' * (2**(h - d) - 1)).join(lt[2**d - 1:2**(d + 1) - 1])
        return ret

    def __remove_trailing_none(self):
        """
        Remove None values at the end of the nodes list.

        This helps maintain a clean tree representation.
        """
        while True:
            if self.nodes[-1] is not None:
                break
            del self.nodes[-1]
