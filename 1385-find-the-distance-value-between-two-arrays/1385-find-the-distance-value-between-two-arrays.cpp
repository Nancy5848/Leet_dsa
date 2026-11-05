class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;

        for (int x : arr1) {
            // Find the first element in arr2 that is >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // Check if the found element is outside the range [x - d, x + d]
            // If it's >= arr2.end() or strictly greater than x + d, no element falls in the range
            if (it == arr2.end() || *it > x + d) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};