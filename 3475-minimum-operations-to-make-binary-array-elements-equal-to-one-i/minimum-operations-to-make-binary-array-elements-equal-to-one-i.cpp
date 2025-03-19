class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int n = nums.size();
        int i = 0;

        while (i <= n - 3) {
            if (nums[i] == 0) {
                // Flip next three elements
                for (int j = i; j < i + 3; j++) {
                    nums[j] = 1 - nums[j];
                }
                operations++;
            }
            i++;
        }

        // Check if last two elements are also ones
        return (nums[n - 1] == 1 && nums[n - 2] == 1) ? operations : -1;
    }
};
