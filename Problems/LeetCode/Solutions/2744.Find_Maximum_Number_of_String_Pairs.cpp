class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = i+1 ; j < n ; j++ )
                if(words[i][0] == words[j][1] and words[i][1] == words[j][0])
                    ans++;
        return ans;
    }
};
