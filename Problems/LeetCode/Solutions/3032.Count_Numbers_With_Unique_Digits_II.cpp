class Solution {
public:
    int numberCount(int a, int b) {
        int ans = 0;
        for( int i = a ; i <= b ; i++ ) {
            int x = i;
            set<int> s;
            vector<int> v;
            while(x) {
                int d = x%10;
                if(s.count(d))
                    break;
                s.insert(d);
                x /= 10;
            }
            ans += (x == 0);
        }
        return ans;
    }
};
