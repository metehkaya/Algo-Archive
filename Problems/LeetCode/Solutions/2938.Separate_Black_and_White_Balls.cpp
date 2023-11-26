class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long ans = 0;
        vector<int> v;
        for( int i = 0 ; i < n ; i++ )
            if(s[i] == '0')
                v.push_back(i);
        for( int i = 0 ; i < v.size() ; i++ )
            ans += v[i]-i;
        return ans;
    }
};

