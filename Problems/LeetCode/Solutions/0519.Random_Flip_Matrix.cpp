class Solution {
public:
    int n,m,sz;
    set<int> s;
    Solution(int n, int m) {
        this->n = n;
        this->m = m;
        this->sz = n*m;
    }
    vector<int> flip() {
        int idx = rand()%sz;
        while(s.find(idx) != s.end())
            idx = rand()%sz;
        s.insert(idx);
        return {idx/m,idx%m};
    }
    void reset() {
        s.clear();
    }
};
