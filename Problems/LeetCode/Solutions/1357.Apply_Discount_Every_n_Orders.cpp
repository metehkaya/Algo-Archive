class Cashier {
public:
    int n;
    int cnt;
    int discount;
    unordered_map<int,int> price;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0;
        this->n = n;
        this->discount = discount;
        int p = products.size();
        for( int i = 0 ; i < p ; i++ )
            price.insert( make_pair( products[i] , prices[i] ) );
    }
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0;
        int p = product.size();
        for( int i = 0 ; i < p ; i++ )
            ans += amount[i] * price[product[i]];
        if(++cnt == n) {
            cnt = 0;
            ans = ans * (100 - discount) / 100.0;
        }
        return ans;
    }
};