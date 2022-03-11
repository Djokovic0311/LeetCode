class Solution {
public:
    int totalMoney(int n) {
        int m=n/7;  //(no.of full weeks)

        int res=0; 
        for(int i=1;i<=m;i++){
            res+=7*(i+3);
        }
        //calculating left days
        for(int i=7*m;i<n;i++){
            res+=++m;
        }
        return res;
    }
};
