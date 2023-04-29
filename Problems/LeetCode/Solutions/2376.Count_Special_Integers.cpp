class Solution {
public:
    vector<int> getDigs(int n) {
        vector<int> digs;
        while(n) {
            digs.push_back(n%10);
            n /= 10;
        }
        reverse(digs.begin(), digs.end());
        return digs;
    }
    int countSpecialNumbers(int n) {
        n++;
        vector<int> digs = getDigs(n);
        int nd = digs.size();
        int ans = 0;
        for( int i = 0 , bmask = 0 ; i < nd ; i++ ) {
            int cnt = 0;
            int d = digs[i];
            for( int k = 1 ; k < d ; k++ )
                if(!(bmask & (1<<k)))
                    cnt++;
            if(i > 0 && d > 0 && !(bmask & 1))
                cnt++;
            int add = cnt;
            for( int j = i+1 ; j < nd ; j++ )
                add *= 10-j;
            ans += add;
            if(bmask & (1<<d))
                break;
            bmask |= (1<<d);
        }
        for( int i = 1 ; i < nd ; i++ ) {
            int add = 9;
            for( int j = 1 ; j < i ; j++ )
                add *= 10-j;
            ans += add;
        }
        return ans;
    }
};
