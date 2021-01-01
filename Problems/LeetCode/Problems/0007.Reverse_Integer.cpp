class Solution {
public:
    int reverse(int X) {
        bool isPos = true;
        long long x = X;
        if(x < 0) {
            x = -x;
            isPos = false;
        }
        vector<int> v;
        while(x) {
            v.push_back(x%10);
            x /= 10;
        }
        for( int i = 0 ; i < v.size() ; i++ )
            x = 10*x+v[i];
        if(!isPos)
            x = -x;
        if(x < INT_MIN || x > INT_MAX)
            return 0;
        return (int) x;
    }
};