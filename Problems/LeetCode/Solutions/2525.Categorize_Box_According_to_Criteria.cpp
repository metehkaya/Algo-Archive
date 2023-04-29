class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = length;
        vol *= width;
        vol *= height;
        int mx = max(max(length,width),height);
        bool bulky = (mx >= (int)1e4 or vol >= (int)1e9);
        bool heavy = (mass >= 100);
        if(heavy && bulky)
            return "Both";
        else if(heavy && !bulky)
            return "Heavy";
        else if(!heavy && bulky)
            return "Bulky";
        else
            return "Neither";
    }
};
