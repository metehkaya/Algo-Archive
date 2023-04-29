class Solution {
public:
    string minimizeError(vector<string>& ar, int target) {
        int n = ar.size();
        int sumf = 0;
        vector<double> v;
        for( int i = 0 ; i < n ; i++ ) {
            double d = stod(ar[i]);
            int x = floor(d);
            int y = ceil(d);
            v.push_back(y-d);
            sumf += x;
        }
        if(target < sumf)
            return "-1";
        double ans = 0;
        sort(v.begin(),v.end());
        for( int i = 0 ; i < n ; i++ )
            if(v[i] != 0) {
                if(sumf < target) {
                    sumf++;
                    ans += v[i];
                }
                else
                    ans += 1-v[i];
            }
        if(sumf < target)
            return "-1";
        string s = to_string(ans);
        int idx = 0;
        while(s[idx] != '.')
            idx++;
        return s.substr(0,idx+4);
    }
};