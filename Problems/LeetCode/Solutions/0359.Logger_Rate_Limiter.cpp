class Logger {
public:
    unordered_map<string,int> hashh;
    Logger() {
        hashh.clear();
    }
    bool shouldPrintMessage(int timestamp, string message) {
        unordered_map<string,int>::iterator mit = hashh.find(message);
        if(mit == hashh.end() || timestamp - mit->second >= 10) {
            hashh[message] = timestamp;
            return true;
        }
        return false;
    }
};