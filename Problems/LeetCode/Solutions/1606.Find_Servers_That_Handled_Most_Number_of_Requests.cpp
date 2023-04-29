#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;
typedef pair<pi,int> pii;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& s, vector<int>& t) {
        int n = s.size();
        vector<int> ans;
        vector<int> cnt(k,0);
        set<pi> fin;
        set<int> avail;
        for( int i = 0 ; i < k ; i++ )
            avail.insert(i);
        set<int>::iterator it1 = avail.begin();
        set<pi>::iterator it2 = fin.begin();
        for( int i = 0 ; i < n ; i++ ) {
            while(!fin.empty()) {
                it2 = fin.begin();
                int a = it2->fi;
                int b = it2->se;
                if(a <= s[i]) {
                    fin.erase(it2);
                    avail.insert(b);
                }
                else
                    break;
            }
            int idx = i%k;
            if(!avail.empty()) {
                it1 = avail.lower_bound(idx);
                if(it1 != avail.end()) {
                    idx = (*it1);
                    avail.erase(it1);
                    fin.insert(pi(s[i]+t[i],idx));
                    cnt[idx]++;
                }
                else {
                    it1 = avail.begin();
                    idx = (*it1);
                    avail.erase(it1);
                    fin.insert(pi(s[i]+t[i],idx));
                    cnt[idx]++;
                }
            }
        }
        int mostBusy = -1;
        for( int i = 0 ; i < k ; i++ ) {
            if(cnt[i] > mostBusy) {
                ans.clear();
                ans.pb(i);
                mostBusy = cnt[i];
            }
            else if(cnt[i] == mostBusy)
                ans.pb(i);
        }
        return ans;
    }
};