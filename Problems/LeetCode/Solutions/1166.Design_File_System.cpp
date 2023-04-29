class FileSystem {
public:
    map<string,int> hashh;
    FileSystem() {
        hashh[""] = 0;
    }
    bool createPath(string path, int value) {
        auto it = hashh.find(path);
        if(it != hashh.end())
            return false;
        int index = path.length()-1;
        while(path[index] != '/')
            index--;
        string s = path.substr(0,index);
        it = hashh.find(s);
        if(it == hashh.end())
            return false;
        hashh[path] = value;
        return true;
    }
    int get(string path) {
        auto it = hashh.find(path);
        int ans = it == hashh.end() ? -1 : it->second;
        return ans;
    }
};