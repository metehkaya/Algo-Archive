class Solution {
public:
    int countDistinct(vector<int>& ar, int k, int p) {
        int n = ar.size();
        vector<vector<int>> vecs[n];
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            vector<int> v;
            for( int j = i ; j < n ; j++ ) {
                if(ar[j] % p == 0)
                    cnt++;
                if(cnt > k)
                    break;
                v.push_back(ar[j]);
                vecs[j-i].push_back(v);
            }
        }
        int ans = 0;
        for( int k = 0 ; k < n ; k++ )
            if(!vecs[k].empty()) {
                int sz = vecs[k].size();
                ans++;
                sort(vecs[k].begin(),vecs[k].end());
                for( int i = 1 ; i < sz ; i++ )
                    if(vecs[k][i] != vecs[k][i-1])
                        ans++;
            }
        return ans;
    }
};
