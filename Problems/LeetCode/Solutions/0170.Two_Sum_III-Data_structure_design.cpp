class TwoSum {
public:
    map<int,int> cnt;
    TwoSum() {}
    void add(int num) {
        cnt[num]++;
    }
    bool find(int t) {
        map<int,int>::iterator it;
        for( it = cnt.begin() ; it != cnt.end() && 2*(it->first) <= t ; it++ ) {
            int val = it->first;
            int times = it->second;
            if(2*val == t && times > 1)
                return true;
            else if(2*val < t && cnt.find(t-val) != cnt.end())
                return true;
        }
        return false;
    }
};