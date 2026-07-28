/**
 * @file Day01_TwoSum.cpp
 * @author Vaibhav Verma (https://github.com/Vaibhav1523)
 * @brief LeetCode 1: Two Sum
 * @difficulty Easy
 * 
 * @approach Hash Map One-Pass
 * - Store visited element and its index in hash map.
 * - For current element, check if target - current exists in map.
 * 
 * @complexity
 * - Time Complexity:  O(N)
 * - Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (mp.count(comp)) {
                return {mp[comp], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> res = sol.twoSum(nums, 9);
    assert((res == std::vector<int>{0, 1}));
    std::cout << "✅ Day 01 Two Sum Passed!" << std::endl;
    return 0;
}
