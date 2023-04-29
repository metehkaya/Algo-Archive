class ProductOfNumbers {
public:
    int n,all;
    vector<int> zero;
    vector<int> mult;
    ProductOfNumbers() {
        n = 1;
        all = 1;
        zero.push_back(0);
        mult.push_back(all);
    }
    void add(int num) {
        n++;
        if(num == 0) {
            all = 1;
            mult.push_back(all);
            zero.push_back(zero.back()+1);
        }
        else {
            all *= num;
            mult.push_back(all);
            zero.push_back(zero.back());
        }
    }
    int getProduct(int k) {
        int cnt0 = zero[n-1] - zero[n-k-1];
        if(cnt0)
            return 0;
        return all / mult[n-k-1];
    }
};