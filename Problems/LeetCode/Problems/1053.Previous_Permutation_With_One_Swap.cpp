class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& ar) {
        stack<int> st;
        int n = ar.size();
        pair<int,int> ans = make_pair(0,0);
        for( int i = 0 ; i < n ; i++ ) {
            while(!st.empty() && ar[st.top()] <= ar[i])
                st.pop();
            if(!st.empty())
                if(ans == make_pair(0,0) || st.top() > ans.first || (st.top() == ans.first && ar[i] > ar[ans.second]))
                    ans = make_pair(st.top(),i);
            st.push(i);
        }
        int l = ans.first;
        int r = ans.second;
        swap(ar[l], ar[r]);
        return ar;
    }
};