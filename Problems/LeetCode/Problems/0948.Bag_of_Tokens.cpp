class Solution {
public:
    int bagOfTokensScore(vector<int>& ar, int p) {
        int n = ar.size() , P = p;
        sort(ar.begin(),ar.end());
        int i = 0 , j = n;
        while(i < j && p >= ar[i])
            p -= ar[i++];
        if(!P)
            return i;
        int ans = i , curr = i;
        while(j > i) {
            p += ar[--j];
            curr--;
            if(curr < 0)
                break;
            while(i < j && p >= ar[i]) {
                curr++;
                p -= ar[i++];
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};