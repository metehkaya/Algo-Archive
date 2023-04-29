class Solution {
public:
    int f(vector<int>& cnt, int rem) {
        int ans;
        for( int i = 0 , sum = 0 ; i <= 100 ; i++ ) {
            sum += cnt[i];
            if(sum >= rem) {
                ans = min(i-50,0);
                break;
            }
        }
        return ans;
    }
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
        int n = v.size();
        vector<int> cnt(101,0);
        for( int i = 0 ; i < k ; i++ )
            cnt[v[i]+50]++;
        vector<int> ans;
        ans.push_back(f(cnt,x));
        for( int i = k ; i < n ; i++ ) {
            cnt[v[i]+50]++;
            cnt[v[i-k]+50]--;
            ans.push_back(f(cnt,x));
        }
        return ans;
    }
};
