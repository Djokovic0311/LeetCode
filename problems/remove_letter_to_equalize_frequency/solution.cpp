#define M 26
class Solution {
    
public:
    int getIdx(char ch)
    {
        return (ch - 'a');
    }

    // Returns true if all non-zero elements
    // values are same
    bool allSame(int freq[], int N)
    {
        int same;

        // get first non-zero element
        int i;
        for (i = 0; i < N; i++) {
            if (freq[i] > 0) {
                same = freq[i];
                break;
            }
        }

        // check equality of each element with variable same
        for (int j = i + 1; j < N; j++)
            if (freq[j] > 0 && freq[j] != same)
                return false;

        return true;
    }

    bool equalFrequency(string word) {
        vector<int> mp(26, -1); //initially marked with -1 to show no char
        
        for(auto it:word)
        {
            if(mp[it-'a']==-1) mp[it-'a']=1;
            else mp[it-'a']++;
        }
            
        
        for(int i=0; i<26; i++)
        {
            if(mp[i]==-1) continue; 
            
            mp[i]--;
            if(mp[i]==0) mp[i]=-1;
            
            int fl=0, cnt=0, fl2=0;
            for(int i=0; i<26; i++)
            {
                if(mp[i]==-1) continue;
                
                if(fl==0)
                {
                    cnt = mp[i];
                    fl=1;
                }
                
                if(mp[i]!=cnt)
                {
                    fl2=1;
                    break;
                }
            }
            if(fl2==0) return true;
            
            if(mp[i]==-1) mp[i]=1;
            else mp[i]++;
            
        }
        return false;
     
    }
};