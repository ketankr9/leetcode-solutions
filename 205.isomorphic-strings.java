/*
 * @lc app=leetcode id=205 lang=java
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (37.78%)
 * Total Accepted:    215.7K
 * Total Submissions: 570.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> mm = new HashMap<Character, Character>();
        HashSet<Character> p = new HashSet<Character>();
        for(int i=0; i<s.length(); i++){
        	
        	if(mm.containsKey(s.charAt(i)) && !mm.get(s.charAt(i)).equals(t.charAt(i)))	return false;
			       
        	if(!mm.containsKey(s.charAt(i)) && p.contains(t.charAt(i)))	return false;
        	
        	mm.put(s.charAt(i), t.charAt(i));
        	p.add(t.charAt(i));
        }
        return true;
    }
}
