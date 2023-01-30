#pragma once
#include "../subroutines.h"

#include <algorithm>
#include <queue>


/*
* You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

Example 1:

Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
Output: 12
Explanation: 
The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12.
Example 2:

Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
Output: 30
Explanation: 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 105
0 <= nums1[i], nums2[j] <= 105
1 <= k <= n
*/



class problem2 {
	static long long solution1(std::vector<uint16_t> nums1, std::vector<uint16_t> nums2, uint16_t k) {
		if (nums1.size() != nums2.size()) return -1;
		if (1 >= k || k >= nums1.size()) return -1;

		vector<pair<uint16_t, uint16_t> > pairs;

		for (uint8_t i = 0; i < nums1.size(); i++)
			pairs.push_back({ nums1[i], nums2[i] });

		sort(pairs.rbegin(), pairs.rend(), [](auto&& le, auto&& re) {
				if (le.second == re.second) return le.first > re.first;
				return le.second < re.second;
			});

		cout << "Pairs: " << pairs << endl;

		std::priority_queue<uint16_t, vector<uint16_t>, greater<uint16_t> > pq;
		uint32_t sum = 0;
		uint64_t max_score = 0;

		for (const auto& pair : pairs) {
			pq.push(pair.first);
			sum += pair.first;

			cout << pq << endl;

			if (pq.size() > k) {
				sum -= pq.top();
				cout << "On top: " << pq.top();
				pq.pop();
			}

			if (k == pq.size()) {
				max_score = max(max_score, static_cast<uint64_t>(sum*pair.second));
			}
		}
		
		return max_score;
	}

public: 

	static void test_cases() {
		vector<uint16_t> v1 = { 1, 3, 3, 2 };
		vector<uint16_t> v2 = { 2, 1, 3, 4 };
		uint16_t k = 3;
		
		cout << "v1: " << v1 << ";\nv2: " << v2 << ";\nk: " << k << endl;
		cout << "Result: " << solution1(v1, v2, k) << endl;
	}
};

/*
* class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        if (nums1.size() != nums2.size()) return -1;
        if (k < 1 || k > nums1.size()) return 0;

        vector<pair<int, int> > pairs;

        for (int i = 0; i < nums1.size(); i++)
            pairs.push_back({nums1[i], nums2[i]});

        sort(pairs.begin(), pairs.end(), [](auto&& le, auto&& re){
            if (le.second == re.second) return le.first > re.first;
            return le.second < re.second;
        });

        //reverse(pairs.begin(), pairs.end());

        cout << "Sorted pair: \n";
        for (auto& p : pairs)
            cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl;
        
        cout << "Reversed pairs: \n" ;
        for (auto it = pairs.rbegin(); it != pairs.rend(); ++it)
            cout << "(" << it->first << ", " << it->second << ") ";
        cout << endl;

        priority_queue<int, vector<int>, greater<int> > pq;
        long long max_score = 0;
        long long sum = 0;

        //for (auto& p : pairs) {
        for (auto p = pairs.rbegin(); p != pairs.rend(); ++p) {
            pq.push(p->first);
            sum += p->first;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                max_score = max(max_score, sum*p->second);
            }

            priority_queue<int, vector<int>, greater<int> > tmp(pq);
            while(!tmp.empty()) {
                cout << tmp.top() << " ";
                tmp.pop();
            }
            cout << "\tsum = " << sum <<"\tmax_score = " << max_score << endl;
        }

        return max_score;
    }
};
*/