class Solution {
public:
    bool isNStraightHand(vector<int>& ar, int k) {
        int n = ar.size();
        if(n % k)
            return false;
        map<int,int> cnt;
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]]++;
        int times = n/k;
        while(times--) {
            int val = cnt.begin()->first;
            for( int i = 0 ; i < k ; i++ ) {
                int x = val+i;
                if(cnt.find(x) == cnt.end())
                    return false;
                if(--cnt[x] == 0)
                    cnt.erase(x);
            }
        }
        return true;
    }
};