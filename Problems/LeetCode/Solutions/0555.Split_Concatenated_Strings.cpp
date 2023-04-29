class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        string s_all = "" , ans = "";
        for(auto& s : strs) {
            string rev = s;
            reverse(rev.begin(),rev.end());
            s_all += max(s,rev);
        }
        int len_all = s_all.length();
        for( int i = 0 , start = 0 ; i < n ; start += strs[i++].length() ) {
            int len = strs[i].length();
            int finish = start + len;
            string other = s_all.substr(finish) + s_all.substr(0,start);
            string s = strs[i];
            string t = s;
            reverse(t.begin(),t.end());
            for( int j = 0 ; j < len ; j++ ) {
                string s_head = s.substr(j) , s_tail = s.substr(0,j);
                string t_head = t.substr(j) , t_tail = t.substr(0,j);
                ans = max(ans,s_head+other+s_tail);
                ans = max(ans,t_head+other+t_tail);
            }
        }
        return ans;
    }
};
