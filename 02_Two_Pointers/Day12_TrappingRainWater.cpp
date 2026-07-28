/**
 * @file Day12_TrappingRainWater.cpp
 * @author Vaibhav Verma (https://github.com/Vaibhav1523)
 * @brief LeetCode 42: Trapping Rain Water
 * @difficulty Hard
 * 
 * @approach Two Pointers Optimal
 * - Move left and right pointers towards center.
 * - Track left_max and right_max. Accumulate water dynamically.
 * 
 * @complexity
 * - Time Complexity:  O(N)
 * - Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int trap(const std::vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;
        
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total_water += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total_water += right_max - height[right];
                }
                right--;
            }
        }
        
        return total_water;
    }
};

int main() {
    Solution sol;
    std::vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    assert(sol.trap(h) == 6);
    std::cout << "✅ Day 12 Trapping Rain Water Passed!" << std::endl;
    return 0;
}
