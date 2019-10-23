
class Solution {
public:
	string reverseStr(string s, int k) {
		string::iterator it = s.begin();
		while ((it < s.end()) && (s.end() > (it + k)))
		{
			reverse(it, it + k);
			it += 2 * k;
		}
		if (s.end() <= (it + k))
			reverse(it, s.end());
		return s;
	}
};