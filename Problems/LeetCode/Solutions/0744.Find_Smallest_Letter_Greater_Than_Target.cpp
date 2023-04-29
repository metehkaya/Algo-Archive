class Solution {
public:
    char nextGreatestLetter(vector<char>& ar, char t) {
        int n = ar.size();
        if(t >= ar[n-1])
            return ar[0];
        int l = 0 , r = n-1 , last;
        while(l <= r) {
            int m = (l+r)>>1;
            if(ar[m] > t)
                last = m , r = m-1;
            else
                l = m+1;
        }
        return ar[last];
    }
};