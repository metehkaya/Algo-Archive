class Solution {
public:
    int n;
    int f(int u , int x , vector<bool>& mark) {
        if(u > n)
            return 0;
        x = mark[u] ? !x : x;
        return f(2*u,x,mark) + f(2*u+1,x,mark) + x;
    }
    int numberOfNodes(int n, vector<int>& queries) {
        this->n = n;
        vector<bool> mark(n+1,false);
        for(int q : queries)
            mark[q] = !mark[q];
        return f(1,0,mark);
    }
};
