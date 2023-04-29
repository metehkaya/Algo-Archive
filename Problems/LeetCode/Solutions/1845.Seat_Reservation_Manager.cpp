class SeatManager {
public:
    set<int> mys;
    SeatManager(int n) {
        for( int i = 1 ; i <= n ; i++ )
            mys.insert(i);
    }
    int reserve() {
        set<int>::iterator it = mys.begin();
        int res = (*it);
        mys.erase(it);
        return res;
    }
    void unreserve(int seatNumber) {
        mys.insert(seatNumber);
    }
};