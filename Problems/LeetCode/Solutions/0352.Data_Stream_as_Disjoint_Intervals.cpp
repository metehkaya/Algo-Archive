class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {}
    void addNum(int val) {
        s.insert(val);
    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int l = -1 , r = -1;
        for(int x : s) {
            if(l == -1)
                l = r = x;
            else {
                if(x == r+1)
                    r = x;
                else {
                    ans.push_back({l,r});
                    l = r = x;
                }
            }
        }
        if(l != -1)
            ans.push_back({l,r});
        return ans;
    }
};
