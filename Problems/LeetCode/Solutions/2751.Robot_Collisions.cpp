class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int,int>> v;
        for( int i = 0 ; i < n ; i++ )
            v.push_back(make_pair(positions[i],i));
        sort(v.begin(),v.end());
        vector<int> st;
        for( int i = 0 ; i < n ; i++ ) {
            bool add = true;
            int idx = v[i].second;
            if(directions[idx] == 'L')
                while(!st.empty() and directions[st.back()] == 'R') {
                    int idx_prev = st.back();
                    if(healths[idx_prev] == healths[idx]) {
                        st.pop_back();
                        add = false;
                        break;
                    }
                    else if(healths[idx_prev] > healths[idx]) {
                        healths[idx_prev]--;
                        add = false;
                        break;
                    }
                    else {
                        st.pop_back();
                        healths[idx]--;
                    }
                }
            if(add)
                st.push_back(idx);
        }
        sort(st.begin(),st.end());
        vector<int> ans;
        for(int idx : st)
            ans.push_back(healths[idx]);
        return ans;
    }
};
