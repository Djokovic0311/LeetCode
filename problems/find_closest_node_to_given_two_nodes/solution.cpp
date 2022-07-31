class Solution {
public:
void bfs(int src, vector<int> &dist,vector<int>& edge,int n){
    queue<int> q;
    q.push(src);
    dist[src]=0;
    vector<bool> vis(n);
    vis[src]=true;
    while(q.size()>0){
        auto p= q.front(); q.pop();
        if(edge[p]!=-1 and !vis[edge[p]]){
            q.push(edge[p]);  
            dist[edge[p]]= dist[p]+1; 
            vis[edge[p]]=true;
        }
    }
}

int closestMeetingNode(vector<int>& e, int n1, int n2) {
    int n= e.size();
    vector<int> A(n,INT_MAX), B(n,INT_MAX);
    bfs(n1,A,e,n);   
    bfs(n2,B,e,n);
    int res= INT_MAX, node=-1;
    for(int i=0;i<n;i++){
        if(A[i]==INT_MAX or B[i]==INT_MAX) continue;
        if(res>max(A[i],B[i])) node=i,res= max(A[i],B[i]);
    }
    return res==INT_MAX? -1 : node;
}
};