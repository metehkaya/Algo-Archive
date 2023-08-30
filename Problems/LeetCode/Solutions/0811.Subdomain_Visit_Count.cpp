class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mp;
        for(string cp_domain : cpdomains) {
            int idx = cp_domain.find(" ");
            int n = stoi(cp_domain.substr(0, idx));
            string s = cp_domain.substr(idx+1);
            mp[s] += n;
            for( int i = 0 ; i < s.size() ; i++ )
                if(s[i] == '.')
                    mp[s.substr(i+1)] += n;
        }
        vector<string> ans;
        for(auto p : mp)
            ans.push_back(to_string(p.second) + " " + p.first);
        return ans;
    }
};
