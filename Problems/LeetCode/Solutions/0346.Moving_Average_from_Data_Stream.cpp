class MovingAverage {
public:
    int n,size;
    double sum;
    queue<int> Q;
    MovingAverage(int size) {
        n = 0;
        sum = 0;
        this->size = size;
    }
    double next(int val) {
        if(n == size) {
            sum -= Q.front();
            Q.pop();
            n--;
        }
        sum += val;
        Q.push(val);
        n++;
        return sum / n;
    }
};