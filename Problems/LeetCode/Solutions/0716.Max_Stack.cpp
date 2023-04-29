class MaxStack {
public:
    list<int> l;
    map<int,vector<list<int>::iterator>> mp;
    MaxStack() {}
    void push(int x) {
        l.push_back(x);
        mp[x].push_back(--l.end());
    }
    int pop() {
        int x = l.back();
        l.pop_back();
        mp[x].pop_back();
        if(mp[x].empty())
            mp.erase(x);
        return x;
    }
    int top() {
        return l.back();
    }
    int peekMax() {
        return mp.rbegin()->first;
    }
    int popMax() {
        int x = mp.rbegin()->first;
        l.erase(mp[x].back());
        mp[x].pop_back();
        if(mp[x].empty())
            mp.erase(x);
        return x;
    }
};
