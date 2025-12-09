class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size()l i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

/* Brute force, nothing fancy. 
time complexity O(N^2)
space complexity O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0;; i <nums.size(); i++) {
            A.push_back({nums[i], i})
        }

        sort(A.begin(), A.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = A[i].first + A[j].first;
            if (cur == target) {
                return {min(A[i].second, A[j].second),
                max(A[i].second), A[j].second}
            } else if (cur < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

/* 
*/