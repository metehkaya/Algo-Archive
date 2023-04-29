class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& ar) {
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            while(ar[i] != ar[ar[i]-1])
                swap(ar[i],ar[ar[i]-1]);
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            if(ar[i] != i+1)
                ans.push_back(i+1);
        return ans;
    }
};