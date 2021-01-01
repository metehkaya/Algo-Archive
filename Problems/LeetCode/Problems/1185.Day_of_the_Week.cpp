class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int total = 365 * (year-1);
        total += (year-1) / 4;
        total -= (year-1) / 100;
        total += (year-1) / 400;
        for( int i = 0 ; i < month-1 ; i++ ) {
            total += days[i];
            if(i == 1)
                if( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) )
                    total++;
        }
        total += day;
        total--;
        string week[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        return week[total%7];
    }
};