/*
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (51.88%)
 * Total Accepted:    196.8K
 * Total Submissions: 361.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 *
 *
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		for (auto n: nums) {
			map[n] += 1;
		}

		auto cmp = [](pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

		for (auto &p: map) {
			if (pq.size() < k) {
				pq.push(p);
			} else {
				if (p.second > pq.top().second) {
					pq.pop();
					pq.push(p);
				}
			}
		}

		vector<int> res;
		while (!pq.empty()) {
			auto &next = pq.top();
			res.push_back(next.first);
			pq.pop();
		}

		return res;
    }
};
