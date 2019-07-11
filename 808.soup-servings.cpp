/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 *
 * https://leetcode.com/problems/soup-servings/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    99
 * Dislikes: 352
 * Total Accepted:    6.4K
 * Total Submissions: 16.9K
 * Testcase Example:  '50'
 *
 * There are two types of soup: type A and type B. Initially we have N ml of
 * each type of soup. There are four kinds of operations:
 * 
 * 
 * Serve 100 ml of soup A and 0 ml of soup B
 * Serve 75 ml of soup A and 25 ml of soup B
 * Serve 50 ml of soup A and 50 ml of soup B
 * Serve 25 ml of soup A and 75 ml of soup B
 * 
 * 
 * When we serve some soup, we give it to someone and we no longer have it.
 * Each turn, we will choose from the four operations with equal probability
 * 0.25. If the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as we can.  We stop once we no longer have
 * some quantity of both types of soup.
 * 
 * Note that we do not have the operation where all 100 ml's of soup B are used
 * first.  
 * 
 * Return the probability that soup A will be empty first, plus half the
 * probability that A and B become empty at the same time.
 * 
 * 
 * 
 * 
 * Example:
 * Input: N = 50
 * Output: 0.625
 * Explanation: 
 * If we choose the first two operations, A will become empty first. For the
 * third operation, A and B will become empty at the same time. For the fourth
 * operation, B will become empty first. So the total probability of A becoming
 * empty first plus half the probability that A and B become empty at the same
 * time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 0 <= N <= 10^9. 
 * Answers within 10^-6 of the true value will be accepted as correct.
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, double> > mm;
    double callme(int depth, int a, int b){
        if(a == 0 && b == 0){
            return 0.5; //*pow(0.25, depth);
        }
        if(a == 0 || b == 0){
            if(a == 0)
                return 1; //pow(0.25, depth);
            return 0;
        }
        if(mm.find(a)!=mm.end() && mm[a].find(b)!=mm[a].end())
            return mm[a][b];
        double ans = 0;
        ans += 0.25*callme(depth+1, a - min(a,100), b);
        ans += 0.25*callme(depth+1, a - min(a, 75), b - min(b, 25));
        ans += 0.25*callme(depth+1, a - min(a, 50), b - min(b, 50));
        ans += 0.25*callme(depth+1, a - min(a, 25), b - min(b, 75));
        mm[a][b] = ans;
        return ans;
    }
    double soupServings(int N) {
        if(N>4800)
            return 1;
        mm.clear();
        return callme(0, N, N); // A, B
    }
};

