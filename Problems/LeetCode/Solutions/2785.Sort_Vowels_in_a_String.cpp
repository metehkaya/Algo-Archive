class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels = set({'a','e','i','o','u','A','E','I','O','U'});
        int n = s.length();
        vector<int> indices;
        vector<char> vowels_sorted;
        for( int i = 0 ; i < n ; i++ )
            if(vowels.count(s[i])) {
                indices.push_back(i);
                vowels_sorted.push_back(s[i]);
            }
        sort(vowels_sorted.begin(),vowels_sorted.end());
        n = vowels_sorted.size();
        for( int i = 0 ; i < n ; i++ )
            s[indices[i]] = vowels_sorted[i];
        return s;
    }
};
