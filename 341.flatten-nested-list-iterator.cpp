/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (48.56%)
 * Total Accepted:    118.3K
 * Total Submissions: 243.5K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns
 * false, 
 * the order of elements returned by next should be: [1,4,6].
 * 
 * 
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
	stack<NestedInteger> st;
    void flattenFront(){
    	vector<NestedInteger> tmp = st.top().getList(); st.pop();
		for(int i=(int)tmp.size()-1; i>=0; i--)
        	st.push(tmp[i]);
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
     	for(int i=(int)nestedList.size()-1; i>=0; i--)
        	st.push(nestedList[i]);
    }

    int next() {
    	while(!st.top().isInteger())
        	flattenFront();
        int top = st.top().getInteger(); st.pop();
        return top;
    }

    bool hasNext() {
    	while(!st.empty() && !st.top().isInteger())
        	flattenFront();
        return !st.empty() && st.top().isInteger();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
