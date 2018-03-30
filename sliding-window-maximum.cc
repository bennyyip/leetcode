// dequeue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &a, int k) {
        int n = a.size();
        vector<int> r;
	// invariant: q is incr
        deque<int> q;
        for (int i = 0; i < n; ++i) {

            // remove the expired one
            if (!q.empty() && q.front() <= i - k)
                q.pop_front();

	    // remove all elements that is smaller than the current one from back.
            while (!q.empty() && a[q.back()] < a[i])
                q.pop_back();

            q.push_back(i);

            if (i >= k - 1)
                r.push_back(a[q.front()]);
        }
        return r;
    }
};

// heap
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // value, index
        priority_queue<pair<int, int>> Q;
        vector<int> r;
        if (nums.size() < 1)
            return r;
        for (int i = 0; i < k; ++i)
            Q.push(make_pair(nums[i], i));

        r.push_back(Q.top().first);

        for (int i = k; i < nums.size(); ++i) {
            Q.push(make_pair(nums[i], i));
            for (;;) {
                pair<int, int> top = Q.top();
                if (top.second > i - k) {
                    r.push_back(top.first);
                    break;
                } else {
                    Q.pop();
                }
            }
        }

        return r;
    }
};
