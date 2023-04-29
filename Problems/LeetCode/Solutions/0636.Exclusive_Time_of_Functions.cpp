class Solution {
public:
    void split(string& s , int& id , int& ts , bool& type) {
        int lens = s.length();
        int idxs = s.find(':');
        string s_id = s.substr(0,idxs);
        string t = s.substr(idxs+1);
        int idxt = t.find(':');
        int lent = t.length();
        string t_ts = t.substr(idxt+1);
        id = stoi(s_id);
        ts = stoi(t_ts);
        type = (t[0] == 's');
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n,0);
        int prev = -1;
        for(string& s : logs) {
            int id,t;
            bool type;
            split(s,id,t,type);
            if(!type)
                t++;
            if(!st.empty())
                ans[st.top()] += t - prev; 
            if(type)
                st.push(id);
            else
                st.pop();
            prev = t;
        }
        return ans;
    }
};
