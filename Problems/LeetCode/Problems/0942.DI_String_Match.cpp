class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> dec,inc;
        vector<int> ans(n+1);
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == 'I')
                inc.push_back(i);
            else
                dec.push_back(i);
        int cntd = dec.size();
        int cnti = inc.size();
        for( int i = cntd-1 ; i >= 0 ; i-- )
            ans[dec[i]+1] = cntd-i-1;
        for( int i = cnti-1 ; i >= 0 ; i-- )
            ans[inc[i]+1] = n-(cnti-1)+i;
        ans[0] = cntd;
        return ans;
    }
};