class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> mx(26,0);
        for( int i = 0 ; i < B.size() ; i++ ) {
            string s = B[i];
            vector<int> cnt(26,0);
            for( int j = 0 ; j < s.length() ; j++ )
                cnt[s[j]-'a']++;
            for( int j = 0 ; j < 26 ; j++ )
                mx[j] = max( mx[j] , cnt[j] );
        }
        vector<string> ans;
        for( int i = 0 ; i < A.size() ; i++ ) {
            string s = A[i];
            vector<int> cnt(26,0);
            for( int j = 0 ; j < s.length() ; j++ )
                cnt[s[j]-'a']++;
            bool ok = true;
            for( int j = 0 ; j < 26 ; j++ )
                if(cnt[j] < mx[j])
                    ok = false;
            if(ok)
                ans.push_back(s);
        }
        return ans;
    }
};