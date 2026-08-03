class Solution:
    def arrayPairSum(self, nums):
        # Sort the array
        nums.sort()

        # Store the sum of minimum elements
        total = 0

        # Add every alternate element (minimum of each pair)
        for i in range(0, len(nums), 2):
            total += nums[i]

        return total
        