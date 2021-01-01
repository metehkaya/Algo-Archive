class Solution {
public:
    vector<int> transformArray(vector<int>& ar) {
        int n = ar.size();
        bool changed;
        do {
            changed = false;
            vector<int> prev = ar;
            for( int i = 1 ; i < n-1 ; i++ ) {
                if(prev[i] > prev[i-1] && prev[i] > prev[i+1])
                    ar[i] = prev[i] - 1 , changed = true;
                else if(prev[i] < prev[i-1] && prev[i] < prev[i+1])
                    ar[i] = prev[i] + 1 , changed = true;
            }
        }while(changed);
        return ar;
    }
};