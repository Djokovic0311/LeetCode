class Solution {
public:
  int lengthLongestPath(string input) {
    int maxPathLen = 0;
    stack<string> dirsInPath;
    int dirsLen = 0;
    long start = 0;
    while (true) {
      auto segmentEndIndex = input.find('\n', start);
      string segmentWithTabs = input.substr(start, segmentEndIndex - start);
      
      auto tabEndIndex = segmentWithTabs.find_first_not_of('\t');
      string segment = segmentWithTabs.substr(tabEndIndex);
      
      int depth = count(segmentWithTabs.begin(), segmentWithTabs.end(), '\t');
      bool isFile = segment.find('.') != string::npos;
      
      while (dirsInPath.size() > depth) {
        string segmentPoped = dirsInPath.top();
        dirsInPath.pop();
        dirsLen -= segmentPoped.length();
      }
      if (isFile) {
        int currentFilePathLen = dirsLen + segment.length() + dirsInPath.size();
        maxPathLen = max(maxPathLen, currentFilePathLen);
      } else {
        dirsInPath.push(segment);
        dirsLen += segment.length();
      }
      
      if (segmentEndIndex == string::npos) break;
      start = segmentEndIndex + 1;
    }
    
    return maxPathLen;
  }
};
