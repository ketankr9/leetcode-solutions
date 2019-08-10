/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 *
 * https://leetcode.com/problems/video-stitching/description/
 *
 * algorithms
 * Medium (46.88%)
 * Total Accepted:    9.8K
 * Total Submissions: 20.9K
 * Testcase Example:  '[[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]]\n10'
 *
 * You are given a series of video clips from a sporting event that lasted T
 * seconds.  These video clips can be overlapping with each other and have
 * varied lengths.
 * 
 * Each video clip clips[i] is an interval: it starts at time clips[i][0] and
 * ends at time clips[i][1].  We can cut these clips into segments freely: for
 * example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
 * 
 * Return the minimum number of clips needed so that we can cut the clips into
 * segments that cover the entire sporting event ([0, T]).  If the task is
 * impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
 * Output: 3
 * Explanation: 
 * We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
 * Then, we can reconstruct the sporting event as follows:
 * We cut [1,9] into segments [1,2] + [2,8] + [8,9].
 * Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event
 * [0, 10].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: clips = [[0,1],[1,2]], T = 5
 * Output: -1
 * Explanation: 
 * We can't cover [0,5] with only [0,1] and [0,2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: clips =
 * [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]],
 * T = 9
 * Output: 3
 * Explanation: 
 * We can take clips [0,4], [4,7], and [6,9].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: clips = [[0,4],[2,8]], T = 5
 * Output: 2
 * Explanation: 
 * Notice you can have extra video after the event ends.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= clips.length <= 100
 * 0 <= clips[i][0], clips[i][1] <= 100
 * 0 <= T <= 100
 * 
 * 
 */
class Solution {
public:
    vector<int> mm;
    int callme(int start, int pos, vector<vector<int>>& clips, int end, int n){
        if(start>=end)  return 0;
        if(mm[start]!=-2)
            return mm[start];
        int ans = INT_MAX;
        while(pos<n && clips[pos][0]<=start){
            if(clips[pos][1]>start)
                ans = min(ans, callme(clips[pos][1], pos, clips, end, n));
            pos++;
        }
        return mm[start] = (ans==INT_MAX?INT_MAX:ans+1);
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        auto comp = [](const vector<int>& a, const vector<int>& b){ return a[0]==b[0]?a[1]<b[1]:a[0]<b[0]; };
        sort(clips.begin(), clips.end(), comp);
        int n = clips.size();
        mm.resize(101, -2);
        // for(int i=0; i+1<clips.size(); i++){
        //     if(clips[i])
        // }
        int ret = callme(0, 0, clips, T, n);
        return ret==INT_MAX?-1:ret;
    }
};
