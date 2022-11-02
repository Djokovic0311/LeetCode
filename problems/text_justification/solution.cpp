class Solution {
public:
    string spaceJustifier(string str, int maxWidth, int isLast){
        if(str.length() == maxWidth)
            return str;

        int spacesInString = 0; //count total spaces in the line 
        for(int i = 0; i<str.length(); i++){
            if(str[i] == ' ')
                spacesInString++;
        }
        int spacesToBeInserted = maxWidth - str.length();
        if(spacesInString == 0 || isLast == 1){ 
            str.insert(str.length(), spacesToBeInserted,' '); //insert required spaces in right of line ex "do                  "
            return str;
        }
        int eachSlot = spacesToBeInserted / spacesInString; 
        int leftOverSpace = spacesToBeInserted % spacesInString; 
        for(int i = 0; i<str.length(); i++){
            if(str[i] == ' ' && (eachSlot > 0 || leftOverSpace >0 )){ 
                int noOfSpaces = eachSlot + ((leftOverSpace--) > 0 ? 1:0);
                str.insert(i, noOfSpaces , ' '); //inserting spaces
                i+=noOfSpaces;   //increament count with no of spaces inserted each time 
            }

        }
        return str;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result; 
        string output = words[0];
        for (int i = 1; i<words.size(); i++){
            if(output.length() + words[i].length() + 1 <= maxWidth) 
					output += " "+words[i]; 
            
            else{ 
			   
                output = spaceJustifier(output, maxWidth, 0);
                result.push_back(output); 
                output = words[i];
            }
        }
        output = spaceJustifier(output, maxWidth, 1); 
        result.push_back(output);
        return result;        
    }
};