class Solution {
public:
    vector<int> findClosestElements(vector<int>& ar, int k, int x) {
        int n = ar.size();
        int l = 0 , r = n-1 , last = n;
        while(l <= r) {
            int m = (l+r) >> 1;
            if(x <= ar[m])
                last = m , r = m-1;
            else
                l = m+1;
        }
        l = r = last;
        while(r < n && k > 0 && ar[r] == x) {
            k--;
            r++;
        }
        while(k > 0) {
            k--;
            if(l == 0)
                r++;
            else if(r == n)
                l--;
            else {
                int dl = x-ar[l-1];
                int dr = ar[r]-x;
                if(dl <= dr)
                    l--;
                else
                    r++;
            }
        }
        vector<int> ans;
        for( int i = l ; i < r ; i++ )
            ans.push_back(ar[i]);
        return ans;
    }
};