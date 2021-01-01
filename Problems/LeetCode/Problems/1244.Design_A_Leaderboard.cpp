class Leaderboard {
public:
    map<int,int> scores;
    Leaderboard() {}
    void addScore(int id, int score) {
        scores[id] += score;
    }
    int top(int k) {
        vector<int> v;
        map<int,int>::iterator it;
        for( it = scores.begin() ; it != scores.end() ; it++ )
            v.push_back(it->second);
        sort(v.begin() , v.end());
        int n = v.size() , ans = 0;
        for( int i = n-k ; i < n ; i++ )
            ans += v[i];
        return ans;
    }
    void reset(int id) {
        scores.erase(id);
    }
};