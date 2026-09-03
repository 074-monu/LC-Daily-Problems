class Solution {
public:

    bool allOdd(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 == 0)
                return false;
        }
        return true;
    }
    bool allEven(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2 != 0)
                return false;
        }
        return true;
    }



    bool uniformArray(vector<int>& nums1) {
        if(allOdd(nums1) || allEven(nums1))
            return true;

        int minEl = *min_element(nums1.begin(), nums1.end());
        if(minEl % 2 == 0){
            return false;
        }

        return true;
    }
};




