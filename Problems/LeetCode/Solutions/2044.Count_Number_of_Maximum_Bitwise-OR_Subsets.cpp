class Solution {
public:
    int countMaxOrSubsets(vector<int>& ar) {
        int n = ar.size();
        int N = (1<<n);
        int mx = 0 , ans = 0;
        for( int bmask = 1 ; bmask < N ; bmask++ ) {
            int num = 0;
            for( int i = 0 ; i < n ; i++ )
                if(bmask & (1<<i))
                    num |= ar[i];
            if(num > mx) {
                mx = num;
                ans = 1;
            }
            else if(num == mx)
                ans++;
        }
        return ans;
    }
};
