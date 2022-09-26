class Solution {
public:
    //Find Parent function
 	int find(char x, unordered_map<char, char>& parent) {
 		if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
 	}
    
    //Main Problem Solver Function
    bool equationsPossible(vector<string>& equations) {
        
        //Mapping each char with itself, 
        //meaning assigning each character parent of itself.
        unordered_map<char, char> parent;
        for(auto x: equations){
            parent[x[0]] = x[0];
            parent[x[3]] = x[3];
        }
        
        //Idea here is simple if two characters "are equal (==)" we are 
        //basically grouping/union-ing them together by assigning the 
        //left side character as parent of the right side character. 
        for(auto it: equations){
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '=') parent[y] = x; //union
        }
        
        //Now here what we are simply doing is that we are checking if 
        //some character is "not equal (!=)" to other but their parent 
        //are same, that means that is the "imposter" equation.
        for(auto it: equations){
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '!' && x==y) return false;
        }
            
        //If everything is fine...
        return true;
    }
};