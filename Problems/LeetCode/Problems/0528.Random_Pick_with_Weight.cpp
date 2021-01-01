class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        int sum = 0;
        int n = w.size();
        for( int i = 0 ; i < n ; i++ ) {
            sum += w[i];
            v.push_back(sum);
        }
    }
    int pickIndex() {
        int r = rand() % v.back();
        auto it = upper_bound(v.begin() , v.end() , r);
        return it-v.begin();
    }
};