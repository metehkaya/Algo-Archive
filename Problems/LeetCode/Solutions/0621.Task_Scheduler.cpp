typedef pair<int,int> pi;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        int day,rem=0;
        vector<int> sch;
        vector<int> cnt(26,0);
        priority_queue<pi> pq;
        for( int i = 0 ; i < tasks.size() ; i++ )
            cnt[tasks[i]-'A']++;
        for( int i = 0 ; i < 26 ; i++ )
            if(cnt[i])
                pq.push(pi(cnt[i],i));
        for( day = 0 ; !pq.empty() or rem > 0 ; day++ ) {
            sch.push_back(-1);
            if(day >= n and sch[day-n] != -1 and cnt[sch[day-n]])
                pq.push(pi(cnt[sch[day-n]],sch[day-n])) , rem--;
            if(!pq.empty()) {
                pi temp = pq.top();
                pq.pop();
                int c = temp.first;
                int i = temp.second;
                sch[day] = i;
                if(--cnt[i])
                    rem++;
            }
        }
        return day;
    }
};