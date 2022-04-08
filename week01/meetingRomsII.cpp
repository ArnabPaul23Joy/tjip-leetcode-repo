/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {
        // Write your code here
        unordered_multiset<int> strTime;
        unordered_multiset<int> endTime;
        set<int> allIntervalNums;
        for (int i = 0; i < intervals.size(); i++)
        {
            strTime.insert(intervals[i].start);
            endTime.insert(intervals[i].end);
            allIntervalNums.insert(intervals[i].start);
            allIntervalNums.insert(intervals[i].end);
        }
        int maxConcurrentMeeting = 0, concurrentMeeting = 0;

        set<int>::iterator it;
        for (it = allIntervalNums.begin(); it != allIntervalNums.end(); it++)
        {
            int strtCount = strTime.count(*it);
            int endCount = endTime.count(*it);
            concurrentMeeting = concurrentMeeting + strtCount - endCount;
            maxConcurrentMeeting = max(maxConcurrentMeeting, concurrentMeeting);
        }
        return maxConcurrentMeeting;
    }
};