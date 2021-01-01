class Solution {
public:
    vector<int> addToArrayForm(vector<int>& ar, int k) {
        vector<int> ans;
        int n = ar.size();
        int add = 0;
        for( int i = n-1 ; i >= 0 or add or k ; i-- ) {
            int d = add + k%10;
            if(i >= 0)
                d += ar[i];
            k /= 10;
            add = d/10;
            ans.push_back(d%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};