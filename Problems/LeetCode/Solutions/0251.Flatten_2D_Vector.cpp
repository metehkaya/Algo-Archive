class Vector2D {
public:
    int idx1,idx2;
    vector<vector<int>> v;
    Vector2D(vector<vector<int>>& v) {
        this->v = v;
        idx1 = idx2 = 0;
    }
    int next() {
        while(idx1 < v.size() && idx2 == v[idx1].size()) {
            idx1++;
            idx2 = 0;
        }
        int val = v[idx1][idx2];
        idx2++;
        while(idx1 < v.size() && idx2 == v[idx1].size()) {
            idx1++;
            idx2 = 0;
        }
        return val;
    }
    bool hasNext() {
        while(idx1 < v.size() && idx2 == v[idx1].size()) {
            idx1++;
            idx2 = 0;
        }
        return idx1 < v.size();
    }
};