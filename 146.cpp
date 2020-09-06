#include <iostream> 
#include <vector>
#include <stack>
#include <queue>
#include <map> 
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string> 
#include <cstdlib>
#include <algorithm>
#include <list> 
#include <deque>
#include <climits>

using namespace std; 


struct node{
    // 创建类必须有默认构造函数，不会自己写就让编译器默认生成一个
    node()=default;
    node(int v, list<int>::iterator p): value(v), pos(p) {}
    int value;
    list<int>::iterator pos; 
};

class LRUCache {
public:
    list<int> visit_order;
    unordered_map<int, node> cache;
    int cap = 0;
    int total = 0;
    
    LRUCache(int capacity) {
        cap = capacity;
        total = 0;
        visit_order.clear();
        cache.clear();
    }
    
    int get(int key) {
        if (cache.count(key)) {
            int result = cache[key].value;
            auto pos = cache[key].pos;
            visit_order.erase(pos);
            visit_order.push_front(key);
            pos = visit_order.begin();
            cache[key] = node(result, pos);
            return result;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            get(key);
            cache[key].value = value; 
            return;
        }
        if (total < cap) {
            visit_order.push_front(key);
            auto pos = visit_order.begin();
            cache[key] = node(value, pos);
            total++;
        } else {
            int r = visit_order.back();
            visit_order.pop_back();
            cache.erase(r);
            visit_order.push_front(key);
            auto pos = visit_order.begin();
            cache[key] = node(value, pos);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */