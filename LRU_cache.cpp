#include <iostream>
#include <list>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LRUCache{

public:

    typedef pair<int, int> CacheNode;
    typedef list<CacheNode> CacheNodeList;
    typedef CacheNodeList::iterator CacheNodeListIter;
    typedef unordered_map<int, CacheNodeListIter> UMap;
    typedef CacheNodeList::size_type s_t;
    typedef UMap::iterator UMapIter;
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        UMapIter found = m.find(key);
        if (found != m.end()) {
            int ret = found->second->second;
            lru.erase(found->second);
            CacheNode tmp(key, ret);
            lru.push_front(tmp);
            m[key] = lru.begin();
            return ret;
        } else
            return -1;
    }
    void set(int key, int value) {
        UMapIter found = m.find(key);
        if (found != m.end()) {
            lru.erase(found->second);
            CacheNode tmp(key, value);
            lru.push_front(tmp);
            m[key] = lru.begin();
        } else {
            if (m.size() == cap) {
                m.erase(lru.back().first);
                lru.pop_back();
                CacheNode tmp(key, value);
                lru.push_front(tmp);
                m[key] = lru.begin();
            } else {
                CacheNode tmp(key, value);
                lru.push_front(tmp);
                m[key] = lru.begin();
            }
        }
    }
private:
    s_t cap;
    CacheNodeList lru;
    UMap m;
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
