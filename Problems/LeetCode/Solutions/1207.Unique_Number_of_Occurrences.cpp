class Solution {
public:
    bool uniqueOccurrences(vector<int>& ar) {
        set<int> cnts;
        int n = ar.size();
        sort(ar.begin() , ar.end());
        for( int i = 0 , j = 0 ; i < n ; i = j ) {
            while(j < n && ar[i] == ar[j])
                j++;
            int cnt = j-i;
            if(cnts.find(cnt) != cnts.end())
                return false;
            cnts.insert(cnt);
        }
        return true;
    }
};