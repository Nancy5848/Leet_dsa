#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        // Min-heap to store pairs of {release_time, server_id} for busy servers
        std::priority_queue<std::pair<long long, int>, 
                            std::vector<std::pair<long long, int>>, 
                            std::greater<std::pair<long long, int>>> busy_servers;
        
        // Set to store currently available server IDs
        std::set<int> available_servers;
        for (int i = 0; i < k; ++i) {
            available_servers.insert(i);
        }
        
        std::vector<int> request_count(k, 0);
        int max_requests = 0;
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long curr_time = arrival[i];
            long long duration = load[i];
            
            // Free up servers whose tasks have finished by the current arrival time
            while (!busy_servers.empty() && busy_servers.top().first <= curr_time) {
                available_servers.insert(busy_servers.top().second);
                busy_servers.pop();
            }
            
            // If no servers are available, drop this request
            if (available_servers.empty()) {
                continue;
            }
            
            // Find the first available server >= (i % k)
            int target = i % k;
            auto it = available_servers.lower_bound(target);
            
            // If none found >= target, wrap around and pick the first available from the beginning
            if (it == available_servers.end()) {
                it = available_servers.begin();
            }
            
            int assigned_server = *it;
            available_servers.erase(it);
            
            // Assign task to this server and push to busy heap
            busy_servers.push({curr_time + duration, assigned_server});
            request_count[assigned_server]++;
            max_requests = std::max(max_requests, request_count[assigned_server]);
        }
        
        // Collect all servers that handled the maximum number of requests
        std::vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};