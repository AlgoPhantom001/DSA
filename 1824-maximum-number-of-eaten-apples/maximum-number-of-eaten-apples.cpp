#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // Min-heap storing pairs of {rot_day, apple_count}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int n = apples.size();
        int eaten = 0;
        int i = 0;
        
        // Continue as long as we are within the first n days OR there are still apples left
        while (i < n || !pq.empty()) {
            // 1. If we are within the first n days, add today's harvest to the queue
            if (i < n && apples[i] > 0) {
                // They rot on day: i + days[i]
                pq.push({i + days[i], apples[i]});
            }
            
            // 2. Discard all batches of apples that have already rotted
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            
            // 3. Eat one apple from the batch that rots the soonest
            if (!pq.empty()) {
                auto [rot_day, count] = pq.top();
                pq.pop();
                
                eaten++;
                count--;
                
                // If there are still apples left in this batch, push them back
                if (count > 0) {
                    pq.push({rot_day, count});
                }
            }
            
            i++;
        }
        
        return eaten;
    }
};