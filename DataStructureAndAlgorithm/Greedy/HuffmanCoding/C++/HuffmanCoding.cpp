#include "HuffmanCoding.h"
#include <iostream>

void printCodes(MinHeapNode* root, std::string str) {
    if (!root) return;

    if (root->data != '$') {
        std::cout << root->data << ": " << str << std::endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(const std::string& data, const std::vector<int>& freq) {
    MinHeapNode *left, *right, *top;

    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;

    for (size_t i = 0; i < data.length(); ++i) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}
