#define fi first
#define se second
#define pb push_back

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        int n = keyTime.size();
        vector<string> ans;
        map<string,vector<int>> times;
        for( int i = 0 ; i < n ; i++ ) {
            string s = keyName[i];
            string t = keyTime[i];
            int h = 10*(t[0]-'0')+(t[1]-'0');
            int m = 10*(t[3]-'0')+(t[4]-'0');
            times[s].pb(60*h+m);
        }
        map<string,vector<int>>:: iterator it;
        for( it = times.begin() ; it != times.end() ; it++ ) {
            string s = it->fi;
            vector<int> v = it->se;
            sort(v.begin(),v.end());
            bool ok = false;
            int sz = v.size();
            for( int i = 0 ; i <= sz-3 ; i++ )
                if(v[i+2] <= v[i]+60)
                    ok = true;
            if(ok)
                ans.pb(s);
        }
        return ans;
    }
};