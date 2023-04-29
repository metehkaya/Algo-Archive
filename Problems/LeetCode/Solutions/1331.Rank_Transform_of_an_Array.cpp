typedef pair<int,int> pi;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& ar) {
        int n = ar.size();
        vector<pi> v;
        vector<int> ans(n);
        for( int i = 0 ; i < n ; i++ )
            v.push_back(pi(ar[i],i));
        sort(v.begin(),v.end());
        for( int i = 0 , j = 0 , val = 1 ; i < n ; i = j , val++ )
            while(j < n && v[i].first == v[j].first)
                ans[v[j++].second] = val;
        return ans;
    }
};