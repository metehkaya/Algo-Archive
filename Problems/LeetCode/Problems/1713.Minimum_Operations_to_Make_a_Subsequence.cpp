class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& ar) {
        int n = target.size();
        map<int,int> mp;
        for( int i = 0 ; i < n ; i++ )
            mp[target[i]] = i;
        n = ar.size();
        vector<int> idx;
        for( int i = 0 ; i < n ; i++ )
            if(mp.find(ar[i]) != mp.end())
                idx.push_back(mp[ar[i]]);
        vector<int> v;
        n = idx.size();
        for( int i = 0 ; i < n ; i++ ) {
            int x = idx[i];
            auto it = lower_bound(v.begin(), v.end(), x);
            if(it == v.end())
                v.push_back(x);
            else
                *it = x;
        }
        return target.size() - v.size();
    }
};