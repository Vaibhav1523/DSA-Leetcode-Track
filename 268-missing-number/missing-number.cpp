class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int allXOR = 0;
       for(int i = 0; i<=nums.size(); i++){
            allXOR = allXOR^i;
       }
        for(int num = 0; num<nums.size(); num++){
            allXOR = allXOR^nums[num];
        }
       return allXOR;
    }
};