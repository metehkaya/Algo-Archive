class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(),s.end());
        int x=0 , y=0 , n = s.length();
        for( int i = 0 ; i < n ; i++ ) {
            if(i % 2 == 0)
                x = 10*x + (s[i]-'0');
            else
                y = 10*y + (s[i]-'0');
        }
        return x+y;
    }
};
