class FrequencyTracker {
public:
    map<int,int> mp;
    multiset<int> freqs;
    FrequencyTracker() {}
    void add(int number) {
        int f = mp[number];
        if(f > 0) {
            auto it = freqs.find(f);
            freqs.erase(it);
        }
        mp[number] = f+1;
        freqs.insert(f+1);
    }
    void deleteOne(int number) {
        int f = mp[number];
        if(f > 0) {
            auto it = freqs.find(f);
            freqs.erase(it);
            mp[number] = f-1;
            if(f-1 != 0)
                freqs.insert(f-1);
        }
    }
    bool hasFrequency(int frequency) {
        return freqs.find(frequency) != freqs.end();
    }
};
