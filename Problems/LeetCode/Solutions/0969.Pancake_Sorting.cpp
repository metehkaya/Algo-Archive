class Solution {
public:
    void rev(vector<int>& ar , int k) {
        for( int i = 0 ; i < k/2 ; i++ )
            swap(ar[i],ar[k-1-i]);
    }
    vector<int> pancakeSort(vector<int>& ar) {
        vector<int> ans;
        int n = ar.size();
        for( int e = n ; e >= 1 ; e-- ) {
            int idx = -1;
            for( int i = 0 ; i < n ; i++ )
                if(ar[i] == e)
                    idx = i;
            if(e != idx+1) {
                ans.push_back(idx+1);
                ans.push_back(e);
                rev(ar,idx+1);
                rev(ar,e);
            }
        }
        return ans;
    }
};