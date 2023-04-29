class Solution {
public:
    bool canMeasureWater(int c1, int c2, int t) {
        queue<int> q;
        unordered_set<int> s;
        q.push(c1);
        q.push(c2);
        s.insert(c1);
        s.insert(c2);
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            if(val == t || val+c1 == t || val+c2 == t)
                return true;
            int val_new = abs(c1-val);
            if(s.count(val_new) == 0) {
                q.push(val_new);
                s.insert(val_new);
            }
            val_new = abs(c2-val);
            if(s.count(val_new) == 0) {
                q.push(val_new);
                s.insert(val_new);
            }
        }
        return false;
    }
};
