class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxWater = 0;

        while (left < right) {

            // Calculate width
            int width = right - left;

            // Water level is the smaller height
            int waterHeight = Math.min(height[left], height[right]);

            // Calculate area
            int area = width * waterHeight;

            // Update maximum area
            maxWater = Math.max(maxWater, area);

            // Move the pointer with smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
}