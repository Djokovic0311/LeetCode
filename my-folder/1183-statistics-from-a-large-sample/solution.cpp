class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int i=255;
        int j=0;
        while(count[i]==0){
            i--;
        }
        double maxi=i;
        while(count[j]==0){
            j++;
        }
        double mini=j;
        long double total=0;
        int model=0;
        int mod=0;
        int number=0;
        for(int i=mini;i<=maxi;i++){
            total+=(long double )count[i]*i;
            if(model<count[i]){
                model=count[i];
                mod=i;
            }
            number+=count[i];
        }
        double median;
        if(number%2!=0){
            int x=(number+1)/2;
            int it=0;
            for(int i=mini;i<=maxi;i++){
                
                it=it+count[i];
                if(it>=x){
                    median=i;
                    break;
                }
            }
        }
        else{
            int x=number/2;
            int it=0;
            for(int i=mini;i<=maxi;i++){
                if(it>x){
                    median=i-1;
                    break;
                }
                if(it==x){
                    int x=i-1;
                    while(count[i]==0){
                        i++;
                    }
                    median=(i+x)/2.0;
                    break;
                }
                it=it+count[i];
            }
            


        }
        double mean=total/number;
        vector<double>ans={static_cast<double>(mini),static_cast<double>(maxi),mean,median,static_cast<double>(mod)};
        return ans;
    }
};
