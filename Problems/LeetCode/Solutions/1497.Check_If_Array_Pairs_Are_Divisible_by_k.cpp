class Solution {
public:
    bool canArrange(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> cnt(k,0);
        for( int i = 0 ; i < n ; i++ ) {
            if(ar[i] >= 0)
                cnt[ar[i]%k]++;
            else
                cnt[(k-abs(ar[i])%k)%k]++;
        }
        for( int i = 1 ; i < k ; i++ )
            if(cnt[i] != cnt[k-i])
                return false;
        if(k%2 == 0 && cnt[k/2]%2)
            return false;
        if(cnt[0]%2)
            return false;
        return true;
    }
};