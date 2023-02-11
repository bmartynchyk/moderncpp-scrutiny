# Intuition
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