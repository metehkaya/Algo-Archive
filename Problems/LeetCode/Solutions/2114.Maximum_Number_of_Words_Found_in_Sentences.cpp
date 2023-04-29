class Solution {
public:
    int mostWordsFound(vector<string>& ar) {
        int n = ar.size() , ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int len = ar[i].length() , cnt = 0;
            for( int j = 0 ; j < len ; j++ )
                if(ar[i][j] == ' ')
                    cnt++;
            ans = max(ans,cnt+1);
        }
        return ans;
    }
};
