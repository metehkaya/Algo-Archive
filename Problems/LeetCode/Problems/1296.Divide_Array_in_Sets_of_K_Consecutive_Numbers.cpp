class Solution {
public:
    bool isPossibleDivide(vector<int>& ar, int k) {
        map<int,int> cnts;
        int n = ar.size();
        for( int i = 0 ; i < n ; i++ )
            cnts[ar[i]]++;
        for( auto it = cnts.begin() ; it != cnts.end() ; it++ ) {
            int x = it->first;
            int y = it->second;
            if(y)
                for( int i = x+1 ; i < x+k ; i++ ) {
                    auto it2 = cnts.find(i);
                    if(it2 == cnts.end() or it2->second < y)
                        return false;
                    cnts[i] -= y;
                }
            cnts[x] = 0;
        }
        return true;
    }
};