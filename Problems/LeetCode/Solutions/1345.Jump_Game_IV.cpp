#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int minJumps(vector<int>& ar) {
        int n = ar.size();
        map<int,vector<int>> indices;
        for( int i = 0 ; i < n ; i++ )
            indices[ar[i]].push_back(i);
        queue<pi> Q;
        set<int> used;
        vector<bool> mark(n,false);
        mark[0] = true;
        Q.push( pi(0,0) );
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            int index = temp.fi;
            int dist = temp.se;
            if(index == n-1)
                return dist;
            if(index > 0 && !mark[index-1]) {
                mark[index-1] = true;
                Q.push( pi( index-1 , dist+1 ) );
            }
            if(index+1 < n && !mark[index+1]) {
                mark[index+1] = true;
                Q.push( pi( index+1 , dist+1 ) );
            }
            if(used.find(ar[index]) == used.end()) {
                used.insert(ar[index]);
                vector<int> v = indices[ar[index]];
                for( int i = 0 ; i < v.size() ; i++ ) {
                    int index2 = v[i];
                    if(!mark[index2]) {
                        mark[index2] = true;
                        Q.push( pi( index2 , dist+1 ) );
                    }
                }
            }
        }
        return -1;
    }
};