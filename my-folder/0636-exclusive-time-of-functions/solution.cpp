class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<pair<int,int>> stk;
        int prevTime = 0;

        for(auto& log : logs) {
            int num = stoi(log.substr(0, log.find(':')));
            int time = stoi(log.substr(log.rfind(':') + 1));
            if(log.find('e') != -1) {
                res[num] += (time-prevTime+1);
                stk.pop();
                prevTime = time+1;
            } else {
                if(!stk.empty()) {
                    res[stk.top().first] += time-prevTime;
                }
                stk.push({num,time});
                prevTime = time;
            }
        }

        return res;
    }
};
