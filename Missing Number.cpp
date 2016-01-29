// https://leetcode.com/problems/missing-number/
int missingNumber(vector<int>& nums) {
	int n = nums.size();
	int miss = 0;
	for (int i = 0; i<n; i++)
	{
		miss += (i + 1) - nums[i];
	}
	return miss;
}