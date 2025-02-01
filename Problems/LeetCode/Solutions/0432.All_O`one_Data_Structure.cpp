class AllOne {
public:
    unordered_map<string,int> count;
    set<pair<int,string>> se;

    AllOne() {
        count.clear();
    }

    void inc(string key) {
        int n = count[key];
        count[key]++;
        se.erase({n, key});
        se.insert({n+1, key});
    }

    void dec(string key) {
        int n = count[key];
        count[key]--;
        se.erase({n, key});
        if(count[key] > 0)
            se.insert({n-1, key});
        else
            count.erase(key);
    }

    string getMaxKey() {
        if (!se.empty())
            return se.rbegin()->second;
        return "";
    }

    string getMinKey() {
        if (!se.empty())
            return se.begin()->second;
        return "";
    }
};