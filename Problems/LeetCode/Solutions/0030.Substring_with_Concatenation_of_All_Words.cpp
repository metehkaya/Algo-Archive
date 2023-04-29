class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int k = words[0].length();
        map<string,int> hash1;
        for( int i = 0 ; i < m ; i++ )
            hash1[words[i]]++;
        vector<int> ans;
        for( int i = 0 ; i <= n-m*k ; i++ ) {
            map<string,int> hash2 = hash1;
            bool cond = true;
            for( int j = 0 ; j < m ; j++ ) {
                string t = s.substr(i+j*k,k);
                if(hash2[t] == 0) {
                    cond = false;
                    break;
                }
                hash2[t]--;
            }
            if(cond)
                ans.push_back(i);
        }
        return ans;
    }
};
