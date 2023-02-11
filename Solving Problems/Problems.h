
#include <iostream>
#include <vector>
#include <unordered_map>
#include "subroutines.h"


#include "Medium problems/problem2.h"

class Problem1 : public CoreProblem {
    // Given an array of integers numsand an integer target, return indices of the two numbers such that they add up to target.
    // You may assume that each input would have exactly one solution, and you may not use the same element twice.
    // You can return the answer in any order.
    
    // Example 1:
    // Input: nums = [2, 7, 11, 15], target = 9
    // Output : [0, 1]
    // Explanation : Because nums[0] + nums[1] == 9, we return[0, 1].
    // 
    // Example 2 :
    // Input : nums = [3, 2, 4], target = 6
    // Output : [1, 2]
    // 
    // Example 3 :
    // Input : nums = [3, 3], target = 6
    // Output : [0, 1]

    //Constraints :

    // 2 <= nums.length <= 104
    // - 109 <= nums[i] <= 109
    // - 109 <= target <= 109
    // Only one valid answer exists.

    // Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity ?

public:
    static std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int spread = 0;

        std::unordered_map<int, int> keys;

        for (int i = 0; i < nums.size(); i++) {
            spread = target - nums[i];

            if (keys.count(spread) > 0)
                return std::vector<int> { keys[spread], i };

            keys[nums[i]] = i;
        }

        return {-1, -1};
    }
    
    static void test_twoSum() {
        int target = 0;
        std::vector<int> v1{ 1, 2, 3, 5, 4, 5 },
            v2{ 3, 12, 11, 4 },
            v3{ 2, 7, 3, 88 };
        
        std::cout << "Target: ";
        std::cin >> target;
        std::cout << "Input: " << v1 << std::endl;
        std::cout << "Output: " << twoSum(v1, target) << std::endl;
        std::cout << "Input: " << v2 << std::endl;
        std::cout << "Output: " << twoSum(v2, target) << std::endl;
        std::cout << "Input: " << v3 << std::endl;
        std::cout << "Output: " << twoSum(v3, target) << std::endl;
    }

    //static void testCases() {

    //}

};






/*
* class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string buff = "";
        stack<string> results;
        bool over = false;

        auto shortest = std::min_element(strs.begin(), strs.end(), [](const auto& a, const auto& b){ 
            return a.length() < b.length(); });
        string shortest_str = *shortest;

        std::cout << shortest_str << std::endl;
        results.push("");

        for (int i = 0; i < shortest_str.size(); i++) {
            buff += shortest_str[i];
            results.push(buff);

            for (int j = 0; j < strs.size(); j++) {
                for(int k = 0; k < buff.size(); k++)
                if (buff[k] != strs[j][k])
                {
                    std::cout << results.top() << std::endl;

                    results.pop();
                    over = false;
                    return results.top();
                }
            }
        }

        return "";
    }
};
*/

/*
* class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) { // Move by each of string in vector.
            int j = 0;

            while (j < prefix.length() && // If not out of range for prefix &&
                    j < strs[i].length() && // If not out of range for compared value &&
                    prefix[j] == strs[i][j]) { // And if elements equals.
                j++; // Then compare with next element.
            }

            prefix = prefix.substr(0, j); // Trim prefix if there are fewer matches then earlier.
            if (prefix.empty()) return "";
        }

        return prefix;
    }
};
*/

/*
* # Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) { // Move by each of string in vector.
            int j = 0;

            while (j < prefix.length() && // If not out of range for prefix &&
                    j < strs[i].length() && // If not out of range for compared value &&
                    prefix[j] == strs[i][j]) { // And if elements equals.
                j++; // Then compare with next element.
            }

            prefix = prefix.substr(0, j); // Trim prefix if there are fewer matches then earlier.
            if (prefix.empty()) return "";
        }

        return prefix;
    }
};
```
*/