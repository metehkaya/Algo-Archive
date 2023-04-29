class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& ar) {
        int n = ar.size();
        vector<bool> mark(1000,false);
        for( int i = 0 ; i < n ; i++ )
            for( int j = 0 ; j < n ; j++ )
                for( int k = 0 ; k < n ; k++ )
                    if(i != j && i != k && j != k && ar[i] > 0 && ar[k] % 2 == 0)
                        mark[100*ar[i]+10*ar[j]+ar[k]] = true;
        vector<int> ans;
        for( int i = 100 ; i < 1000 ; i++ )
            if(mark[i])
                ans.push_back(i);
        return ans;
    }
};
