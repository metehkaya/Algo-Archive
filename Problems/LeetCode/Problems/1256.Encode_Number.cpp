class Solution {
public:
    string encode(int num) {
        int sum = 0 , len = 0;
        while(sum + (1 << len) <= num)
            sum += (1 << (len++));
        int diff = num - sum;
        string ans = "";
        for( int i = len - 1 ; i >= 0 ; i-- ) {
            char c = '0' + (diff % 2);
            ans.push_back(c);
            diff /= 2;
        }
        reverse( ans.begin() , ans.end() );
        return ans;
    }
};