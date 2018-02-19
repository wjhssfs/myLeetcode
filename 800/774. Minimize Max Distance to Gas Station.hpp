// 774. Minimize Max Distance to Gas Station

// On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

// Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

// Return the smallest possible value of D.

// Example:

// Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
// Output: 0.500000
// Note:

// stations.length will be an integer in range [10, 2000].
// stations[i] will be an integer in range [0, 10^8].
// K will be an integer in range [1, 10^6].
// Answers within 10^-6 of the true value will be accepted as correct.

class Solution {
    int getK(vector<int> diffs, double can) {
        int res = 0;
        for (auto diff : diffs) {
            int cur = diff / can;
            if (diff / can > cur) ++cur;
            res += cur - 1;
        }
        //cout << can << " " << res << endl;
        return res;
    }
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        vector<int> diffs;
        double low = 0, high = INT_MIN;
        for (int i = 1; i < stations.size(); ++i) {
            diffs.push_back(stations[i] - stations[i - 1]);
            high = max((int)high, diffs.back());
        }
        while (high - low > 0.000001) {
            double mid = (high + low) / 2.0;
            int kp = getK(diffs, mid);
            if (kp > K) {
                low = mid + 0.000001;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        priority_queue<pair<double, double>> pq;
        for (int i = 1; i < stations.size(); ++i) {
            pq.emplace((double)stations[i] - stations[i - 1], -1.0);
        }
        while (K > 0) {
            auto top = pq.top(); pq.pop();
            top.first = top.first * (-top.second) / (-top.second + 1);
            --top.second;
            pq.emplace(top);
            --K;
        }
        return pq.top().first;
    }
};