/**
 * @file SolutionTemplate.cpp
 * @author Vaibhav Verma (https://github.com/Vaibhav1523)
 * @brief Production C++ Template for LeetCode / DSA Problem Solving
 * 
 * Target: Google / Amazon / Meta Technical Interview Standard
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cassert>

class Solution {
public:
    /**
     * @brief Problem Solution Method
     * 
     * @param nums Input array
     * @param target Target value
     * @return std::vector<int> Result indices/values
     * 
     * @complexity
     * - Time Complexity:  O(N) -> Single pass algorithm
     * - Space Complexity: O(N) -> Hash map auxiliary storage
     */
    std::vector<int> solve(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

// ================= AUTOMATED UNIT TESTS =================
void runTestSuite() {
    Solution sol;
    
    // Test Case 1: Standard Case
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> expected1 = {0, 1};
    assert(sol.solve(nums1, target1) == expected1);
    
    // Test Case 2: Duplicate Values
    std::vector<int> nums2 = {3, 3};
    int target2 = 6;
    std::vector<int> expected2 = {0, 1};
    assert(sol.solve(nums2, target2) == expected2);
    
    std::cout << "✅ [C++] All Unit Test Cases Passed!" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    runTestSuite();
    return 0;
}
