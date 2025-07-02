def fractional_knapsack(capacity, items):
    # items is a list of tuples: (value, weight)
    
    # Calculate value-to-weight ratio for each item
    for item in items:
        item = item + (item[0] / item[1],) # (value, weight, ratio)
    
    # Sort items by ratio in descending order
    items.sort(key=lambda x: x[2], reverse=True)

    total_value = 0.0

    for value, weight, ratio in items:
        if capacity == 0: break

        if weight <= capacity:
            # Take the whole item
            total_value += value
            capacity -= weight
        else:
            # Take a fraction of the item
            total_value += value * (capacity / weight)
            capacity = 0

    return total_value
