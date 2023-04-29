#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& ar, int k) {
        stack<int> st;
        int n = ar.size();
        int rem = n-k;
        for( int i = 0 ; i < n ; i++ ) {
            while(!st.empty() && st.top() > ar[i] && rem > 0) {
                rem--;
                st.pop();
            }
            st.push(ar[i]);
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return vector<int>(ans.begin(), ans.begin()+k);
    }
};
