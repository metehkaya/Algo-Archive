class Solution {
public:
    vector<string> removeAnagrams(vector<string>& ar) {
        int n = ar.size();
        vector<string> ans;
        ans.push_back(ar[0]);
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n) {
                string old_str = ar[j];
                sort(ar[j].begin(),ar[j].end());
                if(ar[j] != ar[i]) {
                    ans.push_back(old_str);
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
