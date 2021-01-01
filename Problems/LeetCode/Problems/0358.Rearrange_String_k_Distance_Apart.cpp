#define fi first
#define se second
typedef pair<int,char> pic;

class Solution {
public:
    string rearrangeString(string s, int k) {
        k = max(k,1);
        int n = s.length();
        vector<int> cnt(256,0);
        for( int i = 0 ; i < n ; i++ )
            cnt[s[i]]++;
        priority_queue<pic> heap;
        for( int i = 0 ; i < 256 ; i++ )
            if(cnt[i])
                heap.push(pic(cnt[i],i));
        string ans = "";
        for( int i = 0 ; i < n ; i++ ) {
            if(i >= k && cnt[ans[i-k]])
                heap.push(pic(cnt[ans[i-k]],ans[i-k]));
            if(heap.empty())
                return "";
            else {
                pic temp = heap.top();
                heap.pop();
                char c = temp.se;
                cnt[c]--;
                ans.push_back(c);
            }
        }
        return ans;
    }
};