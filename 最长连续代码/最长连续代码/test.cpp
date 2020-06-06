#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> num_set;
		for (const int& num : nums) {
			num_set.insert(num);
		}

		int longestStreak = 0;

		for (const int& num : num_set) {
			if (!num_set.count(num - 1)) {
				int currentNum = num;
				int currentStreak = 1;

				while (num_set.count(currentNum + 1)) {
					currentNum += 1;
					currentStreak += 1;
				}

				longestStreak = max(longestStreak, currentStreak);
			}
		}

		return longestStreak;
	}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> hash;
		for (auto e : nums)
			hash[e]++;

		int count = 0;
		int max = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int x = nums[i];
			if (hash.find(x - 1) == hash.end()) {
				while (hash.find(x) != hash.end()) {
					++count;
					++x;
				}
			}

			if (count > max)
				max = count;

			count = 0;
		}

		return max;
	}
};