typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class Solution {
public:
    bool check(vi& a, vi& b) {
        int n = a.size();
        int m = b.size();
        for( int i = 0 , j = 0 ; i < n ; i++ ) {
            while( j < m && b[j] < a[i] )
                j++;
            if(j == m || b[j] > a[i])
                return false;
        }
        return true;
    }
    vi peopleIndexes(vvs& strs) {
        int n = strs.size(), k = 0;
        vvi v(n);
        map<string,int> hashh;
        map<string,int>::iterator mit;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = 0 ; j < strs[i].size() ; j++ ) {
                string str = strs[i][j];
                mit = hashh.find(str);
                if(mit != hashh.end())
                    v[i].push_back(mit->second);
                else
                    v[i].push_back( hashh[str] = (++k) );
            }
            sort( v[i].begin() , v[i].end() );
        }
        vi ans;
        for( int i = 0 ; i < n ; i++ ) {
            bool ok = true;
            for( int j = 0 ; ok && j < n ; j++ )
                if( i != j && check( v[i] , v[j] ) )
                    ok = false;
            if(ok)
                ans.push_back(i);
        }
        return ans;
    }
};