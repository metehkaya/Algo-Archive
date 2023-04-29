class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> vowels({'a','e','i','o','u'});
        int ans = 0 , n = words.size();
        for( int i = left ; i <= right ; i++ ) {
            int len = words[i].length();
            if(vowels.count(words[i][0]) and vowels.count(words[i][len-1]))
                ans++;
        }
        return ans;
    }
};
