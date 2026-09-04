/* Approach 1: my thinking 
1. write helper functions to find max and min as per the question for specific indexes
2. get te difference stored and keep checking for values less than k
3. if less than k found then llok for smallest index values
4. if found then return ansIdx
5. else return -1*/



class Solution {
public:

    int maxi(vector<int>& nums, int end){
        int maxEl = INT_MIN;
        for(int i=0; i<=end; i++){
            if(nums[i] > maxEl)
                maxEl = nums[i];
        }
        return maxEl;
    }

    int mini(vector<int>& nums, int start){
        int minEl = INT_MAX;
        for(int i=start; i<nums.size(); i++){
            if(nums[i] < minEl)
                minEl = nums[i];
        }
        return minEl;
    }


    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int ansIndex = INT_MAX; bool flag = false;

        for(int i=0; i<n; i++){
            int maxVal = maxi(nums, i);
            int minVal = mini(nums, i);
            int temp = maxVal - minVal;

            if(temp <= k){
                flag = true;
                ansIndex = min(ansIndex, i);
            }
        }

        if(flag){
            return ansIndex;
        }

        return -1;
    }
};



/*===================================================================================================================================================================================================*/

// Approach2: CSWITHMIK

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
