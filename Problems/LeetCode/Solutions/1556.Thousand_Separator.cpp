class Solution {
public:
    string thousandSeparator(int n) {
        vector<int> v;
        while(n) {
            v.push_back(n%10);
            n /= 10;
        }
        if(v.empty())
            v.push_back(0);
        reverse(v.begin(),v.end());
        n = v.size();
        int rem = n;
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            ans.push_back('0'+v[i]);
            rem--;
            if(rem > 0 && rem%3 == 0)
                ans.push_back('.');
        }
        return ans;
    }
};