class Solution {
public:
    int minOperations(vector<int>& ar, int x) {
        map<int,int> mp;
        mp[0] = 0;
        int n = ar.size();
        for( int i = 0 , sum = 0 ; i < n ; i++ ) {
            sum += ar[i];
            mp[sum] = i+1;
        }
        int ans = n+1;
        map<int,int>::iterator it = mp.find(x);
        if(it != mp.end())
            ans = it->second;
        for( int i = n-1 , sum = 0 ; i >= 0 ; i-- ) {
            sum += ar[i];
            it = mp.find(x-sum);
            if(it != mp.end())
                ans = min(ans,n-i+it->second);
        }
        return (ans > n) ? -1 : ans;
    }
};