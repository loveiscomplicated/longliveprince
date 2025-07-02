#include "FractionalKnapsack.h"

double fractionalKnapsack(int W, std::vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double totalValue = 0.0;

    for (const auto& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            // Take the whole item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take a fraction of the item
            totalValue += item.value * (static_cast<double>(W) / item.weight);
            W = 0;
        }
    }
    return totalValue;
}
