#include "HashTable.h"

HashTable::HashTable() : table(TABLE_SIZE) {}

int HashTable::hashFunction(const std::string& key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash + ch) % TABLE_SIZE;
    }
    return hash;
}

void HashTable::insert(const std::string& key, int value) {
    int index = hashFunction(key);
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value; // Update existing key
            return;
        }
    }
    table[index].emplace_back(key, value);
}

bool HashTable::get(const std::string& key, int& value) {
    int index = hashFunction(key);
    for (const auto& pair : table[index]) {
        if (pair.first == key) {
            value = pair.second;
            return true;
        }
    }
    return false;
}

void HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    table[index].remove_if([&](const std::pair<std::string, int>& pair) {
        return pair.first == key;
    });
}
