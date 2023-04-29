#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pi> ar;
        int n = arr.size();
        for( int i = 0 ; i < n ; i++ ) {
            int cnt = 0;
            int num = arr[i];
            while(num) {
                cnt++;
                num -= (num & (-num));
            }
            ar.push_back( pi( cnt , arr[i] ) );
        }
        sort( ar.begin() , ar.end() );
        vector<int> ans;
        for( int i = 0 ; i < n ; i++ )
            ans.push_back( ar[i].se );
        return ans;
    }
};