class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> pw3;
        pw3.push_back(1);
        for( int i = 1 ; i <= 14 ; i++ )
            pw3.push_back(3*pw3[i-1]);
        int mx = 0;
        for( int i = 14 ; i >= 0 ; i-- ) {
            int cnt = 0;
            while(n >= pw3[i]) {
                cnt++;
                n -= pw3[i];
            }
            if(cnt == 2)
                return false;
        }
        return true;
    }
};