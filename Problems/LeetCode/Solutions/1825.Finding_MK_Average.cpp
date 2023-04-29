class MKAverage {
public:
    int n,k;
    long long sum;
    queue<int> Q;
    multiset<int> small, mid, big;
    MKAverage(int M, int K) {
        n = M;
        k = K;
        sum = 0;
    }
    void addElement(int val) {
        if(small.empty() || val < *small.rbegin())
            small.insert(val);
        else if(big.empty() || val > *big.begin())
            big.insert(val);
        else {
            sum += val;
            mid.insert(val);
        }
        Q.push(val);
        if(Q.size() > n) {
            int x = Q.front();
            Q.pop();
            auto it = small.find(x);
            if(it != small.end())
                small.erase(it);
            else {
                it = mid.find(x);
                if(it != mid.end()) {
                    mid.erase(it);
                    sum -= x;
                }
                else {
                    it = big.find(x);
                    big.erase(it);
                }
            }
        }
        while(small.size() > k) {
            int x = *small.rbegin();
            small.erase(prev(small.end()));
            mid.insert(x);
            sum += x;
        }
        while(big.size() > k) {
            int x = *big.begin();
            big.erase(big.begin());
            mid.insert(x);
            sum += x;
        }
        while(small.size() < k && !mid.empty()) {
            int x = *mid.begin();
            mid.erase(mid.begin());
            sum -= x;
            small.insert(x);
        }
        while(big.size() < k && !mid.empty()) {
            int x = *mid.rbegin();
            mid.erase(prev(mid.end()));
            sum -= x;
            big.insert(x);
        }
    }
    int calculateMKAverage() {
        return Q.size() < n ? -1 : sum / (n-2*k);
    }
};