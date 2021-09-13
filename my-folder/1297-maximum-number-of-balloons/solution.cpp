class Solution {
public:
    int maxNumberOfBalloons(string text) {
	int b = 0;
	int a = 0;
	int l = 0;
	int o = 0;
	int n = 0;

	for (auto c: text) {
		switch (c) {
			case 'b':
				b++;
				break;
			case 'a':
				a++;
				break;
			case 'l':
				l++;
				break;
			case 'o':
				o++;
				break;
			case 'n':
				n++;
				break;
		}
	}

	int balloons = b;
	balloons = min(balloons, a);
	balloons = min(balloons, l / 2);
	balloons = min(balloons, o / 2);
	balloons = min(balloons, n);

	return balloons;
    }
};
