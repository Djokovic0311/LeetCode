class Solution {
public:
    
    static bool comparator(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])
            return true;
        if(a[0]==b[0])
            return a[1]<=b[1];
        return false;
    }
    
    int binSearch(vector<vector<int>>&tiles,int size,int tar){
        int l = 0;
        int u = size-1;
        
        while(l+1<u){
            int mid = (l+u)/2;
            
            if(tiles[mid][0]<=tar&&tar<=tiles[mid][1])
                return mid;
            
            if(tiles[mid][1]<tar){
                l=mid;
            }
            else u=mid;
        }
        
        //cout<<"tar : "<<tar<<endl;
        
        if(tiles[l][0]<=tar&&tar<=tiles[l][1])
            return l;
        
        if(tar<tiles[u][0])
            return l;
        
        if(tar>=tiles[u][0])
            return u;
        return u;
    }
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        sort(tiles.begin(),tiles.end(),comparator);
        
        int i=0;
        int size=tiles.size();
        
        int maxi=0;
        
        int sum=0;
        
        /*cout<<"Tile : ";
        for(auto ele:tiles){
            cout<<ele[0]<<" "<<ele[1]<<" ; ";
        }
        cout<<endl;*/
        
        vector<int>prefS={0};
        for(auto ele:tiles){
            sum+=(ele[1]-ele[0]+1);
            prefS.push_back(sum);
        }
        
        /*for(auto ele:prefS){
            cout<<ele<<" ";
        }
        cout<<endl;*/
        
        
        while(i<size){
            int start=tiles[i][0];
            int tar=start+carpetLen-1;
            int ind = binSearch(tiles,size,tar);
            
            //cout<<ind<<endl;
            
            int tSum = (prefS[ind]-prefS[i]);
            
            
            if(/*tiles[ind][0]<=tar&&*/tar<=tiles[ind][1]){
                tSum+=(tar-tiles[ind][0])+1;
                
            }
            else if(tar>tiles[ind][1]){
                tSum+=(tiles[ind][1]-tiles[ind][0]+1);
            }
            
            //cout<<tSum<<endl;
            maxi=max(maxi,tSum);
            i++;
        }
        
        return maxi;
    }
};
