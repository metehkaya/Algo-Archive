class Solution {
public:
    bool check(int n) {
        vector<int> cnt(10,0);
        while(n) {
            cnt[n%10]++;
            n /= 10;
        }
        for( int i = 0 ; i < 10 ; i++ )
            if(cnt[i] && i != cnt[i])
                return false;
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while(!check(n))
            n++;
        return n;
    }
};
