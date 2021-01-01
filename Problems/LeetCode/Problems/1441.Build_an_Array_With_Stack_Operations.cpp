class Solution {
public:
    vector<string> buildArray(vector<int>& ar, int n) {
        vector<string> ans;
        n = ar.size();
        int last = 0;
        for( int i = 0 ; i < n ; i++ ) {
            int diff = ar[i]-last-1;
            last = ar[i];
            for( int i = 0 ; i < diff ; i++ )
                ans.push_back("Push"), ans.push_back("Pop");
            ans.push_back("Push");
        }
        return ans;
    }
};