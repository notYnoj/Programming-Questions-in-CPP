class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task_count(26, 0);
        int max_count = 0;
        
        // Count the frequency of each task
        for (char task : tasks) {
            task_count[task - 'A']++;
            max_count = max(max_count, task_count[task - 'A']);
        }
        
        // Count the number of tasks with the maximum frequency
        int num_max_tasks = 0;
        for (int count : task_count) {
            if (count == max_count) {
                num_max_tasks++;
            }
        }
        
        // Calculate the minimum number of intervals required
        int intervals = (max_count - 1) * (n + 1) + num_max_tasks;
        return max(static_cast<int>(tasks.size()), intervals);
    }
};
