#define fi first
#define se second
typedef pair<int,int> pi;

class StockSpanner {
public:
    int day;
    stack<pi> st;
    StockSpanner() {
        day = 0;
    }
    int next(int price) {
        int res;
        day++;
        if(st.empty()) {
            res = 1;
            st.push( pi( price , day ) );
        }
        else {
            while( !st.empty() && st.top().fi <= price )
                st.pop();
            if(st.empty())
                res = day;
            else
                res = day - st.top().se;
            st.push( pi( price , day ) );
        }
        return res;
    }
};