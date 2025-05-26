class BinaryTree:
    def __init__(self, root_e):
        self.nodes = [root_e]

    def insert(self, e, parent, pos):
        if e in self.nodes: # Name already used!
            print(f"Insertion refused: Node '{e}' already exists")
            return
        if parent not in self.nodes:
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
        
        if len(self.nodes) <= idx:
            self.nodes += [None] * (idx - len(self.nodes) + 1)

        self.nodes[idx] = e
            
    def isLeaf(self, e):
        if e not in self.nodes:
            print(f"Error: Node '{e}' does not exist")
            return None
        
        idx = self.nodes.index(e)
        
        child_1 = idx * 2 + 1
        child_2 = idx * 2 + 2
        
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
        if e not in self.nodes:
            print(f"Deletion refused: Node '{e}' does not exist")
            return
        
        idx = self.nodes.index(e)
        
        child_1 = idx * 2 + 1
        child_2 = idx * 2 + 2
        
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
        
        idx = self.nodes.index(e)
        self.nodes[idx] = None
        

    def editNode(self, e_old, e_new):
        if e_old not in self.nodes:
            print(f"Edit refused: Node '{e_old}' does not exist")
            return
        if e_new in self.nodes:
            print(f"Edit refused: Node '{e_new}' already exists")
            return
            
        idx = self.nodes.index(e_old)
        self.nodes[idx] = e_new

    def numOfChild(self, e):
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
        """Height of the tree"""
        h = 1
        while True:
            if len(self.nodes) <= 2**h - 1:
                break
            h += 1
        return h


    def __str__(self):
        """String representation"""
        h = self.height()
        lt = self.nodes[:]

        # Remove trailing empty nodes
        while True:
            if lt[-1] is not None:
                break
            del lt[-1]
        
        # Replace empty node representation
        for i in range(len(lt)):
            if self.nodes[i] is None:
                lt[i] = '\u00B7'

        ret = lt[0]
        for d in range(1, h):
            ret += '\n' + ('\u00B7'*(2**(h-d)-1)).join(lt[2**d-1:2**(d+1)-1])
        return ret


    def __remove_trailing_none(self):
        """Remove all trailing None elements from list"""
        while True:
            if self.nodes[-1] is not None:
                break
            del self.nodes[-1]

