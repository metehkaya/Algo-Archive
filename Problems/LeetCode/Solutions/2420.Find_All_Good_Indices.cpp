class Solution {
public:
    vector<int> goodIndices(vector<int>& v, int k) {
        int n = v.size();
        vector<int> l(n,1);
        for( int i = 1 ; i < n ; i++ )
            if(v[i] <= v[i-1])
                l[i] = l[i-1]+1;
        vector<int> r(n,1);
        for( int i = n-2 ; i >= 0 ; i-- )
            if(v[i] <= v[i+1])
                r[i] = r[i+1]+1;
        vector<int> ans;
        for( int i = k ; i < n-k ; i++ )
            if(l[i-1] >= k && r[i+1] >= k)
                ans.push_back(i);
        return ans;
    }
};
