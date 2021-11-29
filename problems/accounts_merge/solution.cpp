class Solution {
private:
    unordered_map<string, vector<string>> graph;
    unordered_set<string> visited;
    unordered_map<string,string> email_to_name;

    void buildGraph(vector<vector<string>>& accounts) {
        for(int i = 0; i < accounts.size(); ++i) {
            string name = accounts[i][0];
            string first_email = accounts[i][1];
            
            for(int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                graph[first_email].push_back(email);
                graph[email].push_back(first_email);
                if(!email_to_name.count(email) ) {
                    email_to_name[email] = name;
                }
            }
        }
        
    }
    void dfs(string email, set<string> &email_set) {
        if(visited.count(email)) {
            return;
        }
        visited.insert(email);
        email_set.insert(email);
        for(auto email : graph[email]) {
            dfs(email, email_set);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        buildGraph(accounts);
        for(auto [email, _] : graph) {
            if(!visited.count(email)) {
                set<string> email_set;
                dfs(email, email_set);
                vector<string> account(email_set.size() + 1);
                string name = email_to_name[email];
                account = {email_set.begin(), email_set.end()};
                account.insert(account.begin(), name);
                res.push_back(account);
            }
        }
        return res;
    }
};