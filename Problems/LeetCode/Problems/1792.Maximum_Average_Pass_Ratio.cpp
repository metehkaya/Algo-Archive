#define fi first
#define se second
typedef pair<int,int> pi;

double inc(pi a) {
    return (a.fi+1.) / (a.se+1.) - (a.fi / (double)a.se);
}

struct st {
    bool operator()(const pi &x , const pi &y) {
        return inc(x) < inc(y);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& ar, int m) {
        int n = ar.size();
        priority_queue<pi, vector<pi>, st> heap;
        for( int i = 0 ; i < n ; i++ )
            heap.push(pi(ar[i][0],ar[i][1]));
        while(m--) {
            pi temp = heap.top();
            heap.pop();
            int x = temp.fi;
            int y = temp.se;
            heap.push(pi(x+1,y+1));
        }
        double ans = 0;
        while(!heap.empty()) {
            pi temp = heap.top();
            heap.pop();
            int x = temp.fi;
            int y = temp.se;
            ans += (double)x/y;
        }
        return ans/n;
    }
};