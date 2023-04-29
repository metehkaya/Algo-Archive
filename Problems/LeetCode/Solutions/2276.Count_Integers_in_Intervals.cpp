class CountIntervals {
public:
    int ans;
    map<int,int> hashh;
    map<int,int>::iterator mit;
    CountIntervals() {
        ans = 0;
    }
    void add(int left, int right) {
        mit = hashh.upper_bound(left);
        if(mit != hashh.begin()) {
            mit--;
            int lower = (*mit).first;
            int upper = (*mit).second;
            if(upper >= left) {
                ans -= upper-lower+1;
                left = min(left,lower);
                right = max(right,upper);
                hashh.erase(mit);
            }
        }
        while(true) {
            mit = hashh.lower_bound(left);
            if(mit == hashh.end() || (*mit).first > right)
                break;
            int lower = (*mit).first;
            int upper = (*mit).second;
            ans -= upper-lower+1;
            right = max(right,upper);
            hashh.erase(mit);
        }
        hashh[left] = right;
        ans += right-left+1;
    }
    int count() {
        return ans;
    }
};
