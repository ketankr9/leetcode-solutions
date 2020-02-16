/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 *
 * https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
 *
 * algorithms
 * Hard (55.22%)
 * Likes:    167
 * Dislikes: 5
 * Total Accepted:    4.9K
 * Total Submissions: 8.9K
 * Testcase Example:  '"CAKE"'
 *
 * 
 * 
 * You have a keyboard layout as shown above in the XY plane, where each
 * English uppercase letter is located at some coordinate, for example, the
 * letter A is located at coordinate (0,0), the letter B is located at
 * coordinate (0,1), the letter P is located at coordinate (2,3) and the letter
 * Z is located at coordinate (4,1).
 * 
 * Given the string word, return the minimum total distance to type such string
 * using only two fingers. The distance between coordinates (x1,y1) and (x2,y2)
 * is |x1 - x2| + |y1 - y2|. 
 * 
 * Note that the initial positions of your two fingers are considered free so
 * don't count towards your total distance, also your two fingers do not have
 * to start at the first letter or the first two letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "CAKE"
 * Output: 3
 * Explanation: 
 * Using two fingers, one optimal way to type "CAKE" is: 
 * Finger 1 on letter 'C' -> cost = 0 
 * Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
 * Finger 2 on letter 'K' -> cost = 0 
 * Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
 * Total distance = 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word = "HAPPY"
 * Output: 6
 * Explanation: 
 * Using two fingers, one optimal way to type "HAPPY" is:
 * Finger 1 on letter 'H' -> cost = 0
 * Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
 * Finger 2 on letter 'P' -> cost = 0
 * Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
 * Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
 * Total distance = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "NEW"
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: word = "YEAR"
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= word.length <= 300
 * Each word[i] is an English uppercase letter.
 * 
 */

// @lc code=start
class Solution {
public:
	#define pr pair<int, int>
	#define f first
	#define s second

	int dist(int x, int pos){
		if(x == -1)	return 0;
		return abs(x/6 - pos/6) + abs(x%6 - pos%6);
	}

	int p(int x, int y){
		return x*27 + y+1;
	}

	int callme(int i, string& word, int x, int y, vector<vector<int>>& dp){
		if(i >= word.size())	return 0;
		
		if(dp[i][p(x, y)] != -1)
			return dp[i][p(x, y)];

		int pos = word[i]-'A';
		int d1 = dist(x, pos)+callme(i+1, word, pos, y, dp);
		int d2 = dist(y, pos)+callme(i+1, word, x, pos, dp);
		return dp[i][p(x, y)] = min(d1, d2);
	}

    int minimumDistance(string word) {
    	vector<vector<int>> dp(300, vector<int>(702, -1));
        return callme(1, word, word[0]-'A', -1, dp);
    }
};
// @lc code=end
