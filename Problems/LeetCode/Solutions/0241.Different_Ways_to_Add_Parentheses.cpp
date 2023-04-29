class Solution {
public:
    void f(int l , int r , string& s , vector<int>& v) {
        for( int i = l ; i < r ; i++ )
            if(s[i] == '+' or s[i] == '-' or s[i] == '*') {
                vector<int> a,b;
                f(l,i,s,a);
                f(i+1,r,s,b);
                for(int x : a)
                    for(int y : b) {
                        if(s[i] == '+')
                            v.push_back(x+y);
                        else if(s[i] == '-')
                            v.push_back(x-y);
                        else
                            v.push_back(x*y);
                    }
            }
        if(v.empty())
            v.push_back(stoi(s.substr(l,r-l)));
    }
    vector<int> diffWaysToCompute(string s) {
        int n = s.length();
        vector<int> ans;
        f(0,n,s,ans);
        return ans;
    }
};
