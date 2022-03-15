class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x=n&1;
        while(n){
          n>>=1;
          int y=n&1;
          if(x==y){
              return false;
          }
          x=y;  
        }
        return true;
    }
};