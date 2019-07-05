/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 *
 * https://leetcode.com/problems/employee-importance/description/
 *
 * algorithms
 * Easy (54.39%)
 * Total Accepted:    47.9K
 * Total Submissions: 88K
 * Testcase Example:  '[[1,2,[2]], [2,3,[]]]\n2'
 *
 * You are given a data structure of employee information, which includes the
 * employee's unique id, his importance value and his direct subordinates' id.
 * 
 * For example, employee 1 is the leader of employee 2, and employee 2 is the
 * leader of employee 3. They have importance value 15, 10 and 5, respectively.
 * Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has
 * [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3
 * is also a subordinate of employee 1, the relationship is not direct.
 * 
 * Now given the employee information of a company, and an employee id, you
 * need to return the total importance value of this employee and all his
 * subordinates.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
 * Output: 11
 * Explanation:
 * Employee 1 has importance value 5, and he has two direct subordinates:
 * employee 2 and employee 3. They both have importance value 3. So the total
 * importance value of employee 1 is 5 + 3 + 3 = 11.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * One employee has at most one direct leader and may have several
 * subordinates.
 * The maximum number of employees won't exceed 2000.
 * 
 * 
 * 
 * 
 */
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> imp;
    unordered_set<int> visited;
    int callme(int id, vector<Employee*> employees){
        int ans = 0;
        for(auto e: employees){
            if(e->id == id){
                // ans += e->importance;
                for(auto s: e->subordinates){
                    if(visited.count(s)!=0) continue;
                    ans += imp[s];
                    visited.insert(s);
                    ans += callme(s, employees);
                }
            }
        }
        return ans;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        imp.clear();
        visited.clear();
        for(auto e: employees)
            imp[e->id] = e->importance;
        visited.insert(id);
        return callme(id, employees) + imp[id];
        // return ans;
    }
};
