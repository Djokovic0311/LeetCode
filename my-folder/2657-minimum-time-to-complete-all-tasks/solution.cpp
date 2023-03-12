class Solution {

public:

//         for t,d,pt,i in sorted(stack):        
//             if 1-d:
//                 active[i]=[t,pt]
//             else:              
//                 un_used=active[i][1]
//                 res+=un_used
//                 for j in active:
//                     use=min(active[j][1],t-active[j][0]+1,un_used)
//                     active[j][1]-=use
//                     active[j][0]+=use
//                 del active[i]
//         return res 
    int findMinimumTime(vector<vector<int>>& tasks) {
        vector<vector<int>> stk;
        int res = 0;
        unordered_map<int, pair<int, int>> active;

        for (int i = 0; i < tasks.size(); i++) {
            int start = tasks[i][0];
            int end = tasks[i][1];
            int pt = tasks[i][2];
            stk.push_back({start, 0, pt, i});
            stk.push_back({end, 1, pt, i});
        }

        sort(stk.begin(), stk.end());

        for (auto item : stk) {
            int t = item[0],d = item[1],pt = item[2],i = item[3];
            if (1-d) {
                active[i] = {t, pt};
            } else {
                int un_used = active[i].second;
                res += un_used;
                for (auto& [j, task] : active) {
                    int use = min(task.second, min(t-task.first+1, un_used));
                    task.second -= use;
                    task.first += use;
                }
                active.erase(i);
            }
        }
        return res;
    }
};
