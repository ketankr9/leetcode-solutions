/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (53.64%)
 * Likes:    418
 * Dislikes: 1296
 * Total Accepted:    80.6K
 * Total Submissions: 150.3K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 * 
 * For each log, the first word in each log is an alphanumeric identifier.
 * Then, either:
 * 
 * 
 * Each word after the identifier will consist only of lowercase letters,
 * or;
 * Each word after the identifier will consist only of digits.
 * 
 * 
 * We will call these two varieties of logs letter-logs and digit-logs.  It is
 * guaranteed that each log has at least one word after its identifier.
 * 
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with the
 * identifier used in case of ties.  The digit-logs should be put in their
 * original order.
 * 
 * Return the final order of the logs.
 * 
 * 
 * Example 1:
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the
 * identifier.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
	bool isalph(string& st){
		int i;
		for(i=0; st[i] != ' '; i++);
		i++; // move ahead of space
		if(st[i] < '0' || st[i] > '9') // isalpha
			return true;
		return false;
	}
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> alph;
        
        for(auto &st: logs)
        	if(isalph(st))
        		alph.push_back(st);
        
        // sort alpha logs
        sort(alph.begin(), alph.end(), [](string& x, string& y){
        	int i = 0, j = 0;
        	while(x[i] != ' ')	i++; i++;
        	while(y[j] != ' ')	j++; j++;

        	while(i<x.size() && j<y.size() && x[i]==y[j])	i++, j++;
        	if(i != x.size() && j != y.size())
        		return x[i] < y[j];
        	if(i == x.size() && j == y.size()){
        		i = 0;
        		while(x[i]!=' ' && y[i]!=' ' && x[i]==y[i]) i++;
        		return x[i] < y[i];
        	}
        	return i==x.size();
        });

        // push remaining numeric logs
        for(auto &st: logs)
        	if(!isalph(st))
        		alph.push_back(st);

        return alph;
    }
};
// @lc code=end
