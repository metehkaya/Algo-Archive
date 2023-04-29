class OrderedStream {
public:
    int n;
    int idx;
    vector<string> v;
    OrderedStream(int n) {
        idx = 0;
        this->n = n;
        v.clear();
        v.resize(n,"");
    }
    vector<string> insert(int id, string value) {
        v[id-1] = value;
        vector<string> ans;
        while(idx < n)
            if(!v[idx].empty())
                ans.push_back(v[idx++]);
            else
                break;
        return ans;
    }
};