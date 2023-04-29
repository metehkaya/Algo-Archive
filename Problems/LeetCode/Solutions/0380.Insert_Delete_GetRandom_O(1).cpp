class RandomizedSet {
public:
    int n = 0;
    vector<int> ar;
    unordered_map<int,int> index;
    RandomizedSet() {}
    bool insert(int val) {
        bool exists = index.find(val) != index.end();
        if(!exists) {
            index[val] = n++;
            ar.push_back(val);
        }
        return !exists;
    }
    bool remove(int val) {
        auto it = index.find(val);
        bool exists = it != index.end();
        if(exists) {
            int i = it->second;
            int last = n-1;
            if(i != last) {
                int lastVal = ar[n-1];
                swap(ar[i],ar[last]);
                index[lastVal] = i;
            }
            n--;
            index.erase(val);
            ar.pop_back();
        }
        return exists;
    }
    int getRandom() {
        int r = rand() % n;
        return ar[r];
    }
};