class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for( int i = 0 ; i < n ; i += 3 )
            if(v[i+2] - v[i] > k)
                return ans;
        for( int i = 0 ; i < n ; i += 3 )
            ans.push_back({v[i],v[i+1],v[i+2]});
        return ans;
    }
};