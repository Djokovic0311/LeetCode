class Solution {
public:
    std::vector<int> sortItems(int n, int m, std::vector<int>& group, std::vector<std::vector<int>>& beforeItems) {
        // If an item belongs to zero group, assign it a unique group id.
        int groupId = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupId;
                groupId++;
            }
        }
        
        // Sort all items regardless of group dependencies.
        std::unordered_map<int, std::vector<int>> itemGraph;
        std::vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = std::vector<int>();
        }
        
        // Sort all groups regardless of item dependencies.
        std::unordered_map<int, std::vector<int>> groupGraph;
        std::vector<int> groupIndegree(groupId, 0);
        for (int i = 0; i < groupId; ++i) {
            groupGraph[i] = std::vector<int>();
        }
        
        for (int curr = 0; curr < n; curr++) {
            for (int prev : beforeItems[curr]) {
                // Each (prev -> curr) represents an edge in the item graph.
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;
                
                // If they belong to different groups, add an edge in the group graph.
                if (group[curr] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }

        // Topological sort nodes in the graph, return an empty vector if a cycle exists.
        std::vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        std::vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() || groupOrder.empty()) {
            return std::vector<int>();
        }
        
        // Items are sorted regardless of groups, we need to differentiate them by the groups they belong to.
        std::unordered_map<int, std::vector<int>> orderedGroups;
        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }
        
        // Concatenate sorted items in all sorted groups.
        std::vector<int> answerList;
        for (int groupIndex : groupOrder) {
            if (orderedGroups.find(groupIndex) != orderedGroups.end()) {
                answerList.insert(answerList.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
            }
        }
        
        return answerList;
    }
    
private:
    std::vector<int> topologicalSort(std::unordered_map<int, std::vector<int>>& graph, std::vector<int>& indegree) {
        std::vector<int> visited;
        std::stack<int> stack;
        for (const auto& pair : graph) {
            if (indegree[pair.first] == 0) {
                stack.push(pair.first);
            }
        }
        
        while (!stack.empty()) {
            int curr = stack.top();
            stack.pop();
            visited.push_back(curr);
            
            for (int prev : graph[curr]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    stack.push(prev);
                }
            }
        }

        return visited.size() == graph.size() ? visited : std::vector<int>();
    }
};
