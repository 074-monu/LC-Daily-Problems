class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // case1: if all odd => diretly copy => valid
        // case2: if all even => directly copy => valid
        // case3: odd even mix => can be made all odd => if all evens were subtracted by odd
        /*
            odd - odd = even
            even - odd = odd => this can be used to make all odd

        */

        // answer is always true
        return true;
    }
};
