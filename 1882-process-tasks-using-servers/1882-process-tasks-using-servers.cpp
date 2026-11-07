#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        // Available servers min-heap: stores {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        
        // Unavailable servers min-heap: stores {free_time, weight, index}
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
        
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        long long currentTime = 0;
        
        for (int j = 0; j < m; ++j) {
            currentTime = max(currentTime, (long long)j);
            
            // If no servers are free, jump time to the next available server
            if (freeServers.empty() && !busyServers.empty()) {
                currentTime = max(currentTime, get<0>(busyServers.top()));
            }
            
            // Release all servers that finish by currentTime
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, index});
            }
            
            // Assign the task to the best available server
            auto [weight, index] = freeServers.top();
            freeServers.pop();
            
            ans[j] = index;
            busyServers.push({currentTime + tasks[j], weight, index});
        }
        
        return ans;
    }
};