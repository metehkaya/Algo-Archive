class Solution {
public:
    string smallestNumber(long long n) {
        vector<int> v;
        for( int i = 9 ; i >= 2 ; i-- )
            while(n%i == 0) {
                n /= i;
                v.push_back(i);
            }
        if(n > 1)
            return "-1";
        if(v.empty())
            v.push_back(1);
        reverse(v.begin(), v.end());
        string ans = "";
        for(int x : v)
            ans.push_back('0'+x);
        return ans;
    }
};
