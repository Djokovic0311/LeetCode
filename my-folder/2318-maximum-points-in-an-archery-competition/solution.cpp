class Solution {
public:
    int n;
    vector<int> a;
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        a=aliceArrows;
        n=numArrows;
        int ans=0;
        vector<int> res;
        for(int mask=0;mask<(1<<12);mask++){
            int score=0;
            vector<int> temp(12,0);
            int x=0;
            for(int j=0;j<12;j++){
                if((mask&(1<<j))){
                    score+=j;
                    x+=(a[j]+1);
                    temp[j]=(a[j]+1);
                }
            }
            if(x==n && score>=ans){
                res=temp;
                ans=score;
            }
            else if(x<n && score>=ans){
                for(int j=0;j<12;j++){
                    if(temp[j]!=0){
                        temp[j]=temp[j]+(n-x);
                        break;
                    }
                }
                res=temp;
                ans=score;
            }
        }
        return res;
    }
};
