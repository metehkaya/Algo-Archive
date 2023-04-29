class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<int,int> cnt;
        for(string s : words) {
            int bmask = 0;
            for(char c : s)
                bmask |= (1<<(c-'a'));
            cnt[bmask]++;
        }
        int ans = 0;
        for(auto it : cnt) {
            int x = it.second;
            ans += x*(x-1)/2;
        }
        return ans;
    }
};
