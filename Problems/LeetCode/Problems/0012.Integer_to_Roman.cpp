class Solution {
public:
    string intToRoman(int num) {
        string th[4] = {"","M","MM","MMM"};
        string hu[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string te[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string on[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        return th[num/1000]+hu[num%1000/100]+te[num%100/10]+on[num%10];
    }
};