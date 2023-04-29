class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v;
        for( int i = 1 ; i <= n ; i++ )
            v.push_back(to_string(i));
        while(n > 1) {
            for( int i = 0 ; i < n/2 ; i++ )
                v[i] = "(" + v[i] + "," + v[n-1-i] + ")";
            n /= 2;
        }
        return v[0];
    }
};
