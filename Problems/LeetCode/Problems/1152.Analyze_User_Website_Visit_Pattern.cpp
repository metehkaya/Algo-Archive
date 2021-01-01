struct pack {
    int t;
    string u,w;
    pack(string _u , int _t , string _w) {
        u = _u;
        t = _t;
        w = _w;
    }
};

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        vector<pack> ar;
        int n = username.size();
        for( int i = 0 ; i < n ; i++ ) {
            pack p(username[i],timestamp[i],website[i]);
            ar.push_back(p);
        }
        sort(ar.begin() , ar.end() , [](pack a , pack b) {
            if(a.u != b.u)
                return a.u < b.u;
            return a.t < b.t;
        });
        map<vector<string>,int> cnt;
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i].u == ar[j].u)
                j++;
            set<vector<string>> s;
            for( int a = i ; a < j-2 ; a++ )
                for( int b = a+1 ; b < j-1 ; b++ )
                    for( int c = b+1 ; c < j ; c++ ) {
                        vector<string> v(3);
                        v[0] = ar[a].w;
                        v[1] = ar[b].w;
                        v[2] = ar[c].w;
                        s.insert(v);
                    }
            for( auto it = s.begin() ; it != s.end() ; it++ )
                cnt[(*it)]++;
        }
        int best = 0;
        vector<string> ans(3,"");
        for( auto it = cnt.begin() ; it != cnt.end() ; it++ )
            if(it->second > best)
                ans = it->first , best = it->second;
        return ans;
    }
};