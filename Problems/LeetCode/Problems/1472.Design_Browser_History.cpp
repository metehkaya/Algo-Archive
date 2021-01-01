class BrowserHistory {
public:
    int n,curr;
    vector<string> v;
    BrowserHistory(string home) {
        n = 1;
        curr = 0;
        v.push_back(home);
    }
    void visit(string url) {
        v.resize(curr+1);
        v.push_back(url);
        n = (++curr) + 1;
    }
    string back(int steps) {
        curr = max(curr-steps,0);
        return v[curr];
    }
    string forward(int steps) {
        curr = min(curr+steps,n-1);
        return v[curr];
    }
};