class Solution {
public:
    bool f(int l , int r , int cnt , string& s , vector<int>& end , vector<vector<int>>& commas) {
        if(l == r) {
            if(s[l] == 't')
                return true;
            return false;
        }
        cnt++;
        if(s[l] == '!')
            return !f(l+2,r-1,cnt,s,end,commas);
        char c = s[l];
        vector<int> v = commas[l+1];
        int vs = v.size();
        if(vs == 0)
            return f(l+2,r-1,cnt,s,end,commas);
        vector<bool> res;
        res.push_back( f(l+2,v[0]-1,cnt,s,end,commas) );
        res.push_back( f(v[vs-1]+1,r-1,cnt,s,end,commas) );
        for( int i = 0 ; i < vs-1 ; i++ )
            res.push_back( f(v[i]+1,v[i+1]-1,cnt,s,end,commas) );
        bool ans = res[0];
        for( int i = 1 ; i < res.size() ; i++ ) {
            if(c == '&')
                ans &= res[i];
            else
                ans |= res[i];
        }
        return ans;
    }
    bool parseBoolExpr(string s) {
        int n = s.length();
        int cnt = 0;
        stack<int> st;
        vector<int> end(n,-1);
        vector<vector<int>> coms(n+1);
        vector<vector<int>> commas(n+1);
        for( int i = 0 ; i < n ; i++ ) {
            char c = s[i];
            if(c == '(') {
                cnt++;
                st.push(i);
            }
            else if(c == ')') {
                int index = st.top();
                st.pop();
                end[index] = i;
                end[i] = index;
                coms[index] = commas[cnt];
                commas[cnt].clear();
                cnt--;
            }
            else if(c == ',')
                commas[cnt].push_back(i);
        }
        return f(0,n-1,0,s,end,coms);
    }
};