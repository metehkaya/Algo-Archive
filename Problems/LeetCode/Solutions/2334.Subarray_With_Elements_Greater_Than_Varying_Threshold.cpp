#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pi;

class Solution {
public:
    int validSubarraySize(vector<int>& ar, int threshold) {
        int n = ar.size();
        vector<pi> queries;
        for( int k = n ; k >= 1 ; k-- )
            queries.push_back(pi(k,threshold/k+1));
        vector<pi> arr;
        for( int i = 0 ; i < n ; i++ )
            arr.pb(pi(ar[i],i));
        sort(arr.begin(),arr.end());
        set<int> myset;
        myset.insert(-1);
        myset.insert(n);
        set<int> samevalue;
        vector<pi> intervals;
        for( int i = 0 ; i < n ; i++ ) {
            pi p = arr[i];
            int val = p.fi;
            int idx = p.se;
            set<int>::iterator it = myset.lower_bound(idx);
            it--;
            int ll = (*it);
            it = myset.upper_bound(idx);
            int rr = (*it);
            myset.insert(idx);
            intervals.pb(pi(val,rr-ll-1));
        }
        int minLen = n+1;
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            pi p = intervals[i];
            int val = p.fi;
            int len = p.se;
            while(j < n && queries[j].se <= val)
                minLen = queries[j++].fi;
            if(len >= minLen)
                return len;
        }
        return -1;
    }
};
