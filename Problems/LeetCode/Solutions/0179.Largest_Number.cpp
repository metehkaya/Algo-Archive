class Solution {
public:
    static bool comp(int &a, int &b) {
        string s = to_string(a);
        string t = to_string(b);
        return (s+t) > (t+s);
    }
    string largestNumber(vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end(),comp);
        string ans = "";
        for( int i = 0 ; i < n ; i++ )
            ans += to_string(ar[i]);
        if(ans[0] == '0')
            ans = "0";
        return ans;
    }
};