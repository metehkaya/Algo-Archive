typedef pair<int,int> pi;

class Solution {
public:
    int minDays(int n) {
        queue<pi> Q;
        set<int> mark;
        mark.insert(n);
        Q.push(pi(n,0));
        while(!Q.empty()) {
            pi temp = Q.front();
            Q.pop();
            n = temp.first;
            int dist = temp.second;
            if(n == 0)
                return dist;
            if(mark.find(n-1) == mark.end()) {
                Q.push(pi(n-1,dist+1));
                mark.insert(n-1);
            }
            if(n%2 == 0 && mark.find(n/2) == mark.end()) {
                Q.push(pi(n/2,dist+1));
                mark.insert(n/2);
            }
            if(n%3 == 0 && mark.find(n/3) == mark.end()) {
                Q.push(pi(n/3,dist+1));
                mark.insert(n/3);
            }
        }
        return -1;
    }
};