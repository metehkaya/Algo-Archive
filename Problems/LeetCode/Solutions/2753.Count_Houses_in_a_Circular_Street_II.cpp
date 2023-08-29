class Street {
public:
    Street(vector<int> doors);
    void closeDoor();
    bool isDoorOpen();
    void moveRight();
 };
 
class Solution {
public:
    int houseCount(Street* street, int k) {
        int id = -1 , ans;
        for( int i = 0 ; i < 2*k ; i++ ) {
            if(street->isDoorOpen()) {
                if(id == -1)
                    id = i;
                else {
                    ans = i-id;
                    street->closeDoor();
                }
            }
            street->moveRight();
        }
        return ans;
    }
};
