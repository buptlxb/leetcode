#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

class RandomizedSet {
    vector<int> container;
    unordered_map<int, vector<int>::size_type> dict;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srandom(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dict.find(val) != dict.end())
            return false;
        dict[val] = container.size();
        container.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dict.find(val) == dict.end())
            return false;
        auto idx = dict[val];
        swap(container[idx], container.back());
        dict[container[idx]] = idx;
        container.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return container[random()%container.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(void)
{
    return 0;
}
