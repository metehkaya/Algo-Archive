typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vvi intervalIntersection(vvi& a, vvi& b) {
        int n = a.size();
        int m = b.size();
        vvi ans;
        int i=0,j=0;
        while(i < n && j < m) {
            while(i < n && a[i][1] < b[j][0])
                i++;
            if(i == n)
                break;
            while(j < m && b[j][1] < a[i][0])
                j++;
            if(j == m)
                break;
            int s = max(a[i][0] , b[j][0]);
            int e = min(a[i][1] , b[j][1]);
            if(s <= e) {
                vi v(2);
                v[0] = s;
                v[1] = e;
                ans.push_back(v);
                if(a[i][1] < b[j][1])
                    i++;
                else if(b[j][1] < a[i][1])
                    j++;
                else
                    i++,j++;
            }
        }
        return ans;
    }
};