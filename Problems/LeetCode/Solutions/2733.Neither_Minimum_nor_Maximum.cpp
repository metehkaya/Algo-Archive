class Solution {
public:
    int findNonMinOrMax(vector<int>& v) {
        int n = v.size();
        if(n <= 2)
            return -1;
        sort(v.begin(),v.end());
        return v[1];
    }
};
