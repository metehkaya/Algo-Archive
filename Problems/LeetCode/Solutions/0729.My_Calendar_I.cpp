class MyCalendar {
public:
    int n;
    vector<int> s,e;
    MyCalendar() {
        n = 0;
    }
    bool book(int start, int end) {
        for( int i = 0 ; i < n ; i++ ) {
            int ss = s[i];
            int ee = e[i];
            if(ee <= start || end <= ss)
                continue;
            return false;
        }
        n++;
        s.push_back(start);
        e.push_back(end);
        return true;
    }
};