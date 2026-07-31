#include<bits/stdc++.h>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int number = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i]!= 0){
                nums[number] = nums[i];
                number++;
            }
        }
        while(number<nums.size()){
            nums[number] = 0;
            number++;
        }
    }
};