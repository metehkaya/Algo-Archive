class TimeMap {
public:
    map<string,map<int,string>> vals;
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        vals[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        auto it1 = vals.find(key);
        if(it1 == vals.end())
            return "";
        auto it2 = vals[key].upper_bound(timestamp);
        if(it2 == vals[key].begin())
            return "";
        it2--;
        return it2->second;
    }
};