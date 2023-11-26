class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = false;
            for(char c : words[i])
                if(c == x)
                    ok = true;
            if(ok)
                ans.push_back(i);
        }
        return ans;
    }
};
