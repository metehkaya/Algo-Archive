#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& v, int k) {
        int n = v.size();
        vector<int> sum(n);
        sum[0] = v[0];
        for( int i = 1 ; i < n ; i++ )
            sum[i] = sum[i-1] + v[i];
        vector<int> group(n);
        group[0] = sum[k-1];
        for( int i = 1 ; i <= n-k ; i++ )
            group[i] = sum[i+k-1] - sum[i-1];
        set<pi> l,r;
        l.insert(pi(-group[0],0));
        for( int i = 2*k ; i <= n-k ; i++ )
            r.insert(pi(-group[i],i));
        vector<int> ans(3);
        int best_score = 0;
        for( int i = k ; i <= n-2*k ; i++ ) {
            int best_l = -((*l.begin()).fi);
            int best_r = -((*r.begin()).fi);
            int score = group[i]+best_l+best_r;
            vector<int> pos(3);
            pos[0] = (*l.begin()).se;
            pos[1] = i;
            pos[2] = (*r.begin()).se;
            if(score > best_score) {
                best_score = score;
                ans = pos;
            }
            else if(score == best_score) {
                if(pos[0] < ans[0] or (pos[0] == ans[0] and pos[1] < ans[1]) or (pos[0] == ans[0] and pos[1] == ans[1] and pos[2] < ans[2]))
                    ans = pos;
            }
            l.insert(pi(-group[i-k+1],i-k+1));
            r.erase(pi(-group[i+k],i+k));
        }
        return ans;
    }
};
