class Solution {
public:
    long long maxSum(vector<int>& v, int m, int k) {
        int n = v.size() , cnt = 0;
        long long sum = 0 , ans = 0;
        map<int,int> mp;
        for( int i = 0 ; i < k ; i++ ) {
            sum += v[i];
            if(++mp[v[i]] == 1)
                cnt++;
        }
        if(cnt >= m)
            ans = sum;
        for( int i = k ; i < n ; i++ ) {
            int j = i-k;
            sum += v[i];
            if(++mp[v[i]] == 1)
                cnt++;
            sum -= v[j];
            if(--mp[v[j]] == 0)
                cnt--;
            if(cnt >= m)
                ans = max(ans,sum);
        }
        return ans;
    }
};
