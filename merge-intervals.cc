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
    vector<Interval> merge(vector<Interval> &v) {
        vector<Interval> r;
        sort(v.begin(), v.end(),
             [](Interval a, Interval b) { return a.start < b.start; });

        for (auto x : v) {
            if (r.empty() || x.start > r.back().end)
                r.push_back(x);
            else {
                r.back().start = min(x.start, r.back().start);
                r.back().end = max(x.end, r.back().end);
            }
        }
	return r;
    }
};
