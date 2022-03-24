class Solution {
public:
    bool validUtf8(vector<int>& data) {
	int conts = 0;
	for(int i = 0; i < data.size(); i++) {
		if(conts--) { if ((data[i] & 0xC0) != 0x80) return false; }
		else if((data[i] & 0xF8) == 0xF0) conts = 3;
		else if((data[i] & 0xF0) == 0xE0) conts = 2;
		else if((data[i] & 0xE0) == 0xC0) conts = 1;
		else if((data[i] & 0x80) == 0x00) conts = 0;
		else return false;
	}
	return !conts;        
    }
};