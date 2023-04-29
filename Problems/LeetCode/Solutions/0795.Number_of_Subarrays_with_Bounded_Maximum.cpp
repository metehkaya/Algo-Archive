typedef long long LL;

class Solution {
public:
    LL neg(int x , int y) {
        if(x > y)
            return 0;
        LL len = y-x+1;
        return len*(len+1)/2;
    }
    int numSubarrayBoundedMax(vector<int>& ar, int lower, int upper) {
        LL ans = 0;
        int n = ar.size();
        for( int l = 0 , r = 0 ; l < n ; l = r ) {
            if(ar[l] > upper)
                r++;
            else {
                vector<int> v;
                while(r < n && ar[r] <= upper)
                    if(ar[r++] >= lower)
                        v.push_back(r-1-l);
                LL len = r-l;
                if(!v.empty()) {
                    int sz = v.size();
                    LL add = len*(len+1)/2;
                    add -= neg(0,v[0]-1);
                    add -= neg(v[sz-1]+1,len-1);
                    for( int i = 1 ; i < sz ; i++ )
                        add -= neg(v[i-1]+1,v[i]-1);
                    ans += add;
                }
            }
        }
        return (int) ans;
    }
};