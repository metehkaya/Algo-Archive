class ParkingSystem {
public:
    int cnt[3];
    ParkingSystem(int big, int medium, int small) {
        cnt[0] = big;
        cnt[1] = medium;
        cnt[2] = small;
    }
    bool addCar(int i) {
        if(cnt[--i]) {
            cnt[i]--;
            return true;
        }
        return false;
    }
};