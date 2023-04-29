typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vii points;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        for( int i = 0 ; i < 4 ; i++ )
            for( int j = i+1 ; j < 4 ; j++ )
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    return false;
        int perm[4] = {0,1,2,3};
        do {
            vii v;
            for( int i = 0 ; i < 4 ; i++ )
                v.push_back(points[perm[i]]);
            bool ok = true;
            int minDist = INT_MAX;
            int maxDist = INT_MIN;
            for( int i = 0 ; i < 4 ; i++ ) {
                int j = (i+1)%4;
                int k = (j+1)%4;
                int dx1 = v[j][0]-v[i][0];
                int dy1 = v[j][1]-v[i][1];
                int dx2 = v[k][0]-v[j][0];
                int dy2 = v[k][1]-v[j][1];
                if(dx1*dx2+dy1*dy2 != 0)
                    ok = false;
                int dist = dx1*dx1+dy1*dy1;
                minDist = min(minDist,dist);
                maxDist = max(maxDist,dist);
            }
            if(minDist != maxDist)
                ok = false;
            if(ok)
                return true;
        }while(next_permutation(perm,perm+4));
        return false;
    }
};