class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        first = nums[0]
        second = second = 2**31
        for num in nums:
            if num > second:
                return True

            if num < second and num > first:
                second = num
            
            if num < first:
                first = num

        return False
        