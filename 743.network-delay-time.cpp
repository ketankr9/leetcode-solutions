/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (43.83%)
 * Total Accepted:    44.9K
 * Total Submissions: 102.4K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */
class Solution {
public:
	typedef unordered_set<int> us;
	typedef unordered_map<int, int> um;
	typedef vector<int> vv;
	typedef pair<int, int> pr;
	#define s second
	#define f first
	struct comp{
		bool operator()(pr t1, pr t2){
			return t1.f < t2.f;
		}
	};
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        us visited;
        vv dist(N, INT_MAX);
        unordered_map<int, vector<pr>> mm;
        for(auto const& e: times)
        	mm[e[0]].push_back({e[1], e[2]});
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({0, K});
        dist[K-1] = 0;
        while(!pq.empty()){
        	pr top = pq.top(); pq.pop();
        	if(visited.count(top.s)!=0)	continue;
        	visited.insert(top.s);
        	for(auto const& e: mm[top.s]){
        		if(visited.count(e.f)!=0)	continue;
        		dist[e.f-1] = min(dist[e.f-1], top.f+e.s);
        		pq.push({top.f+e.s, e.f});
        	}
        }
        int ans = 0;
        for(auto const &e: dist)
        	ans = max(ans, e);
        return ans == INT_MAX?-1:ans;
    }
};
