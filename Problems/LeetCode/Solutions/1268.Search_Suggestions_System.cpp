class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& ar, string word) {
        int n = ar.size();
        sort(ar.begin() , ar.end());
        int len = word.length();
        vector<vector<string>> ans;
        for( int i = 0 , l = 0 , r = n-1 ; i < len ; i++ ) {
            while(l <= r && (i >= ar[l].length() or ar[l][i] != word[i]))
                l++;
            while(r >= l && (i >= ar[r].length() or ar[r][i] != word[i]))
                r--;
            vector<string> v;
            if(l <= r)
                for( int j = l ; j <= min(l+2,r) ; j++ )
                    v.push_back(ar[j]);
            ans.push_back(v);
        }
        return ans;
    }
};