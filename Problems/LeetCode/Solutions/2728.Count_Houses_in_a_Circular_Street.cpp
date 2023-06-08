class Street {
public:
    Street(vector<int> doors);
    void openDoor();
    void closeDoor();
    bool isDoorOpen();
    void moveRight();
    void moveLeft();
};

class Solution {
public:
    int houseCount(Street* street, int k) {
        for( int i = 0 ; i < k ; i++ ) {
            street->openDoor();
            street->moveRight();
        }
        street->closeDoor();
        int ans = 0;
        do {
            street->moveRight();
            ans++;
        } while(street->isDoorOpen());
        return ans;
    }
};
