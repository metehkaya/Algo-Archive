class Solution {
public:
    int minDeletionSize(vector<string>& ar) {
        int n = ar.size() , m = ar[0].size() , ans = 0;
        vector<string> words(n,"");
        for( int j = 0 ; j < m ; j++ ) {
            vector<string> temp = words;
            for( int i = 0 ; i < n ; i++ )
                temp[i].push_back(ar[i][j]);
            bool ok = true;
            for( int i = 0 ; i < n-1 ; i++ )
                if(temp[i] > temp[i+1])
                    ok = false;
            if(ok)
                words = temp;
            else
                ans++;
        }
        return ans;
    }
};