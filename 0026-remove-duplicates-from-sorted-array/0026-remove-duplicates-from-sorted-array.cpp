class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // edge case

        int i = 0; // pointer for placing unique elements
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) { 
                i++;              // move i forward
                nums[i] = nums[j]; // place the new unique element
            }
        }
        return i + 1; // length of unique elements
    }
};
