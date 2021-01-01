class Solution {
public:
    void check(string& time, string& ch, string& ans, string curr) {
        if(curr.length() == 4) {
            string hour = curr.substr(0,2);
            string mins = curr.substr(2,2);
            if(hour < "24" && mins < "60") {
                string tmp = hour + ":" + mins;
                if(ans == "99:99")
                    ans = tmp;
                else if(ans < time && (tmp < ans || tmp > time))
                    ans = tmp;
                else if(ans > time && (tmp < ans && tmp > time))
                    ans = tmp;
            }
            return;
        }
        for( int i = 0 ; i < 4 ; i++ )
            check(time,ch,ans,curr+ch[i]);
    }
    string nextClosestTime(string time) {
        string ch = time.substr(0,2) + time.substr(3,2);
        string ans = "99:99";
        check(time,ch,ans,"");
        return ans;
    }
};