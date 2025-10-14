class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        cursor = 0
        idx = 0
        zero_count = 0
        while cursor < len(nums):
            if nums[cursor] == 0:
                zero_count += 1
            else:
                nums[idx] = nums[cursor]
                idx += 1
            
            cursor += 1
        
        while idx < len(nums):
            nums[idx] = 0
            idx += 1
        