class Solution {
public:
		string longToIp(long x, int step) {
			int d = (int)(x & 255);
			x >>= 8;

			int c = (int)(x & 255);
			x >>= 8;

			int b = (int)(x & 255);
			x >>= 8;

			int a = (int)(x & 255);

			int count = 0;
			while (step) {
				count++;
				step >>= 1;
			}
			int mask = 32 - (count - 1);
			return to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d) + "/" + to_string(mask);
		}


	    vector<string> ipToCIDR(string ip, int n) {
			long x = 0;
			istringstream ss(ip);
			string cur;
			while (getline(ss, cur, '.')) {
				x = x * 256 + stoi(cur);
			}

			vector<string> result;
			while (n > 0) {
				int step = x & -x; // get rid of all 1s, except the rightmost 1
				if (step == 0) { // Special handling for 0.0.0.0
					step = 1; 
					while (step < n) { step <<= 1; }
				}
				while (step > n) { step >>= 1; }
				result.push_back(longToIp(x, step));
				x += step;
				n -= step;
			}
			return result;
	    }
};
