class Solution {
public:
	vector<vector<int>> graph;
	vector<int> ans;

	void dfs(int &current, vector<int> &quiet) {
    
		ans[current] = current;

		for(auto &neighbour : graph[current]) {
			if(ans[neighbour] == -1) 
				dfs(neighbour, quiet);
			
			if(quiet[ans[current]] > quiet[ans[neighbour]])
				ans[current] = ans[neighbour];
		}
    
	}

	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
		int n = quiet.size();
		graph.resize(n);
		ans.resize(n, -1);
    
		for(auto &pair : richer)
			graph[pair[1]].push_back(pair[0]);
    
		for(int person = 0; person < n; person++) {
			if(ans[person] == -1)
				dfs(person, quiet);
		}
    
		return ans;
	}
};