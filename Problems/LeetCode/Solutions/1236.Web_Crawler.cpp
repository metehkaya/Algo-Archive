class Solution {
public:
    string domain;
    vector<string> ans;
    unordered_set<string> myset;
    string get_domain(string& s) {
        int idx = s.find_first_of('/',7);
        if(idx == string::npos)
            idx = s.length();
        return s.substr(7,idx-7);
    }
    void dfs(string& url , HtmlParser& htmlParser) {
        myset.insert(url);
        ans.push_back(url);
        auto urls = htmlParser.getUrls(url);
        for(string& s : urls) {
            string s_domain = get_domain(s);
            if(s_domain == domain and myset.find(s) == myset.end()) {
                myset.insert(s);
                dfs(s,htmlParser);
            }
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        domain = get_domain(startUrl);
        dfs(startUrl, htmlParser);
        return ans;
    }
};
