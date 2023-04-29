#define fi first
#define se second
typedef pair<int,int> pi;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size() , day = 0 , ans = 0;
        priority_queue<pi,vector<pi>,greater<pi>> heap;
        while(day < n || !heap.empty()) {
            if(day < n)
                heap.push(pi(day+days[day],apples[day]));
            while(!heap.empty()) {
                pi temp = heap.top();
                heap.pop();
                if(temp.fi == day || temp.se == 0)
                    continue;
                ans++;
                temp.se--;
                heap.push(temp);
                break;
            }
            day++;
        }
        return ans;
    }
};