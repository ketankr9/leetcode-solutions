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

	unordered_map<int, int> mm;
	int pp(int i, pr& x, pr& y){
		return ( (x.f*6+x.s)*26 + (y.f*6+y.s) )*300 + i;
	}

	pr bd(char c){
		int pos = (int)c - (int)'A';
		return {pos/6, pos%6};
	}

	int callme(int i, string& word, pr x, pr y){
		if(i >= word.size())	return 0;
		
		if(mm.find(pp(i, x, y)) != mm.end())
			return mm[pp(i, x, y)];
		
		pr pos = bd(word[i]);

		int ret = INT_MAX;
		// left
		int d1 = abs(x.f-pos.f) + abs(x.s-pos.s);
		// right
		int d2 = (y.f == -1 ? 0 : (abs(y.f-pos.f) + abs(y.s-pos.s)) );

		return mm[pp(i, x, y)] = min(d1+callme(i+1, word, pos, y), d2+callme(i+1, word, x, pos));
	}

    int minimumDistance(string word) {
        return callme(1, word, bd(word[0]), {-1, -1});
    }
};
// @lc code=end
