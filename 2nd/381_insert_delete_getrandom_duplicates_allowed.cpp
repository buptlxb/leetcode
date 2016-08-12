#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>

using namespace std;

class RandomizedCollection {
    vector<int> container;
    unordered_map<int, unordered_set<vector<int>::size_type>> dict;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srandom(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = dict.find(val) == dict.end();
        dict[val].insert(container.size());
        container.push_back(val);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (dict.find(val) == dict.end())
            return false;
        auto idx = *dict[val].begin();
        dict[val].erase(idx);
        if (dict[val].empty())
            dict.erase(val);
        swap(container[idx], container.back());
        container.pop_back();
        if (dict.find(container[idx]) != dict.end()) {
            dict[container[idx]].erase(container.size());
            dict[container[idx]].insert(idx);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return container[random() % container.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(void)
{
    RandomizedCollection obj;
    bool param_1 = obj.insert(0);
    bool param_2 = obj.remove(0);
    bool param_3 = obj.insert(-1);
    bool param_4 = obj.remove(0);
    int param_5 = obj.getRandom();
    int param_6 = obj.getRandom();
    return 0;
}
