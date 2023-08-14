struct FileNode {
    unordered_map<string, FileNode*> next;
    bool isFile;
    string content;
    FileNode() {
        isFile = false;
        content = "";
    }
};

class FileSystem {
public:
    FileNode *root;
    FileSystem() {
        root = new FileNode();
    }
    vector<string> ls(string path) {
        FileNode *curr = goToPathFolder(path);
        if(curr->isFile)
            return {path.substr(path.find_last_of('/') + 1)};
        vector<string> ans;
        for(auto &p : curr->next)
            ans.push_back(p.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void mkdir(string path) {
        goToPathFolder(path);
    }
    void addContentToFile(string filePath, string content) {
        FileNode *curr = goToPathFolder(filePath);
        curr->content += content;
        curr->isFile = true;
    }
    string readContentFromFile(string filePath) {
        FileNode *curr = goToPathFolder(filePath);
        return curr->content;
    }
    FileNode* goToPathFolder(string path) {
        FileNode *curr = root;
        stringstream s(path);
        string folder;
        while(getline(s, folder, '/'))
            if(folder.size()) {
                if (curr->next[folder] == NULL)
                    curr->next[folder] = new FileNode();
                curr = curr->next[folder];
            }
        return curr;
    }
};
