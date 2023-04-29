typedef pair<int,int> pi;

class Solution {
public:
    int gcd(int x , int y) {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    long long interchangeableRectangles(vector<vector<int>>& ar) {
        int n = ar.size();
        map<pi,int> cnt;
        for( int i = 0 ; i < n ; i++ ) {
            int x = ar[i][0];
            int y = ar[i][1];
            int g = gcd(x,y);
            x /= g , y /= g;
            cnt[pi(x,y)]++;
        }
        long long ans = 0;
        for(auto it : cnt) {
            long long x = it.second;
            ans += x*(x-1)/2;
        }
        return ans;
    }
};