class Solution {
public:
    int n;
    vector<int> ans;
    void f(int x) {
        if(x > n)
            return;
        ans.push_back(x);
        for( int i = 0 ; i < 10 ; i++ )
            f(10*x+i);
    }
    vector<int> lexicalOrder(int n) {
        this->n = n;
        for( int i = 1 ; i <= 9 ; i++ )
            f(i);
        return ans;
    }
};
