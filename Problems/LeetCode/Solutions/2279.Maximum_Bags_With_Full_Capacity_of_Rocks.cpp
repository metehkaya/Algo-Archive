class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int rem) {
        int n = capacity.size() , ans = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(capacity[i] == rocks[i])
                ans++;
            else
                v.push_back(capacity[i]-rocks[i]);
        sort(v.begin(),v.end());
        int m = v.size();
        for( int i = 0 ; i < m && rem >= v[i] ; i++ ) {
            ans++;
            rem -= v[i];
        }
        return ans;
    }
};
