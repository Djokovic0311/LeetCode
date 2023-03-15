class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

         unordered_map<int,int> m ; 
        for(int i = 0; i< arr.size();i++){
          int rem = (arr[i]%k + k)%k ;
          if(rem==0 && m.find(0)!=m.end()){
              m[0]--;
              if(m[0]==0)
              m.erase(0);
          }
         else  if(m.find(k-rem)!=m.end()){
              m[k-rem]--;
              if(m[k-rem]==0)
              m.erase(k-rem);

          }
          else m[rem]++;
           
        }

         
       
       return m.size()==0;
        
    }
};
