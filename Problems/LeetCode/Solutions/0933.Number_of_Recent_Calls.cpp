class RecentCounter {
public:
    int n;
    queue<int> Q;
    RecentCounter() {
        n = 0;
    }
    int ping(int t) {
        n++;
        Q.push(t);
        while(Q.front() < t-3000)
            Q.pop() , n--;
        return n;
    }
};