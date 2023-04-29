class Solution {
public:
    bool checkPossibility(vector<int>& ar) {
        int n = ar.size();
        if(n <= 2)
            return true;
        vector<bool> pref(n);
        pref[0] = true;
        for( int i = 1 ; i < n ; i++ )
            pref[i] = pref[i-1] && (ar[i] >= ar[i-1]);
        vector<bool> suff(n);
        suff[n-1] = true;
        for( int i = n-2 ; i >= 0 ; i-- )
            suff[i] = suff[i+1] && (ar[i] <= ar[i+1]);
        if(pref[n-2] || suff[1])
            return true;
        for( int i = 1 ; i < n-1 ; i++ )
            if(pref[i-1] && suff[i+1] && ar[i-1] <= ar[i+1])
                return true;
        return false;
    }
};