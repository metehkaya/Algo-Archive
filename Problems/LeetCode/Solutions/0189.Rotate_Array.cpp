class Solution {
public:
    void rotate(vector<int>& ar, int k) {
        int n = ar.size();
        vector<int> ans;
        k = k%n;
        k = (n-k%n);
        for( int i = 0 ; i < n ; i++ )
            ans.push_back(ar[(k+i)%n]);
        ar = ans;
    }
};