class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        set<int> collection;
        for(string s : startWords) {
            int bmask = 0;
            for(char c : s)
                bmask |= (1<<(c-'a'));
            collection.insert(bmask);
        }
        int ans = 0;
        for(string s : targetWords) {
            int bmask = 0;
            for(char c : s)
                bmask |= (1<<(c-'a'));
            for(char c : s)
                if(collection.find(bmask^(1<<(c-'a'))) != collection.end()) {
                    ans++;
                    break;
                }
        }
        return ans;
    }
};
