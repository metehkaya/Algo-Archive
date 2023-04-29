class NumberContainers {
public:
    map<int,set<int>> val_2_idx;
    map<int,int> idx_2_val;
    NumberContainers() {
    }
    void change(int index, int number) {
        int old = idx_2_val[index];
        if(old > 0) {
            val_2_idx[old].erase(index);
        }
        idx_2_val[index] = number;
        val_2_idx[number].insert(index);
    }
    
    int find(int number) {
        map<int,set<int>>::iterator it = val_2_idx.find(number);
        if(it == val_2_idx.end())
            return -1;
        if(it->se.empty())
            return -1;
        set<int>::iterator sit = it->second.begin();
        return (*sit);
    }
};
