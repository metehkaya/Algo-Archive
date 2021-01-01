class Solution {
public:
    bool checkIfExist(vector<int>& ar) {
        set<int> var;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ ) {
            if(var.find(2*ar[i]) != var.end())
                return true;
            if(ar[i] % 2 == 0 && var.find(ar[i]/2) != var.end())
                return true;
            var.insert(ar[i]);
        }
        return false;
    }
};