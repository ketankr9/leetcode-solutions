/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (22.92%)
 * Likes:    1432
 * Dislikes: 799
 * Total Accepted:    259.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ladder = 1;
        queue<string> q;
        unordered_set<string> ss;
        for(auto e: wordList)
            ss.insert(e);
        q.push(beginWord);
        while(!q.empty()){
            queue<string> tmp;
            while(!q.empty()){
                string word;// = q.front(); q.pop();
                if(q.front() == endWord)
                    return ladder;
                for(int k=0; k<(int)q.front().size(); k++){
                    word = q.front();
                    for(int i=0; i<26; i++){
                        word[k] = ('a'+i);
                        if(ss.find(word)!=ss.end()){
                            tmp.push(word);
                            ss.erase(word);
                        }
                    }
                }
                q.pop();
            }
            ladder++;
            q = tmp;
        }
        return 0;
    }
};

