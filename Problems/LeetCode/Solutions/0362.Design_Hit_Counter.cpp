class HitCounter {
public:
    int sz;
    queue<int> Q;
    HitCounter() {
        sz = 0;
    }
    void hit(int t) {
        sz++;
        Q.push(t);
    }
    int getHits(int t) {
        while(!Q.empty() && Q.front() <= t-300) {
            sz--;
            Q.pop();
        }
        return sz;
    }
};