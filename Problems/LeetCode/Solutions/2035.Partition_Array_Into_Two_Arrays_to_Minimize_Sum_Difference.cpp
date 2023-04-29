class Solution {
public:
    int sum;
    set<int> vals[16];
    int ans = INT_MAX;
    void f(int val , int k , set<int>::iterator it) {
        set<int>::iterator it1 = it;
        set<int>::iterator it2 = it;
        if(it != vals[k].end()) {
            int total = val + (*it);
            ans = min(ans,abs(total-(sum-total)));
            it2++;
            if(it2 != vals[k].end()) {
                total = val + (*it2);
                ans = min(ans,abs(total-(sum-total)));
            }
        }
        if(it != vals[k].begin()) {
            it1--;
            int total = val + (*it1);
            ans = min(ans,abs(total-(sum-total)));
        }
    }
    int minimumDifference(vector<int>& ar) {
        int n = ar.size() / 2;
        int N = (1<<n);
        for( int i = 0 ; i < 2*n ; i++ )
            sum += ar[i];
        for( int bmask = 0 ; bmask < N ; bmask++ ) {
            int val = 0 , cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    val += ar[i] , cnt++;
            vals[cnt].insert(val);
        }
        for( int bmask = 0 ; bmask < N ; bmask++ ) {
            int val = 0 , cnt = 0;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    val += ar[i+n] , cnt++;
            f(val,n-cnt,vals[n-cnt].lower_bound(sum/2-val));
            f(val,n-cnt,vals[n-cnt].upper_bound(sum/2-val));
            f(val,n-cnt,vals[n-cnt].lower_bound(sum/2+1-val));
            f(val,n-cnt,vals[n-cnt].upper_bound(sum/2+1-val));
        }
        return ans;
    }
};