/* *题目：
 *  56
 *  Merge Intervals
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> res;
        for(int i = 0; i < intervals.size(); i++){
            Interval tmp = intervals[i];
            while(i+1 < intervals.size() && mergeTwo(tmp, intervals[i+1], tmp)){
                i++;
            }
            res.push_back(tmp);
        }
        
        return res;
    }
    
    bool mergeTwo(Interval& a, Interval& b, Interval& c) {
        if(a.end < b.start){
            return false;
        }
        
        c.start = min(a.start, b.start);
        c.end = max(a.end, b.end);
        return true;
    }
    
    static bool cmp(Interval& a, Interval& b) {
        return a.start < b.start;
    }
};