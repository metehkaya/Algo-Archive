class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> Q;
        stack<int> st;
        for( int i = 0 ; i < n ; i++ ) {
            Q.push(students[i]);
            st.push(sandwiches[n-1-i]);
        }
        int rem = n , cons = 0;
        while(rem > 0 && cons < n) {
            if(Q.front() == st.top()) {
                rem--;
                cons = 0;
                Q.pop();
                st.pop();
            }
            else {
                cons++;
                Q.push(Q.front());
                Q.pop();
            }
        }
        return rem;
    }
};