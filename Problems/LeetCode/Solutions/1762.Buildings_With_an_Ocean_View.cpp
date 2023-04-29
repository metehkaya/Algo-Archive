class Solution {
public:
    vector<int> findBuildings(vector<int>& v) {
        int n = v.size() , mx = 0;
        vector<int> ans;
        for( int i = n-1 ; i >= 0 ; i-- ) {
            if(mx < v[i])
                ans.push_back(i);
            mx = max(mx,v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
