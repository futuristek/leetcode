/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 *
 * https://leetcode.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (31.32%)
 * Total Accepted:    51.7K
 * Total Submissions: 165.1K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * Given two strings A and B, find the minimum number of times A has to be
 * repeated such that B is a substring of it. If no such solution, return -1.
 * 
 * For example, with A = "abcd" and B = "cdabcdab".
 * 
 * Return 3, because by repeating A three times (“abcdabcdabcd”), B is a
 * substring of it; and B is not a substring of A repeated two times
 * ("abcdabcd").
 * 
 * Note:
 * The length of A and B will be between 1 and 10000.
 * 
 */
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int ai = 0, bi = 0, count = 1;
        int aj = ai + 1;
        auto rA = A;

        while (rA.size() < B.size()) {
            rA.append(A);
            count++;
        }
        
        while (bi < B.size() && (ai < A.size() + B.size())) {
            if (ai == rA.size()) {
                rA.append(A);
                count++;
            }

            if (rA[ai] == B[bi]) {
                bi++;
                ai++;
            } else {
                bi = 0;
                ai = aj;
                aj++;
            }
        }

        return (bi == B.size() ? count : -1);
    }
};