class VideoSharingPlatform {
public:
    unordered_map<int,int> views;
    unordered_map<int,int> likes;
    unordered_map<int,int> dislikes;
    unordered_map<int,string> videos;
    int next_video_id = 0;
    set<int> available_ids;
    VideoSharingPlatform() {}
    int upload(string video) {
        int id;
        if(!available_ids.empty()) {
            auto it = available_ids.begin();
            id = (*it);
            available_ids.erase(it);
        }
        else
            id = next_video_id++;
        likes[id] = dislikes[id] = views[id] = 0;
        videos[id] = video;
        return id;
    }
    void remove(int id) {
        auto it = videos.find(id);
        if(it != videos.end()) {
            videos.erase(it);
            views.erase(id);
            likes.erase(id);
            dislikes.erase(id);
            available_ids.insert(id);
        }
    }
    string watch(int id, int s, int e) {
        auto it = videos.find(id);
        if(it == videos.end())
            return "-1";
        views[id]++;
        string& video = it->second;
        int len = video.length();
        e = min(e,len-1);
        return video.substr(s,e+1-s);
    }
    void like(int id) {
        auto it = likes.find(id);
        if(it != likes.end())
            it->second++;
    }
    void dislike(int id) {
        auto it = dislikes.find(id);
        if(it != dislikes.end())
            it->second++;
    }
    vector<int> getLikesAndDislikes(int id) {
        auto it = likes.find(id);
        if(it == likes.end())
            return {-1};
        return {likes[id],dislikes[id]};
    }
    int getViews(int id) {
        auto it = views.find(id);
        return (it == views.end()) ? -1 : it->second;
    }
};
