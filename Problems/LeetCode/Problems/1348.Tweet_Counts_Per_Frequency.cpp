class TweetCounts {
public:
    map<string,vector<int>> times;
    TweetCounts() {}
    void recordTweet(string name, int t) {
        times[name].push_back(t);
    }
    vector<int> getTweetCountsPerFrequency(string freq, string name, int st, int et) {
        int f;
        if(freq == "minute")
            f = 60;
        else if(freq == "hour")
            f = 60*60;
        else
            f = 60*60*24;
        int len = (et-st)/f + 1;
        vector<int> ans(len,0);
        auto it = times.find(name);
        if(it != times.end()) {
            vector<int> v = it->second;
            int sz = v.size();
            for( int i = 0 ; i < sz ; i++ )
                if( v[i] >= st && v[i] <= et ) {
                    int t = (v[i]-st)/f;
                    ans[t]++;
                }
        }
        return ans;
    }
};