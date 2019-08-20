/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (48.12%)
 * Total Accepted:    86.5K
 * Total Submissions: 179.7K
 * Testcase Example:  '[["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
	double ans;
	void callme(double cur, string num, string end, unordered_map<string, vector<pair<string, double>>>& mm, unordered_set<string>& ss){
		// cout<<num<<":"<<end<<endl;
		if(ss.count(num)!=0)	return;
		if(end == num){
			ans = cur;
			return;
		}

		if(mm.find(num)==mm.end())	return;
		ss.insert(num);
		for(auto deno: mm[num])
			callme(cur*deno.second, deno.first, end, mm, ss);
		ss.erase(num);
	}

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& queries) {
	    unordered_map<string, vector<pair<string, double>>> mm;

	    for (int i = 0; i < (int)eq.size(); ++i){
	    	mm[eq[i][0]].push_back(make_pair(eq[i][1], val[i]));
	    	mm[eq[i][1]].push_back(make_pair(eq[i][0], (double)1.0/val[i]));
	    }
	    vector<double> ret;
	    for(auto q: queries){
    		if(mm.find(q[0])==mm.end()  || mm.find(q[1])==mm.end()){
    			ret.push_back(-1.0);
    			continue;
    		}

	    	ans = INT_MAX;
	    	unordered_set<string> ss;
	    	callme(1.0, q[0], q[1], mm, ss);
	    	if(ans == INT_MAX){
	    		ss.clear();
	    		callme(1.0, q[1], q[0], mm, ss);
	    		ret.push_back(ans==INT_MAX?-1.0:(1.0/ans));
	    	}else
	    		ret.push_back(ans);
	    	// cout<<ans<<" ";
	    }

	    return ret;
    }
};
