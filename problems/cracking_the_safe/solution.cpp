class Solution {
public:
    string finalAns = "";
    bool visited[10005];
    int n, k, total;
    int counter = 0;
    
    void dfs(string node, string ans) {
        if (finalAns != "") return;
        if (counter == total) {
         string realAns = ans.substr(0, n);
         int x = -1;
         while (1) {
            if (x == -1) x = n - 1 + n;
            else x = x + n;
            realAns.push_back(ans[x]);
            if (x >= ans.size() - 1) break;
         }
         finalAns = realAns;
         return;
      }
        for (int i = 0; i < k; i++) {
         if (finalAns != "") return; // search pruning
		 
		 // reusing last n-1 new digits
         char a = i + '0';
         string newNode = node.substr(1);
         newNode.push_back(a);
		 
		 // explore node if yet visited
         int newNodeInt = stoi(newNode);
         if (visited[newNodeInt]) continue;
         visited[newNodeInt] = 1;
         counter++;
         string newAns = ans + newNode;
         dfs(newNode, newAns);
		 
		 // backtracking
         visited[newNodeInt] = 0; counter--;
      }
    }
    string crackSafe(int n1, int k1) {
      n = n1, k = k1;
	  // total possible no. combinations = k^n
      total = (int) pow(k, n);
	  
	  // coz we starting at "00..0"
      string init = "";
      for (int i = 0; i < n; i++) init.push_back('0');
	  
	  // base-1 only 1 possible answer
      if (k1 == 1) return init;
      dfs(init, "");
      return finalAns;        
    }
};