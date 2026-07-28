/**
 * @file SolutionTemplate.java
 * @author Vaibhav Verma (https://github.com/Vaibhav1523)
 * @brief Production Java Template for LeetCode / DSA Problem Solving
 * 
 * Target: Google / Amazon / Meta Technical Interview Standard
 */

import java.util.HashMap;
import java.util.Map;
import java.util.Arrays;

public class SolutionTemplate {

    /**
     * @brief Core Algorithm Implementation
     * 
     * @param nums Input array
     * @param target Target sum
     * @return int[] Indices of the two numbers adding to target
     * 
     * @complexity
     * - Time Complexity:  O(N) -> Linear sweep with HashMap lookup
     * - Space Complexity: O(N) -> Extra memory for frequency table
     */
    public int[] solve(int[] nums, int target) {
        if (nums == null || nums.length < 2) {
            return new int[]{};
        }

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return new int[]{};
    }

    // ================= AUTOMATED UNIT TESTS =================
    public static void main(String[] args) {
        SolutionTemplate sol = new SolutionTemplate();

        // Test Case 1
        int[] result1 = sol.solve(new int[]{2, 7, 11, 15}, 9);
        assert Arrays.equals(result1, new int[]{0, 1}) : "Test Case 1 Failed!";

        // Test Case 2
        int[] result2 = sol.solve(new int[]{3, 2, 4}, 6);
        assert Arrays.equals(result2, new int[]{1, 2}) : "Test Case 2 Failed!";

        System.out.println("✅ [Java] All Unit Test Cases Passed!");
    }
}
