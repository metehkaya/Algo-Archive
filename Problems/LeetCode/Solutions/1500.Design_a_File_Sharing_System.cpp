class FileSharing {
public:
    int next_user_id;
    set<int> available_user_ids;
    vector<set<int>> chunk_to_users;
    unordered_map<int,vector<int>> user_to_chunks;
    FileSharing(int m) {
        next_user_id = 1;
        chunk_to_users.resize(m+1);
    }
    int join(vector<int> ownedChunks) {
        int user_id;
        if(available_user_ids.empty())
            user_id = next_user_id++;
        else {
            auto iter = available_user_ids.begin();
            user_id = (*iter);
            available_user_ids.erase(iter);
        }
        user_to_chunks[user_id] = ownedChunks;
        for(int chunk : ownedChunks)
            chunk_to_users[chunk].insert(user_id);
        return user_id;
    }
    void leave(int userID) {
        available_user_ids.insert(userID);
        for(int chunk : user_to_chunks[userID])
            chunk_to_users[chunk].erase(userID);
        user_to_chunks.erase(userID);
    }
    vector<int> request(int userID, int chunkID) {
        auto& users_set = chunk_to_users[chunkID];
        if(users_set.empty())
            return {};
        auto users = vector<int>(users_set.begin(),users_set.end());
        user_to_chunks[userID].push_back(chunkID);
        users_set.insert(userID);
        return users;
    }
};
