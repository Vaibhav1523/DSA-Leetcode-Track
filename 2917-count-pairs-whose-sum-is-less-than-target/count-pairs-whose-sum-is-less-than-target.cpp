class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n-1;
        while(r>l){
            if(nums[l] + nums[r]<target){
                res+=r-l;
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};