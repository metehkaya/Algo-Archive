class MyCalendarTwo {
public:
    vector<pair<int,int>> ar1;
    vector<pair<int,int>> ar2;
    MyCalendarTwo() {
        ar1.clear();
        ar2.clear();
    }
    bool book(int start, int end) {
        for( int i = 0 ; i < ar2.size() ; i++ ) {
            int s = ar2[i].first;
            int e = ar2[i].second;
            if(s >= end || start >= e)
                continue;
            return false;
        }
        for( int i = 0 ; i < ar1.size() ; i++ ) {
            int s = max(start,ar1[i].first);
            int e = min(end,ar1[i].second);
            if(s < e)
                ar2.push_back(make_pair(s,e));
        }
        ar1.push_back(make_pair(start,end));
        return true;
    }
};