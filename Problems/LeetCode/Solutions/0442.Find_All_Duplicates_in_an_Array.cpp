class Solution {
public:
    vector<int> findDuplicates(vector<int>& ar) {
        vector<int> ans;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            int num = abs(ar[i]);
            if(ar[num-1] < 0)
                ans.push_back(num);
            ar[num-1] *= -1;
        }
        return ans;
    }
};