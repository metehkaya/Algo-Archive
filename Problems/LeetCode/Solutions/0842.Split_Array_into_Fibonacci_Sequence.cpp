#define pb push_back
typedef long long LL;

class Solution {
public:
    int n;
    string s;
    vector<int> ans,lens;
    bool mark[200][11][11];
    int str2num(int i , int j) {
        if(i < j && s[i] == '0')
            return -1;
        if(j-i+1 >= 11)
            return -1;
        LL num = 0;
        while(i <= j)
            num = 10*num + (s[i++]-'0');
        if(num > INT_MAX)
            return -1;
        return num;
    }
    bool f(int len2 , int num2 , int len1 , int num1 , int idx) {
        if(idx == n)
            return true;
        if(mark[idx][len1][len2])
            return false;
        mark[idx][len1][len2] = true;
        LL sum = (LL) num1 + num2;
        if(sum > INT_MAX)
            return false;
        LL num = 0;
        for( int i = idx ; i < n ; i++ ) {
            int num = str2num(idx,i);
            if(num == -1)
                break;
            if(num == sum && f(len1,num1,i-idx+1,num,i+1)) {
                lens.pb(i-idx+1);
                return true;
            }
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string s) {
        this->s = s;
        n = s.length();
        bool ok = false;
        for( int i = 0 ; i < n-2 && !ok ; i++ ) {
            int x = str2num(0,i);
            if(x == -1)
                break;
            for( int j = i+1 ; j < n-1 ; j++ ) {
                int y = str2num(i+1,j);
                if(y == -1)
                    break;
                if(f(i+1,x,j-i,y,j+1)) {
                    ok = true;
                    lens.pb(j-i);
                    lens.pb(i+1);
                    break;
                }
            }
        }
        if(!lens.empty()) {
            reverse(lens.begin(),lens.end());
            int sz = lens.size() , idx = 0;
            for( int i = 0 ; i < sz ; i++ ) {
                int num = 0 , cnt = lens[i];
                while(cnt--)
                    num = 10*num + (s[idx++]-'0');
                ans.pb(num);
            }
        }
        return ans;
    }
};