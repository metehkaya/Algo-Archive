class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> hashh;
        int n = strs.size();
         map<vector<int>,vector<string>>::iterator mit;
        for( int i = 0 ; i < n ; i++ ) {
            vector<int> cnt(26,0);
            string str = strs[i];
            int len = str.length();
            for( int i = 0 ; i < len ; i++ )
                cnt[str[i]-'a']++;
            mit = hashh.find(cnt);
            if(mit != hashh.end())
                mit->second.push_back(str);
            else {
                vector<string> v;
                v.push_back(str);
                hashh.insert(make_pair(cnt,v));
            }
        }
        vector<vector<string>> ans;
        for( mit = hashh.begin() ; mit != hashh.end() ; mit++ )
            ans.push_back(mit->second);
        return ans;
    }
};