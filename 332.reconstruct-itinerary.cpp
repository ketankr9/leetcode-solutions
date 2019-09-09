/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (32.05%)
 * Total Accepted:    86.5K
 * Total Submissions: 269.9K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * Note:
 * 
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 * 
 * 
 */
class Solution {
public:
	vector<string> gans, lans;
	int k;
	void callme(string start, unordered_map<string,vector<pair<string, bool>>>& mm){
		if(!gans.empty())	return;
		if(lans.size() == k){
			if(gans.empty()){
				lans.push_back(start);
				gans = lans;
				lans.pop_back();
			}
			return;
		}

		if(mm.find(start)==mm.end())	return;
		for(auto &m: mm[start]){
			if(m.second)	continue;
			m.second = true;
			lans.push_back(start);
			callme(m.first, mm);
			m.second = false;
			lans.pop_back();
		}
	}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    	k = tickets.size();
    	gans.clear(); lans.clear();
        unordered_map<string,vector<pair<string, bool>>> mm;
        for(auto const& t: tickets)
        	mm[t[0]].push_back({t[1], false});
        for(auto &m: mm)
        	sort(m.second.begin(), m.second.end(), 
        		[](const pair<string, bool> &p1, const pair<string, bool> &p2)
        		{
        			return p1.first < p2.first;
        		});

        callme("JFK", mm);
        return gans;
    }
};
