class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> q;
        int n = s.length();
        int r = 0 , d = 0;
        int cntr = 0 , cntd = 0;
        for( int i = 0 ; i < n ; i++ ) {
            q.push(i);
            if(s[i] == 'R')
                cntr++;
            else
                cntd++;
        }
        while(cntr > 0 && cntd > 0) {
            int id = q.front();
            q.pop();
            if(s[id] == 'R') {
                if(r)
                    r-- , cntr--;
                else {
                    d++;
                    q.push(id);
                }
            }
            else {
                if(d)
                    d-- , cntd--;
                else {
                    r++;
                    q.push(id);
                }
            }
        }
        return (cntr > 0) ? "Radiant" : "Dire";
    }
};
