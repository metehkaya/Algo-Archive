class Solution {
public:
    bool isCovered(vector<vector<int>>& ar, int left, int right) {
        int n = ar.size();
        bool var[51];
        memset(var,false,sizeof(var));
        for( int i = 0 ; i < n ; i++ )
            for( int j = ar[i][0] ; j <= ar[i][1] ; j++ )
                var[j] = true;
        for( int i = left ; i <= right ; i++ )
            if(!var[i])
                return false;
        return true;
    }
};