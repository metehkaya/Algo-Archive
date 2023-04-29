class LUPrefix {
public:
    int ans;
    vector<bool> res;
    LUPrefix(int n) {
        ans = 0;
        res.resize(n+2,false);
    }
    void upload(int video) {
        res[video] = true;
        while(res[ans+1])
            ans++;
    }
    int longest() {
        return ans;
    }
};
