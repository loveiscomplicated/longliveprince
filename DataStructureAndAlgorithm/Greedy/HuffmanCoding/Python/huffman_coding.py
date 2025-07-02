import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Define comparison for priority queue
    def __lt__(self, other):
        return self.freq < other.freq

def huffman_coding(data):
    # data is a dictionary of character frequencies: {'a': 5, 'b': 9, ...}

    priority_queue = []
    for char, freq in data.items():
        heapq.heappush(priority_queue, Node(char, freq))

    while len(priority_queue) > 1:
        left = heapq.heappop(priority_queue)
        right = heapq.heappop(priority_queue)

        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right

        heapq.heappush(priority_queue, merged)

    # The single node left in the priority queue is the root of the Huffman tree
    root = heapq.heappop(priority_queue)

    codes = {}
    def build_codes(node, current_code):
        if node is None: return

        if node.char is not None:
            codes[node.char] = current_code
            return

        build_codes(node.left, current_code + "0")
        build_codes(node.right, current_code + "1")

    build_codes(root, "")
    return codes
