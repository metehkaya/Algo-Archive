class Solution {
public:
    int maximum69Number (int num) {
        int tmp = num;
        vector<int> digs(4,0);
        for( int i = 3 ; i>= 0 ; i-- ) {
            int dig = num%10;
            digs[i] = dig;
            num /= 10;
        }
        int ans = tmp;
        for( int i = 0 , add = 3000 ; i < 4 ; i++ , add /= 10 )
            if(digs[i] == 6) {
                ans += add;
                break;
            }
        return ans;
    }
};