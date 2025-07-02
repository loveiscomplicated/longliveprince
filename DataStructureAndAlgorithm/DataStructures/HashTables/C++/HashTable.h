#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <string>
#include <vector>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<std::pair<std::string, int>>> table;

    int hashFunction(const std::string& key);

public:
    HashTable();
    void insert(const std::string& key, int value);
    bool get(const std::string& key, int& value);
    void remove(const std::string& key);
};

#endif // HASHTABLE_H
