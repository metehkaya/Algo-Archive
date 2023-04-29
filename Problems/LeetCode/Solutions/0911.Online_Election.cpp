typedef pair<int,int> pi;

class TopVotedCandidate {
public:
    map<int,int> best;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size() , mx = 0;
        vector<int> cnt(n,0);
        for( int i = 0 ; i < n ; i++ ) {
            int p = persons[i];
            int t = times[i];
            if(++cnt[p] >= mx) {
                mx = cnt[p];
                best[t] = p;
            }
        }
    }
    int q(int t) {
        auto it = best.upper_bound(t);
        it--;
        return it->second;
    }
};