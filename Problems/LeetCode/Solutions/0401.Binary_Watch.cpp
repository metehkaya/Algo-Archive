class Solution {
public:
    int cnt(int x) {
        int res = 0;
        while(x) {
            res += x%2;
            x /= 2;
        }
        return res;
    }
    vector<string> readBinaryWatch(int n) {
        vector<string> ans;
        for( int h = 0 ; h < 12 ; h++ )
            for( int m = 0 ; m < 60 ; m++ )
                if(cnt(h) + cnt(m) == n) {
                    if(m >= 10)
                        ans.push_back(to_string(h)+":"+to_string(m));
                    else
                        ans.push_back(to_string(h)+":"+"0"+to_string(m));
                }
        return ans;
    }
};