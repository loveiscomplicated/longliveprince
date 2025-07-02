#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include <string>
#include <map>
#include <queue>
#include <vector>

struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode* root, std::string str);
void HuffmanCodes(const std::string& data, const std::vector<int>& freq);

#endif // HUFFMANCODING_H
