#define fi first
#define se second
#define pb push_back
typedef pair<int,char> pic;

class Solution {
public:
    string ans;
    int cnt[26];
    string reorganizeString(string s) {
        int n = s.length();
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]-'a']++;
        priority_queue<pic> heap;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i])
                heap.push(pic(cnt[i],'a'+i));
        char last;
        pic temp = heap.top();
        heap.pop();
        last = temp.se;
        ans.pb(temp.se);
        if(--temp.fi)
            heap.push(temp);
        while(!heap.empty()) {
            temp = heap.top();
            heap.pop();
            if(temp.se != last) {
                last = temp.se;
                ans.pb(temp.se);
                if(--temp.fi)
                    heap.push(temp);
            }
            else {
                if(heap.empty())
                    return "";
                pic temp2 = heap.top();
                heap.pop();
                last = temp2.se;
                ans.pb(temp2.se);
                if(--temp2.fi)
                    heap.push(temp2);
                heap.push(temp);
            }
        }
        return ans;
    }
};