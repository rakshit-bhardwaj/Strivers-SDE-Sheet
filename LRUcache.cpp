#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int,list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    int size,cur=0;

    LRUCache(int capacity)
    {
        size = capacity;
    }

    int get(int key)
    {
        if(m.find(key)==m.end()) return -1;
        int ans = m[key]->second;
        l.erase(m[key]);
        m.erase(key);
        l.push_back({key,ans});
        auto it = l.end();
        it--;
        m[key] = it;
        return ans;
    }

    void put(int key, int value)
    {
        if(m.find(key)!=m.end()){
            l.erase(m[key]);
            l.push_back({key,value});
            m.erase(key);
            auto it = l.end();
            it--;
            m[key] = it;
        } else {
            if(cur < size){
                l.push_back({key,value});
                auto it = l.end();
                it--;
                m[key] = it;
                cur++;
            } else {
                m.erase(l.front().first);
                l.pop_front();
                l.push_back({key,value});
                auto it = l.end();
                it--;
                m[key] = it;
            }
        }
    }
};
