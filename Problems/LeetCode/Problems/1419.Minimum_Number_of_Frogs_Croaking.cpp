class Solution {
public:
    int minNumberOfFrogs(string str) {
        int toInt[256];
        toInt['c']=0,toInt['r']=1,toInt['o']=2,toInt['a']=3,toInt['k']=4;
        vector<int> cnt(5,0);
        int n = str.length();
        for( int i = 0 ; i < n ; i++ ) {
            int val = toInt[str[i]];
            if(val == 0) {
                cnt[0] = max( cnt[0]-1 , 0 );
                cnt[1]++;
            }
            else {
                if(cnt[val] <= 0)
                    return -1;
                cnt[val]--;
                cnt[(val+1)%5]++;
            }
        }
        for( int i = 1 ; i < 5 ; i++ )
            if(cnt[i])
                return -1;
        return cnt[0];
    }
};