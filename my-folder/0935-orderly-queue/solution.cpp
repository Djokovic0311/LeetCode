class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
        
        string temp=s;
        
        for(int i=0;i<s.length();i++){
            
            string sub=s.substr(i)+s.substr(0,i);
            
            if(min(temp,sub)==sub){
                temp=sub;
            }
            
        }
        
        return temp;
    }
    
    else{
        
        sort(s.begin(),s.end());
        
        return s;
    }
    }
};
