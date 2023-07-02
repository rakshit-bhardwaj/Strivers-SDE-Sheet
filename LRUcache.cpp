#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int,int>> l;
    int cur = 0,cap;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if(m.find(key)==m.end()) return -1;
        int value = m[key]->second;
        l.push_back({key,value});
        l.erase(m[key]);
        auto it = l.end();
        it--;
        m[key] = it;
        return value;
    }

    void put(int key, int value)
    {   
        
        if(m.find(key)==m.end()){
            if(cur == cap){
                auto fr = l.front();
                m.erase(fr.first);
                l.pop_front();
                cur--;
            }
            l.push_back({key,value});
            auto it = l.end();
            it--;
            m[key] = it;
            cur++;
        } else {
            l.erase(m[key]);
            l.push_back({key,value});
            auto it = l.end();
            it--;
            m[key] = it;
        }
    }
};
