class Solution {
public:
    string digitSum(string s, int k) {
        int len = s.length();
        if(len <= k)
            return s;
        string t = "";
        for( int i = 0 ; i < len ; i += k ) {
            int sum = 0;
            for( int j = i ; j < min(i+k,len) ; j++ )
                sum += s[j]-'0';
            t += std::to_string(sum);
        }
        return digitSum(t,k);
    }
};
