class StockPrice {
public:
    map<int,int> mp;
    multiset<int> st;
    StockPrice() {}
    void update(int t, int p) {
        map<int,int>::iterator it = mp.find(t);
        if(it != mp.end()) {
            int old = (*it).second;
            multiset<int>::iterator sit = st.find(old);
            st.erase(sit);
            st.insert(p);
            mp[t] = p;
        }
        else {
            mp[t] = p;
            st.insert(p);
        }
    }
    int current() {
        map<int,int>::iterator it = mp.end();
        it--;
        return (*it).second;
    }
    int maximum() {
        multiset<int>::iterator sit = st.end();
        sit--;
        return (*sit);
    }
    int minimum() {
        multiset<int>::iterator sit = st.begin();
        return (*sit);
    }
};