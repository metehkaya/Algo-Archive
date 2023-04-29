class Solution {
public:
    string reformatDate(string s) {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int len = s.length();
        string d,m,y;
        int i = 0;
        while(s[i] >= '0' && s[i] <= '9')
            d.push_back(s[i++]);
        while(s[i] != ' ')
            i++;
        i++;
        while(s[i] != ' ')
            m.push_back(s[i++]);
        i++;
        while(i < len)
            y.push_back(s[i++]);
        string ans = y + "-";
        for( int i = 0 ; i < 12 ; i++ )
            if(months[i] == m) {
                int num = i+1;
                if(num < 10)
                    ans.push_back('0');
                string w = "";
                while(num) {
                    w.push_back('0' + num%10);
                    num /= 10;
                }
                reverse(w.begin(),w.end());
                ans += w;
                break;
            }
        ans += "-";
        if(d.length() == 1)
            ans.push_back('0');
        ans += d;
        return ans;
    }
};