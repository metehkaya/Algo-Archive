class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size() , cnt = 0;
        vector<int> ans;
        vector<int> bmask(n+1,0);
        for( int i = 0 ; i < n ; i++ ) {
            bmask[a[i]] ^= 1;
            if(bmask[a[i]] == 3)
                cnt++;
            bmask[b[i]] ^= 2;
            if(bmask[b[i]] == 3)
                cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};
