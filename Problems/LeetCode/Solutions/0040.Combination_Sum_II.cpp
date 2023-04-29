#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int n,t;
    vector<pi> ar;
    bool dp[101][31];
    vector<int> v[101][31];
    vector<vector<int>> ans;
    void f(int id , int k , vector<int>& curr) {
        if(id == 0) {
            vector<int> add;
            for( int i = n-1 ; i >= 0 ; i-- )
                for( int j = 0 ; j < curr[i] ; j++ )
                    add.pb(ar[n-1-i].fi);
            ans.pb(add);
            return;
        }
        int sz = v[id][k].size();
        for( int i = 0 ; i < sz ; i++ ) {
            int cnt = v[id][k][i];
            int j = k - cnt*ar[id-1].fi;
            curr.pb(cnt);
            f(id-1,j,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int t) {
        this->t = t;
        n = arr.size();
        sort(arr.begin(),arr.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && arr[i] == arr[j])
                j++;
            ar.pb(pi(arr[i],j-i));
        }
        n = ar.size();
        dp[0][0] = true;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j <= t ; j++ )
                if(dp[i][j]) {
                    int mx = min(ar[i].se,(t-j)/ar[i].fi);
                    for( int k = 0 ; k <= mx ; k++ ) {
                        int j2 = j + k*ar[i].fi;
                        v[i+1][j2].pb(k);
                        dp[i+1][j2] = true;
                    }
                }
        vector<int> curr;
        if(dp[n][t])
            f(n,t,curr);
        return ans;
    }
};