class Solution {
public:
    void update(int x , int n , int add , vector<int>& tree) {
        while(x <= n) {
            tree[x] += add;
            x += (x&(-x));
        }
    }
    int query(int x , vector<int>& tree) {
        int res = 0;
        while(x) {
            res += tree[x];
            x -= (x&(-x));
        }
        return res;
    }
    string minInteger(string s, int k) {
        queue<int> Q[10];
        int n = s.length();
        s = "@" + s;
        vector<int> tree(n+1,0);
        for( int i = 1 ; i <= n ; i++ )
            Q[s[i]-'0'].push(i);
        string ans = "";
        for( int i = 1 ; i <= n ; i++ )
            for( int j = 0 ; j < 10 ; j++ )
                if(!Q[j].empty()) {
                    char c = '0' + j;
                    int ind = Q[j].front();
                    int move = query(ind,tree);
                    int place = ind+move;
                    if(place-1 <= k) {
                        Q[j].pop();
                        k -= place-1;
                        ans.push_back(c);
                        update(ind,n,-1,tree);
                        break;
                    }
                }
        return ans;
    }
};