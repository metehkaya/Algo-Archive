class Solution {
public:
    int maxSatisfaction(vector<int>& ar) {
        int N = ar.size();
        vector<int> pos,neg;
        for( int i = 0 ; i < N ; i++ )
            if(ar[i] >= 0)
                pos.push_back(ar[i]);
            else
                neg.push_back(-ar[i]);
        int ans = 0;
        int sump = 0;
        int sumn = 0;
        int p = pos.size();
        int n = neg.size();
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        for( int i = 0 ; i < p ; i++ ) {
            sump += pos[i];
            ans += (i+1) * pos[i];
        }
        int curr = ans;
        for( int i = 0 ; i < n ; i++ ) {
            curr += sump;
            sumn += neg[i];
            curr -= sumn;
            ans = max(ans, curr);
        }
        return ans;
    }
};