class Solution {
public:
    vector<string> invalidTransactions(vector<string>& ar) {
        int n = ar.size();
        string str[n][4];
        int minute[n];
        for( int i = 0 ; i < n ; i++ ) {
            string s = ar[i];
            for( int j = 0 ; j < 3 ; j++ ) {
                int idx = s.find(",");
                string t = s.substr(0,idx);
                str[i][j] = t;
                s = s.substr(idx+1);
            }
            str[i][3] = s;
            minute[i] = stoi(str[i][1]);
        }
        vector<string> ans;
        for( int i = 0 ; i < n ; i++ ) {
            bool add = (str[i][2].length() >= 4);
            for( int j = 0 ; j < n ; j++ )
                if(i != j)
                    if(abs(minute[i]-minute[j]) <= 60 && str[i][0] == str[j][0] && str[i][3] != str[j][3])
                        add = true;
            if(add)
                ans.push_back(ar[i]);
        }
        return ans;
    }
};