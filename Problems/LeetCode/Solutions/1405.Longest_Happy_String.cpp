#define fi first
#define se second
typedef pair<int,char> pic;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pic> Q;
        if(a > 0)
            Q.push(pic(a,'a'));
        if(b > 0)
            Q.push(pic(b,'b'));
        if(c > 0)
            Q.push(pic(c,'c'));
        pic prev = Q.top();
        Q.pop();
        if(prev.fi >= 2) {
            prev.fi -= 2;
            ans.push_back(prev.se);
            ans.push_back(prev.se);
        }
        else {
            prev.fi--;
            ans.push_back(prev.se);
        }
        while(!Q.empty()) {
            pic curr = Q.top();
            Q.pop();
            if(curr.fi - prev.fi >= 2) {
                curr.fi -= 2;
                ans.push_back(curr.se);
                ans.push_back(curr.se);
            }
            else {
                curr.fi--;
                ans.push_back(curr.se);
            }
            if(prev.fi)
                Q.push(prev);
            prev = curr;
        }
        return ans;
    }
};