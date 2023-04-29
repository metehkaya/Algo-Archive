#define fi first
#define se second
typedef pair<int,int> pi;

class MyCalendarThree {
public:
    vector<pi> v;
    MyCalendarThree() {}
    int book(int start, int end) {
        v.push_back(pi(start,1));
        v.push_back(pi(end,-1));
        sort(v.begin(),v.end());
        int curr = 0 , ans = 0;
        for(pi p : v) {
            curr += p.se;
            ans = max(ans,curr);
        }
        return ans;
    }
};
