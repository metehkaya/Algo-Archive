class Solution {
public:
    int nl,nu;
    multiset<int> lower,upper;
    void remove(int x) {
        multiset<int>::iterator it = lower.find(x);
        if(it != lower.end()) {
            nl--;
            lower.erase(it);
        }
        else {
            nu--;
            it = upper.find(x);
            upper.erase(it);
        }
    }
    void balance() {
        while(nl-nu > 1) {
            multiset<int>::iterator it = lower.end();
            it--;
            int x = (*it);
            lower.erase(it);
            upper.insert(x);
            nl--;
            nu++;
        }
        while(nu-nl > 1) {
            multiset<int>::iterator it = upper.begin();
            int x = (*it);
            upper.erase(it);
            lower.insert(x);
            nl++;
            nu--;
        }
    }
    double getMedian() {
        double res;
        if(nl > nu) {
            multiset<int>::reverse_iterator rit = lower.rbegin();
            res = (*rit);
        }
        else if(nu > nl) {
            multiset<int>::iterator it = upper.begin();
            res = (*it);
        }
        else {
            multiset<int>::reverse_iterator rit = lower.rbegin();
            multiset<int>::iterator it = upper.begin();
            res = (1.0*(*it)+1.0*(*rit))/2.0;
        }
        return res;
    }
    vector<double> medianSlidingWindow(vector<int>& ar, int k) {
        vector<double> ans;
        int n = ar.size();
        for( int i = 0 ; i < k ; i++ )
            lower.insert(ar[i]) , nl++;
        balance();
        ans.push_back(getMedian());
        for( int i = k ; i < n ; i++ ) {
            remove(ar[i-k]);
            if(nl == 0)
                upper.insert(ar[i]) , nu++;
            else if(nu == 0)
                lower.insert(ar[i]) , nl++;
            else {
                multiset<int>::iterator it = upper.begin();
                int first = (*it);
                if(ar[i] >= first)
                    upper.insert(ar[i]) , nu++;
                else
                    lower.insert(ar[i]) , nl++;
            }
            balance();
            ans.push_back(getMedian());
        }
        return ans;
    }
};
