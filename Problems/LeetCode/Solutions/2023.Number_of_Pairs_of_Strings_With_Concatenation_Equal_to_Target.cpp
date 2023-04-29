class Solution {
public:
    int numOfPairs(vector<string>& ar, string t) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                if(i != j && t == ar[i]+ar[j])
                    ans++;
        return ans;
    }
};