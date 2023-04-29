class Solution {
public:
    vector<vector<int>> abbreviations;
    void f(string& s , int idx , int len , bool allow , vector<int>& add) {
        if(idx == len) {
            abbreviations.push_back(add);
            return;
        }
        if(allow)
            for( int i = idx+1 ; i <= len ; i++ ) {
                add.push_back(i-idx);
                f(s,i,len,false,add);
                add.pop_back();
            }
        add.push_back('a'-s[idx]);
        f(s,idx+1,len,true,add);
        add.pop_back();
    }
    string minAbbreviation(string s, vector<string>& tmp_dict) {
        vector<string> dict;
        for(string& t : tmp_dict)
            if(s.length() == t.length())
                dict.push_back(t);
        vector<int> add;
        int len = s.length();
        f(s,0,len,true,add);
        sort(abbreviations.begin() , abbreviations.end() , [&](auto& a , auto& b) {
            return a.size() < b.size();
        });
        string ans = "";
        for(vector<int>& v : abbreviations) {
            bool ok = true;
            for(string& t : dict) {
                int idx = 0;
                bool same = true;
                for(int val : v) {
                    if(val > 0)
                        idx += val;
                    else {
                        if(t[idx] != 'a'-val) {
                            same = false;
                            break;
                        }
                        idx++;
                    }
                }
                if(same) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                for(int val : v)
                    if(val > 0)
                        ans += to_string(val);
                    else
                        ans.push_back('a'-val);
                break;
            }
        }
        return ans;
    }
};
