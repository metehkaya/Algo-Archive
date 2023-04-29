class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        bool neg = (num < 0);
        num = abs(num);
        vector<int> digs;
        while(num) {
            digs.push_back(num%10);
            num /= 10;
        }
        int n = digs.size();
        sort(digs.begin(),digs.end());
        long long ans = 0;
        if(neg) {
            for( int i = n-1 ; i >= 0 ; i-- )
                ans = 10*ans + digs[i];
            ans = -ans;
        }
        else {
            int idx = -1;
            for( int i = 0 ; i < n ; i++ )
                if(digs[i] > 0) {
                    idx = i;
                    ans = digs[i];
                    break;
                }
            for( int i = 0 ; i < n ; i++ )
                if(i != idx)
                    ans = 10*ans + digs[i];
        }
        return ans;
    }
};
