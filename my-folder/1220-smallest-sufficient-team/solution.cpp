class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    unordered_map<string, int> skill_map;
    int n = req_skills.size();
    for(int i=0; i<n; ++i){
        skill_map[req_skills[i]] = i;
    }
    vector<int> people_skills(people.size());
    for(int i=0; i<people.size(); ++i){
        for(string& skill: people[i]){
            if(skill_map.count(skill))
                people_skills[i] |= 1 << skill_map[skill];
        }
    }
    vector<int> dp(1<<n, INT_MAX);
    vector<int> parent(1<<n, -1);
    vector<int> person(1<<n, -1);
    dp[0] = 0;
    for(int i=0; i<people.size(); ++i){
        int k_skills = people_skills[i];
        if(k_skills == 0) continue;
        for(int j=0; j<(1<<n); ++j){
            if(dp[j] == INT_MAX) continue;
            int t_skills = j | k_skills;
            if(dp[t_skills] > dp[j] + 1){
                dp[t_skills] = dp[j] + 1;
                parent[t_skills] = j;
                person[t_skills] = i;
            }
        }
    }
    vector<int> res;
    int cur = (1<<n) - 1;
    while(cur != 0){
        res.push_back(person[cur]);
        cur = parent[cur];
    }
    return res;        
    }
};
