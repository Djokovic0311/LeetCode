class Task {
public:
    int taskId;
    int userId;
    std::string taskDescription;
    int dueDate;
    bool isComplete;
    std::unordered_set<std::string> tags;

    Task(int taskId, int userId, const std::string& taskDescription, int dueDate, const std::vector<std::string>& tags) 
        : taskId(taskId), userId(userId), taskDescription(taskDescription), dueDate(dueDate), isComplete(false) 
    {
        this->tags.insert(tags.begin(), tags.end());
    }
};

class TodoList {
    int nextTaskId = 1;
    std::unordered_map<int, std::list<Task>> userTasks; // userId -> list of tasks

public:
    TodoList() {}

    int addTask(int userId, const std::string& taskDescription, int dueDate, const std::vector<std::string>& tags) {
        Task task(nextTaskId, userId, taskDescription, dueDate, tags);
        userTasks[userId].push_back(task);
        return nextTaskId++;
    }

    vector<string> getAllTasks(int userId) {
        vector<string> result;
        if (userTasks.find(userId) == userTasks.end()) {
            return result;
        }
        for (const auto& task : userTasks[userId]) {
            if (!task.isComplete) {
                result.push_back(task.taskDescription);
            }
        }
        sort(result.begin(), result.end(), [this, &userId](const std::string& a, const std::string& b) {
            return getTaskByDescription(userId, a).dueDate < getTaskByDescription(userId, b).dueDate;
        });
        return result;
    }

    std::vector<std::string> getTasksForTag(int userId, const std::string& tag) {
        std::vector<std::string> result;
        if (userTasks.find(userId) == userTasks.end()) {
            return result;
        }
        for (const auto& task : userTasks[userId]) {
            if (!task.isComplete && task.tags.find(tag) != task.tags.end()) {
                result.push_back(task.taskDescription);
            }
        }
        sort(result.begin(), result.end(), [this, &userId](const std::string& a, const std::string& b) {
            return getTaskByDescription(userId, a).dueDate < getTaskByDescription(userId, b).dueDate;
        });
        return result;
    }

    void completeTask(int userId, int taskId) {
        if (userTasks.find(userId) == userTasks.end()) {
            return;
        }
        for (auto& task : userTasks[userId]) {
            if (task.taskId == taskId && !task.isComplete) {
                task.isComplete = true;
                break;
            }
        }
    }

private:
    Task& getTaskByDescription(int userId, const std::string& description) {
        for (auto& task : userTasks[userId]) {
            if (task.taskDescription == description) {
                return task;
            }
        }
        throw std::runtime_error("Task description not found!");
    }
};


/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
