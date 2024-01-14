class Solution {
public:
    vector<int> compute_lps(string& pattern) {
        int length = 0 , i = 1;
        vector<int> lps(pattern.size());
        lps[0] = 0;
        while(i < pattern.size()) {
            if(pattern[i] == pattern[length])
                lps[i++] = ++length;
            else {
                if(length != 0)
                    length = lps[length - 1];
                else
                    lps[i++] = 0;
            }
        }
        return lps;
    }
    vector<int> kmp(string& text, string& pattern) {
        vector<int> lps = compute_lps(pattern);
        vector<int> matches;
        int i = 0 , j = 0;
        while(i < text.size()) {
            if(pattern[j] == text[i])
                i++ , j++;
            if(j == pattern.size()) {
                matches.push_back(i-j);
                j = lps[j-1];
            }
            else if(i < text.size() && pattern[j] != text[i]) {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return matches;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> va = kmp(s,a);
        vector<int> vb = kmp(s,b);
        vector<int> ans;
        for(int idx : va) {
            auto it1 = lower_bound(vb.begin(),vb.end(),idx-k);
            auto it2 = upper_bound(vb.begin(),vb.end(),idx+k);
            if(it2-it1 > 0)
                ans.push_back(idx);
        }
        return ans;
    }
};
