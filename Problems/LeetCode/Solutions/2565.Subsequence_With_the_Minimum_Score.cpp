class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.length() , m = t.length();
        int ans = m , last = m;
        vector<int> idx(m+1,-1);
        idx[m] = n;
        for( int i = m-1 ; i >= 0 ; i-- ) {
            int j = idx[i+1]-1;
            while(j >= 0 and t[i] != s[j])
                j--;
            if(j == -1) {
                ans = i+1;
                break;
            }
            if(i == 0)
                return 0;
            last = i;
            idx[i] = j;
        }
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while(j < n and t[i] != s[j])
                j++;
            if(j == n)
                break;
            while(last < m and idx[last] <= j)
                last++;
            ans = min(ans,last-i-1);
            j++;
        }
        return ans;
    }
};
