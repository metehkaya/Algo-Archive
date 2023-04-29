class LogSystem {
public:
    map<string,int> mp;
    LogSystem() {}
    void put(int id, string timestamp) {
        mp[timestamp] = id;
    }
    vector<int> retrieve(string s, string e, string granularity) {
        if(granularity == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if(granularity == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if(granularity == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if(granularity == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if(granularity == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        vector<int> ans;
        auto start = mp.lower_bound(s), end = mp.upper_bound(e);
        for( auto iter = start ; iter != end ; iter++ )
            ans.push_back(iter->second);
        return ans;
    }
};
