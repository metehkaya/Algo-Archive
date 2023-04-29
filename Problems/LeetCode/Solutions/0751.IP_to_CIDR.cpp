class Solution {
public:
    int getTrailingZero(long long ip) {
        if(ip == 0)
            return 32;
        int count = 0;
        while((ip & 0x1) == 0) {
            count++;
            ip /= 2;
        }
        return count;
    }
    long long toIp(string& ip) {
        std::stringstream s(ip);
        char ch;
        long long a,b,c,d;
        s >> a >> ch >> b >> ch >> c >> ch >> d;
        return (a << 24) | (b << 16) | (c << 8) | d;
    }
    void deal(vector<string>& result, int& startIp, int& number) {
        int trailingZeros = getTrailingZero(startIp);
        long long covered = (1LL << trailingZeros);
        while(covered > number) {
            covered /= 2;
            trailingZeros--;
        }
        char buf[200];
        sprintf(buf, "%d.%d.%d.%d/%d", (startIp >> 24) & 0xFF, (startIp >> 16) & 0xFF,
            (startIp >> 8) & 0xFF, startIp & 0xFF, 32 - trailingZeros);
        result.emplace_back(buf);
        number -= covered;
        startIp += covered;
    }
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> result;
        int startIp = toIp(ip);
        while(n)
            deal(result,startIp,n);
        return result;
    }
};
