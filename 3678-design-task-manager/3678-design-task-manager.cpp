class TaskManager {
private:
    // taskId -> {userId, priority}
    unordered_map<int, pair<int, int>> taskInfo;
    
    // max heap: {priority, taskId, taskId}
    // We use taskId as second field so that on priority ties the larger taskId is preferred.
    priority_queue<tuple<int,int,int>> maxHeap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int user = t[0], task = t[1], pr = t[2];
            taskInfo[task] = {user, pr};
            maxHeap.push({pr, task, task});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        maxHeap.push({priority, taskId, taskId});
    }

    void edit(int taskId, int newPriority) {
        auto it = taskInfo.find(taskId);
        if (it == taskInfo.end()) return; // guard, though problem guarantees existence
        int user = it->second.first;
        taskInfo[taskId] = {user, newPriority};
        maxHeap.push({newPriority, taskId, taskId});
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy removal; heap entries become stale
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, tidKey, tid] = maxHeap.top();
            maxHeap.pop();

            auto it = taskInfo.find(tid);
            if (it != taskInfo.end() && it->second.second == priority) {
                int user = it->second.first;
                taskInfo.erase(tid);
                return user;
            }
            // otherwise stale entry, continue
        }
        return -1;
    }
};

