class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> total;
        int n = messages.size();
        int best = 0;
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            string s = messages[i];
            int cnt = 0;
            int len = s.length();
            for( int j = 0 ; j < len ; j++ )
                if(s[j] == ' ')
                    cnt++;
            total[senders[i]] += cnt+1;
            int curr = total[senders[i]];
            if(curr > best || (curr == best && senders[i] > ans)) {
                ans = senders[i];
                best = curr;
            }
        }
        return ans;
    }
};
