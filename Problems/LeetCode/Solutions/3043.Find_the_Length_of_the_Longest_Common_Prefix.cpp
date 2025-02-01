class Solution {
public:
    map<int,int> mp;
    void update(int x, int bmask) {
        while(x) {
            mp[x] |= bmask;
            x /= 10;
        }
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int x : arr1)
            update(x, 1);
        for(int x : arr2)
            update(x, 2);
        for(auto it = mp.rbegin() ; it != mp.rend() ; it++)
            if(it->second == 3)
                return to_string(it->first).length();
        return 0;
    }
};