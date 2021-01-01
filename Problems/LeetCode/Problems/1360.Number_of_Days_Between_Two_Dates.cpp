class Solution {
public:
    bool isLeapYear(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }
    int getDays(string& date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        int sum = day;
        for( int i = 1971 ; i < year ; i++ )
            sum += 365 + isLeapYear(i);
        for( int i = 1 ; i < month ; i++ ) {
            if( i == 4 or i == 6 or i == 9 or i == 11 )
                sum += 30;
            else if( i == 2 )
                sum += 28 + isLeapYear(year);
            else
                sum += 31;
        }
        return sum;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs( getDays(date2) - getDays(date1) );
    }
};