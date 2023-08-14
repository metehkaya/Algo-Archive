/*
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> v, ans;
        for(vector<Interval>& worker : schedule)
            for(Interval& i : worker)
                v.push_back(i);
        sort(v.begin(), v.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });
        int last_r = INT_MIN;
        for(Interval& i : v) {
            if(last_r < i.start and last_r != INT_MIN)
                ans.push_back(Interval(last_r,i.start));
            last_r = max(last_r,i.end);
        }
        return ans;
    }
};
