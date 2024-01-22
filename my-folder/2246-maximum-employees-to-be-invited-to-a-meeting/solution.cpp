// Time Complexity: O(V+E)
// Space Complexity: O(V+E)
class Solution {
public:
    void toposort(vector<vector<int>>&adjList,vector<int>&visited,stack<int>&st, int node)
    {
        // mark as visited
        visited[node]=1;
         
        // traverse over neighbors
        for(auto adjNode: adjList[node])
          // yet not visited
           if(!visited[adjNode])
              toposort(adjList,visited,st,adjNode);
       st.push(node);
       
    }

    int dfs(vector<vector<int>>&adjList,vector<int>&visited,int node,vector<int>&Nodes)
    {
        // mark as visited
         visited[node]=1;
          int cnt=1;
          Nodes.push_back(node);
         // traverse over neighbor nodes
         for(auto adjNode: adjList[node])
          // yet not visited
           if(!visited[adjNode])
            cnt+=dfs(adjList,visited,adjNode,Nodes);
        
        // return 
        return cnt;
    }
    int maximumInvitations(vector<int>& favorite) {

        // create an adjacency list
        int n=favorite.size();
        if(n<=3)
          return n;
        vector<vector<int>>adjList(n,vector<int>());
        for(int i=0;i<n;i++)
          adjList[i].push_back(favorite[i]);

        stack<int>st;
        vector<int>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
          if(!visited[i])
           toposort(adjList,visited,st,i);
        
        // transpose of graph
        vector<vector<int>>adjT(n,vector<int>());
        
        for(int i=0;i<n;i++)
          {  visited[i]=0;
              adjT[favorite[i]].push_back(i);
          }
        int sum=0;
        while(!st.empty())
        {   vector<int>Nodes;
            int node=st.top();
            st.pop();
             int lc;
            if(!visited[node])
             {lc=dfs(adjT,visited,node,Nodes);
              if(lc>2)
                ans=max(lc,ans);
              else
              if(lc==2)
             {  
              
                sum+=extendL(adjT,Nodes[0],Nodes[1],n);
                sum+=extendL(adjT,Nodes[1],Nodes[0],n);
             }
              }
        }
       
       return  max(sum,ans);
    }
    int extendL(vector<vector<int>>&adjT,int node,int parent,int n)
    {
        // do level wise bfs
        queue<int>q;
        q.push(node);
        vector<int>visited(n,0);

        // to count no. of nodes
        int cnt=0;

        while(!q.empty())
        {
            int Size=q.size();

            for(int i=0;i<Size;i++)
            {
                int node=q.front();
                q.pop();

                // traverse over neighbors
                for(auto adjNode: adjT[node])
                  {
                      if(adjNode==parent) continue;
                      
                      // yet not visited
                      if(!visited[adjNode])
                      {
                          q.push(adjNode);
                          // mark as visited
                          visited[adjNode]=1;
                      }
                  }
            }
             cnt++;
        }

        // return ans
        return cnt;
    }
};
