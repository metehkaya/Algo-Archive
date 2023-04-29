class Solution {
public:
    struct pt { 
        double x = 0, y = 0; 
        double to(const pt &o) const {
            return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));    
        }
    };
    vector<double> circleFrom(const pt& A, const pt& B, const pt& C) {
        double bx = B.x - A.x, by = B.y - A.y, cx = C.x - A.x, cy = C.y - A.y;
        double b = bx * bx + by * by;
        double c = cx * cx + cy * cy;
        double d = bx * cy - by * cx;
        pt I = { (cy * b - by * c) / (2 * d) + A.x , (bx * c - cx * b) / (2 * d) + A.y };
        return {I.x, I.y, I.to(A)};
    }
    vector<double> centerAndRadius(const vector<pt> &b) {
        if(b.size() == 0)
            return {0,0,0};
        if(b.size() == 1)
            return {b[0].x, b[0].y, 0};
        if(b.size() == 2)
            return {(b[0].x + b[1].x) / 2, (b[0].y + b[1].y) / 2, b[0].to(b[1]) / 2};
        return circleFrom(b[0], b[1], b[2]);
    }
    vector<double> outerTrees(vector<vector<int>>& trees, int i = 0, vector<pt> b = {}) {
        if(i == 0) {
            srand(time(nullptr));
            random_shuffle(begin(trees),end(trees));
        }
        if(i == trees.size() || b.size() == 3)
            return centerAndRadius(b);
        auto c = outerTrees(trees, i+1, b);
        auto p = pt{(double)trees[i][0], (double)trees[i][1]};
        if(p.to(pt{c[0], c[1]}) <= c[2])
            return c;
        b.push_back(p);
        return outerTrees(trees, i+1, b);
    }
};
