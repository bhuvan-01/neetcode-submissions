/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> startTime, endTime;
        startTime.reserve(intervals.size());
        endTime.reserve(intervals.size());
        for (auto& in : intervals) {
            startTime.push_back(in.start);
            endTime.push_back(in.end);
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(),   endTime.end());

        int startPtr = 0, endPtr = 0;
        int parallel = 0, maxParallel = 0;
        int n = intervals.size();

        // Process all the start times in order:
        while (startPtr < n) {
            if (startTime[startPtr] < endTime[endPtr]) {
                // need a new room
                parallel++;
                startPtr++;
            } else {
                // one meeting ended → free a room
                parallel--;
                endPtr++;
            }
            maxParallel = max(maxParallel, parallel);
        }

        return maxParallel;
    }
};
