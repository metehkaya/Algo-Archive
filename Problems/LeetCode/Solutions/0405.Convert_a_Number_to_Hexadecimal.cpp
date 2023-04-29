class Solution {
public:
    string toHex(int num) {
        string ans = "";
        for( int i = 0 ; i < 8 ; i++ ) {
            int x = (num & 15);
            num >>= 4;
            if(x <= 9)
                ans.push_back('0'+x);
            else
                ans.push_back('a'+(x-10));
            if(num == 0)
                break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};