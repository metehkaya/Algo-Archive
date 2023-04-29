class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& ar) {
        int n = ar.size();
        sort(ar.begin(),ar.end());
        long long mass = m;
        for(int x : ar) {
            if(mass < x)
                return false;
            mass += x;
        }
        return true;
    }
};
