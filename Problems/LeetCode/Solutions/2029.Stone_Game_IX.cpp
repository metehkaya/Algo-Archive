class Solution {
public:
    bool stoneGameIX(vector<int>& ar) {
        int n = ar.size();
        vector<int> cnt(3,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[ar[i]%3]++;
        if(n == cnt[0])
            return false;
        if(cnt[2] == 0) {
            if(cnt[1] < 3)
                return false;
            if((cnt[0]+3) % 2)
                return false;
            return true;
        }
        if(cnt[1] == 0) {
            if(cnt[2] < 3)
                return false;
            if((cnt[0]+3) % 2)
                return false;
            return true;
        }
        if(cnt[0] % 2 == 0)
            return true;
        if(abs(cnt[1] - cnt[2]) >= 3)
            return true;
        return false;
    }
};
