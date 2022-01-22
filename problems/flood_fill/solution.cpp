class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));        
        queue<pair<int,int>>pq;
        pq.push({sr,sc});
        visited[sr][sc]=1;
        
        while(pq.size()>0)
        {
            int i=pq.front().first;
            int j=pq.front().second;
            
            pq.pop();
            
            if(i-1>=0&&image[i-1][j]==image[i][j]&& visited[i-1][j]==0)
            {
                visited[i][j]=1;
                pq.push({i-1,j});
            }
            if(j-1>=0&&image[i][j-1]==image[i][j]&& visited[i][j-1]==0)
            {
                visited[i][j-1]=1;
                pq.push({i,j-1});
            }
            if(i+1<image.size()&&image[i+1][j]==image[i][j]&& visited[i+1][j]==0)
            {
                visited[i+1][j]=1;
                pq.push({i+1,j});
            }
            if(j+1<image[0].size()&&image[i][j+1]==image[i][j]&& visited[i][j+1]==0)
            {
                visited[i][j+1]=1;
                pq.push({i,j+1});
            }
            image[i][j]=newColor;
        }
        return image;        
    }
};