/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (45.39%)
 * Total Accepted:    53.9K
 * Total Submissions: 118.7K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string representing an attendance record for a student. The
 * record only contains the following three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A student could be rewarded if his attendance record doesn't contain more
 * than one 'A' (absent) or more than two continuous 'L' (late).    
 * 
 * You need to return whether the student could be rewarded according to his
 * attendance record.
 * 
 * Example 1:
 * 
 * Input: "PPALLP"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "PPALLL"
 * Output: False
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool checkRecord(string s) {
        int i=0;
        int cnta = 0;
        int n = s.size();
        while(i<n){
            if(s[i] == 'P'){ i++; continue; }
            if(s[i] == 'A'){
                i++;
                cnta++;
                if(cnta>1)
                    return false;
                continue;
            }

            char c = s[i];
            int cnt=0;
            while(i<n && s[i]==c)
                i++, cnt++;
            if(cnt>2)
                return false;
        }
        return true;
    }
};
