class Solution {
public:
    int largestInteger(int num) {
        vector<int> p,digs[2];
        while(num) {
            digs[num%2].push_back(num%10);
            p.push_back(num%2);
            num /= 10;
        }
        reverse(p.begin(),p.end());
        sort(digs[0].begin(),digs[0].end());
        sort(digs[1].begin(),digs[1].end());
        int ans = 0;
        for(int i : p) {
            ans = 10*ans + digs[i].back();
            digs[i].pop_back();
        }
        return ans;
    }
};
