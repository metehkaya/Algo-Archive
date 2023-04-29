class Solution {
public:
    int f(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int n = s.length();
        int num = 0;
        for( int i = 0 ; i < n ; i++ )
            num += f(s[i]-'a'+1);
        while(--k)
            num = f(num);
        return num;
    }
};