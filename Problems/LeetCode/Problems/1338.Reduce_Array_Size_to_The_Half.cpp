class Solution {
public:
    int minSetSize(vector<int>& ar) {
        int n = ar.size();
        int least = (n+1) / 2;
        map<int,int> cnts;
        for( int i = 0 ; i < n ; i++ )
            cnts[ar[i]]++;
        vector<int> v;
        for( auto it = cnts.begin() ; it != cnts.end() ; it++ )
            v.push_back(it->second);
        sort( v.begin() , v.end() );
        int sum = 0;
        for( int i = v.size()-1 ; i >= 0 ; i-- ) {
            sum += v[i];
            if(sum >= least)
                return v.size()-i;
        }
        return -1;
    }
};