#define fi first
#define se second
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

class MovieRentingSystem {
public:
    set<pii> renteds;
    map<pi,int> price;
    map<int,set<pi>> unrentedCopies;
    MovieRentingSystem(int n, vector<vector<int>>& ar) {
        for( int i = 0 ; i < ar.size() ; i++ ) {
            int s = ar[i][0];
            int m = ar[i][1];
            int p = ar[i][2];
            unrentedCopies[m].insert(pi(p,s));
            price[pi(m,s)] = p;
        }
    }
    vector<int> search(int m) {
        int sz = min((int)unrentedCopies[m].size(),5);
        set<pi>::iterator it = unrentedCopies[m].begin();
        vector<int> ans;
        while(sz--) {
            ans.push_back((*it).se);
            it++;
        }
        return ans;
    }
    void rent(int s, int m) {
        int p = price[pi(m,s)];
        unrentedCopies[m].erase(pi(p,s));
        renteds.insert(pii(p,pi(s,m)));
    }
    void drop(int s, int m) {
        int p = price[pi(m,s)];
        unrentedCopies[m].insert(pi(p,s));
        renteds.erase(pii(p,pi(s,m)));
    }
    vector<vector<int>> report() {
        int sz = min((int)renteds.size(),5);
        set<pii>::iterator it = renteds.begin();
        vector<vector<int>> ans;
        while(sz--) {
            int s = (*it).se.fi;
            int m = (*it).se.se;
            vector<int> add(2);
            add[0] = s;
            add[1] = m;
            ans.push_back(add);
            it++;
        }
        return ans;
    }
};