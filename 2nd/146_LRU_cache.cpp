#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
public:
    typedef pair<int, int> CacheNode;
    typedef list<CacheNode> LRUList;
    typedef unordered_map<int, LRUList::iterator> Cache;
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        int ret = -1;
        auto found = cache.find(key);
        if (found != cache.end()) {
            ret = found->second->second;
            lru.erase(found->second);
            found->second = lru.insert(lru.begin(), CacheNode(key, ret));
        }
        return ret;
    }
    
    void set(int key, int value) {
        auto found = cache.find(key);
        if (found != cache.end()) {
            lru.erase(found->second);
            found->second = lru.insert(lru.begin(), CacheNode(key, value));
        } else {
            if (cache.size() >= cap) {
                cache.erase(lru.back().first);
                lru.pop_back();
            }
            cache[key] = lru.insert(lru.begin(), CacheNode(key, value));
        }
    }
private:
    Cache cache;
    LRUList lru;
    int cap;
};

int main(void)
{
    LRUCache lruc = LRUCache(3);
    lruc.set(1, 1);
    lruc.set(2, 2);
    lruc.set(3, 3);
    cout << lruc.get(1) << endl;
    lruc.set(4, 4);
    cout << lruc.get(2) << endl;
    cout << lruc.get(3) << endl;
    return 0;
}
