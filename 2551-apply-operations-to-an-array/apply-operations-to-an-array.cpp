#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        int n = nums.size();

       
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        
        std::vector<int> result;
        for (int num : nums) {
            if (num != 0) {
                result.push_back(num);
            }
        }
        result.insert(result.end(), nums.size() - result.size(), 0);

        return result;
    }
};