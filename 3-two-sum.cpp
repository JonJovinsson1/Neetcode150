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

/* create a copy of the array/vector with the vector<pair<int,int>> 
A; line and the for loop, adding each value and its position in the
 copied vector to the new vector. <pair> is is pairing/joining the 
 value and position value in the new vector as a small object. 
Sort, sorts the new vector A.
while i is smaller than j, cur is equal to A[i].first, the first 
value in the vector pair (the begin() of the vector A), and A[j].
first is equal to end/last value of the vector (the .end() of A)
if cur equals target, return A[i].second & A[j].second, the indexes 
of the values that add to target.
else if cur is less than target, increase i which will increase the 
total sum,
else decrease j as J's value is end(), as this will decrease the total of sum.
This makes both the left and right point move closer.

time complexity: O(n log n)
space complecity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indicies;

        for (int i = 0; i < nums.size(), i++) {
            indicies[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indicies.count(diff) && indicies[diff] != i) {
                return {i, indicies[diff]};
            }
        }
        return {};
    }
};

/* 
Algebraic way: 
instead of a + b = target
b = target - a

create an unordered map "indicies"
the first for loop is populating the map, with the vector nums value, and i as the index. eg: nums = [10,7,3]
indicies after the first loop 
indicies{10:0,}
second loop:
indicies{10:0, 7:1}
third loop
indicies{10:0, 7:1, 3:2}

then it moves to the next for loop.
diff is declared as "b" or diff = target - nums[i]
if the map is: {10:0, 7:1, 3:2} and i = 2
then nums[i] = 3

the if condition counts the diff, using count() as a safe method to not insert another value into indicies, and checks that indicies[diff] is not equal to i (so it doesnt use the same value twice, lets say for target = 6, using 3 twice when it is at index 2 for example)
 then returns i & indicies[diff] to return the indexes.
 
 time complexity: O(n)
 space complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (prevMap.find(diff) != prevMap.end()) {
                return {prevMap[diff], i};
            }
            prevMap.insert({nums[i],i});
        }
        return {};
    }
};
/*Similar to the above solution, but is only making a single pass.
declare an unordered map called prevMap
for loop iterates for the size of nums, declading diff = target - nums[i]. Inside the for loop, the if statement checks prevMap.find[diff] is not equal to the last value in prevMap and returns the index of prevMap[diff] & i.
*/