class Solution {
public:
    map<int, stack<int> > st;
    vector<int> anagramMappings(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for( int i = 0 ; i < n ; i++ )
            st[b[i]].push(i);
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ ) {
            int idx = st[a[i]].top();
            st[a[i]].pop();
            ans.push_back(idx);
        }
        return ans;
    }
};