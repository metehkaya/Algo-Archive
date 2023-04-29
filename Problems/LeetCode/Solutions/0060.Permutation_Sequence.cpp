class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n);
        fact[0] = 1;
        for( int i = 1 ; i < n ; i++ )
            fact[i] = fact[i-1] * i;
        k--;
        string ans = "";
        vector<bool> mark(n,false);
        for( int i = n-1 ; i >= 0 ; i-- )
            for( int j = 0 ; j < n ; j++ )
                if(!mark[j]) {
                    if(k < fact[i]) {
                        mark[j] = true;
                        ans.push_back('1'+j);
                        break;
                    }
                    k -= fact[i];
                }
        return ans;
    }
};