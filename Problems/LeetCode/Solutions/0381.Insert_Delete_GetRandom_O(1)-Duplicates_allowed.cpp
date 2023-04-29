class RandomizedCollection {
public:
    int n = 0;
    vector<int> ar;
    unordered_map<int,unordered_set<int>> index;
    RandomizedCollection() {}
    bool insert(int val) {
        bool exists = index.find(val) != index.end();
        ar.push_back(val);
        index[val].insert(n++);
        return !exists;
    }
    bool remove(int val) {
        auto it = index.find(val);
        bool exists = it != index.end();
        if(exists) {
            int i = *(it->second.begin());
            int last = n-1;
            if(i != last && ar[i] != ar[last]) {
                int lastVal = ar[n-1];
                swap(ar[i],ar[last]);
                index[lastVal].erase(last);
                index[lastVal].insert(i);
            }
            if(i != last && ar[i] == ar[last])
                i = last;
            n--;
            ar.pop_back();
            index[val].erase(i);
            if(index[val].empty())
                index.erase(val);
        }
        return exists;
    }
    int getRandom() {
        int r = rand() % n;
        return ar[r];
    }
};