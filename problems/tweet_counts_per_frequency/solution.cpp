class TweetCounts {
public:
  unordered_map<string, vector<int>> t;
      
  void recordTweet(string tN, int time) { 
    t[tN].insert(upper_bound(t[tN].begin(), t[tN].end(), time), time);
  }
    
  vector<int> getTweetCountsPerFrequency(string freq, string tN, int startTime, int endTime) {
    vector<int>res;
    int sh = freq[0] == 'm' ? sh = 60 : freq[0] == 'h' ? sh = 3600 : sh = 86400;
    
    auto id = upper_bound(t[tN].begin(), t[tN].end(), --startTime);
    
    while(startTime != endTime){
      startTime = min(endTime, startTime + sh);
      auto id_next = upper_bound(id, t[tN].end(), startTime);
      res.push_back(id_next - id);
      id = id_next;
    }
    
    return res;
  }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */