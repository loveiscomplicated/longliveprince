#ifndef FRACTIONALKNAPSACK_H
#define FRACTIONALKNAPSACK_H

#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
    double ratio;

    Item(int v, int w) : value(v), weight(w), ratio(static_cast<double>(v) / w) {}
};

double fractionalKnapsack(int W, std::vector<Item>& items);

#endif // FRACTIONALKNAPSACK_H
