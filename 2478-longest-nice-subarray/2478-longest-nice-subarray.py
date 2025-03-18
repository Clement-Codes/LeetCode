class Solution:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        max_length = 1  # Track the maximum nice subarray length found

        for start in range(len(nums) - max_length):
            current_length = 1  # Length of current nice subarray
            used_bits = nums[start]  # Track which bits are used in our subarray

            # Try to extend the subarray
            for end in range(start + 1, len(nums)):
                # If no bits overlap between current number and used bits, we can extend
                if (used_bits & nums[end]) == 0:
                    used_bits |= nums[
                        end
                    ]  # Add new number's bits to our tracker
                    current_length += 1
                # If bits overlap, this number can't be part of our nice subarray
                else:
                    break

            # Update max length if we found a longer nice subarray
            max_length = max(max_length, current_length)

        return max_length