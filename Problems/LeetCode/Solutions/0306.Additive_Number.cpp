typedef long long LL;

class Solution {
public:
    int n;
    string s;
    bool mark[35][19][19];
    LL str2num(int i , int j) {
        if(i < j && s[i] == '0')
            return -1;
        if(j-i+1 >= 19)
            return -1;
        LL num = 0;
        while(i <= j)
            num = 10*num + (s[i++]-'0');
        return num;
    }
    bool f(int len2 , LL num2 , int len1 , LL num1 , int idx) {
        if(idx == n)
            return true;
        if(mark[idx][len1][len2])
            return false;
        mark[idx][len1][len2] = true;
        LL sum = (LL) num1 + num2;
        if(sum > LLONG_MAX)
            return false;
        LL num = 0;
        for( int i = idx ; i < n ; i++ ) {
            LL num = str2num(idx,i);
            if(num == -1)
                break;
            if(num == sum && f(len1,num1,i-idx+1,num,i+1))
                return true;
        }
        return false;
    }
    bool isAdditiveNumber(string s) {
        this->s = s;
        n = s.length();
        for( int i = 0 ; i < n-2 ; i++ ) {
            LL x = str2num(0,i);
            if(x == -1)
                break;
            for( int j = i+1 ; j < n-1 ; j++ ) {
                LL y = str2num(i+1,j);
                if(y == -1)
                    break;
                if(f(i+1,x,j-i,y,j+1))
                    return true;
            }
        }
        return false;
    }
};