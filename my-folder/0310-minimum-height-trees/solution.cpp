class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> roots;
        if(n==1) 
        {
            roots.push_back(0);
            return roots;
        }
        vector<vector<int>> graph(n);
        vector<int> inDegree(n); //  indegree of a node is the number of edges leading to that node 
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
            inDegree[e[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==1) // leaf node
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int node = q.front();q.pop();
                inDegree[node]--; // remove leaf
                
                if(n<=2) roots.push_back(node);
                
                for(int& neighbor:graph[node])
                {
                    inDegree[neighbor]--; // remove leaf
                    if(inDegree[neighbor]==1) 
                    {
                        q.push(neighbor);
                    }
                }
            }
            n-=size; // remove leaves layer by layer
        }
        return roots;
    }
};
