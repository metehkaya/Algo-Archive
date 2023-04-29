struct Task {
    string desc;
    int due_data;
    unordered_set<string> tags;
    bool operator<(const Task& other) const {
        return due_data < other.due_data;
    }
};

class TodoList {
public:
    int n_tasks = 0;
    unordered_map<int, unordered_map<int, Task>> user_to_tasks;
    TodoList() {}
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        Task task = Task{taskDescription, dueDate, {tags.begin(), tags.end()}};
        user_to_tasks[userId][++n_tasks] = task;
        return n_tasks;
    }
    vector<string> getAllTasks(int userId) {
        vector<string> res;
        auto tasks = get_sorted_tasks(userId);
        for(Task& task : tasks)
            res.push_back(task.desc);
        return res;
    }
    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> res;
        auto tasks = get_sorted_tasks(userId);
        for(Task& task : tasks)
            if(task.tags.count(tag))
                res.push_back(task.desc);
        return res;
    }
    void completeTask(int userId, int taskId) {
        auto it = user_to_tasks.find(userId);
        if(it == user_to_tasks.end())
            return;
        auto& id_to_tasks = it->second;
        if(!id_to_tasks.count(taskId))
            return;
        id_to_tasks.erase(taskId);
    }
    vector<Task> get_sorted_tasks(int userId) {
        const auto it = user_to_tasks.find(userId);
        if(it == user_to_tasks.end())
            return {};
        vector<Task> tasks;
        for(auto task : it->second)
            tasks.push_back(task.second);
        sort(tasks.begin(),tasks.end());
        return tasks;
    }
};
