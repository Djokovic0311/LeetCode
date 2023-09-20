class AuthenticationManager {
public:
    unordered_map<string, int>mp;
    int time= 0;
    AuthenticationManager(int timeToLive) {
        time= timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]= currentTime + time;// This will give you our expiry time at which we will be logged out from the site.
    }
    
    void renew(string tokenId, int currentTime) {
        auto it= mp.find(tokenId); //check if the token is available or not, if it's not available return.
        if(it==mp.end())
        return;
        else{
        if(mp[tokenId]>currentTime) // if the token is available and it's expiry time is greater than current time renew and update the expiry time
        {
            mp[tokenId]= currentTime + time;  // update the expiry time by adding the current time with timeToLive value i.e 5 here.
        }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int total=0;
        for(auto x:mp) // iterate through every token and check if any token has it's expiry time greater than currentTime, if yes do total= total+1, it is simply calculating the remaining time here.
        {
            // cout<<x.second<<" ";
            if(x.second>currentTime)
            total++;
        }
        return total;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
