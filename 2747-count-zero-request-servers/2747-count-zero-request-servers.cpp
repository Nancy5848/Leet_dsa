#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        // Store queries with their original indices: {query_time, original_index}
        vector<pair<int, int>> q(m);
        for (int i = 0; i < m; ++i) {
            q[i] = {queries[i], i};
        }
        
        // Sort queries by time
        sort(q.begin(), q.end());
        
        // Sort logs by time
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        unordered_map<int, int> server_count;
        int l = 0, r = 0;
        int num_logs = logs.size();
        
        for (int i = 0; i < m; ++i) {
            int query_time = q[i].first;
            int orig_idx = q[i].second;
            int window_start = query_time - x;
            int window_end = query_time;
            
            // Add logs that fall up to window_end
            while (r < num_logs && logs[r][1] <= window_end) {
                server_count[logs[r][0]]++;
                r++;
            }
            
            // Remove logs that are strictly before window_start
            while (l < num_logs && logs[l][1] < window_start) {
                server_count[logs[l][0]]--;
                if (server_count[logs[l][0]] == 0) {
                    server_count.erase(logs[l][0]);
                }
                l++;
            }
            
            // Servers with zero requests = total servers (n) - servers with at least one request
            ans[orig_idx] = n - server_count.size();
        }
        
        return ans;
    }
};