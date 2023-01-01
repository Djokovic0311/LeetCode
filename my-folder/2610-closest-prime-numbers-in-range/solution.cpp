class Solution {
public:
    
    int vis[1000001];
    int prime[1000001];
    vector<int> closestPrimes(int left, int right) {
        int last = 0;
        int closest = INT_MAX;
        vector<int> v(2,-1);

        memset(vis,0,sizeof(vis));
        int tot=0;
        for(int i=2;i<=right;i++){
            if(vis[i]==0){
                prime[++tot]=i;
                vis[i]=i;
            }
            for(int x=1;x<=tot;x++){
                if(prime[x]*i>right || prime[x]>vis[i])break;
                vis[prime[x]*i]=prime[x];
            }
        }
        
        for(int i=1;i<=tot;i++){
            if(prime[i]>=left){
                if(last == 0) {
                    last = prime[i];
                }
                else {
                    if(prime[i] - last < closest) {
                        closest = prime[i] - last;
                        v[0] = last;
                        v[1] = prime[i];
                    }
                    last = prime[i];
                }
            }
        }

        return v;
    }
};
