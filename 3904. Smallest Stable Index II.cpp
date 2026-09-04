// optimized


class Solution {
public:

    //1. we can get the max value on the go up to index i
    //2. we can pre process the min values from i to end and can save it in an array, back propagation will help storing

    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // pre processing of min from index in an array
        int minEl = INT_MAX;
        vector<int>minFromIdx(n);
        for(int i=n-1; i>=0; i--){
            minEl = min(minEl, nums[i]);
            minFromIdx[i] = minEl;
        }

        // 2. iterate on each index to get first stable value
        int maxEl = INT_MIN;
        for(int i=0; i<n; i++){
            maxEl = max(maxEl, nums[i]);

            if(maxEl - minFromIdx[i]  <= k){
                 // no need to check for smallest index because we are traversing from left to right so wherever this condition matches first that will be the smallest index
                return i;
            }

        }

        // if not found 
        return -1;
    
    }
};


//  TC Optimized from O(N^2) to O(N)
