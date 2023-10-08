class Solution {
public:
    int minimumBuckets(string hamsters) {
        if(hamsters.length()==1){
            if(hamsters[0]=='.')return 0;
            if(hamsters[0]=='H')return -1;
        }
        int ans = 0;
        for(int i = 0; i < hamsters.length(); i++){
            if(hamsters[i]=='H'){
                if(i==0){
                    if(hamsters[i+1]=='H')return -1;
                    else {hamsters[i+1] = '#';ans++;}
                }else if(i==hamsters.length()-1){
                    if(hamsters[i-1]=='H'){return -1;}
                    else if(hamsters[i-1]=='.'){ans++;}
                }else{
                    if(hamsters[i+1]=='H'){
                        if(hamsters[i-1]=='H')return -1;
                        else if(hamsters[i-1]=='.')ans++;
                    }else if(hamsters[i-1]=='#'){
                        continue;
                    }else if(hamsters[i+1]=='.'){
                        ans++;
                        hamsters[i+1]='#';
                    }
                }
            }
        }

        return ans;
    }
};
