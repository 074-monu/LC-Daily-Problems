class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int F = 0, sum = 0;
        // 1. find F(0) & sum
        for(int i=0; i<n; i++){
            F += i*nums[i];
            sum += nums[i];
        }

        // 2. use the previous values to determine the new ones.
        int result = F;
        for(int k=0; k<n; k++){
            int newF = F + sum - n*nums[n-1-k]; // used formula to get last elements without rotation
            result = max(result, newF); // get the max values
            F = newF;
        }


        return result;

    }
};
