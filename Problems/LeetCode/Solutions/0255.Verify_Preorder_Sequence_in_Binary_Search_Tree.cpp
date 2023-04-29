class Solution {
public:
    bool verifyPreorder(vector<int>& v) {
        stack<vector<int>> st;
        st.push({INT_MIN,INT_MAX});
        for(int x : v) {
            while(!st.empty() and (x < st.top()[0] or x > st.top()[1]))
                st.pop();
            if(st.empty())
                return false;
            auto v = st.top();
            st.pop();
            if(x < v[1])
                st.push({x+1,v[1]});
            if(x > v[0])
                st.push({v[0],x-1});
        }
        return true;
    }
};
