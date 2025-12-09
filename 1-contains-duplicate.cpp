
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

/* a class is declared (Solution), and inside its public scope a function with a return type of a boolean is declared. The function then declares nums as a reference to a vector of integers. using the ampersand allows to pass by reference and not by value. This means if you are changing values in the function it will change the value outside the function too.

NOTE:
    If you are changing values with a function, then do NOT use an ampersand.

This is brute force method. Lazy, not complex and not optimal.
Time complexity of O(n^2)
Space complexity O(1)
 */ 

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1; i<nums.size();i++){
            if(nums[i]==nums[i-1]) {
                return true;
            }
        }
        return false;
    }
 };
 
 /* This sorts the array before value checking. "i" starts at 1 so there is not an out of index error with the nums[i-1] if condition.
 Time complexity = O(n log n)
 Space complexity = O(1 or n) depending on algorithm.
 */

class Solution {
public:
    bool hasDuplicate(vector<int>& nums){
        unordered_set<int> seen;
        for(int num : nums){
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};