class Solution {
public:
    int getWinner(vector<int>& ar, int k) {
        int n = ar.size() , mx = 0;
        for( int i = 0 ; i < n ; i++ )
            mx = max(mx,ar[i]);
        if(k >= n-1)
            return mx;
        int i = 0 , j = 1 , res = -1 , cnt = 0;
        while(cnt < k) {
            if(ar[i] == mx or ar[j] == mx)
                return mx;
            if(ar[i] > ar[j]) {
                if(res == ar[i])
                    cnt++;
                else
                    res = ar[i] , cnt = 1;
                j = max(i,j) + 1;
            }
            else {
                if(res == ar[j])
                    cnt++;
                else
                    res = ar[j] , cnt = 1;
                i = max(i,j) + 1;
            }
        }
        return res;
    }
};