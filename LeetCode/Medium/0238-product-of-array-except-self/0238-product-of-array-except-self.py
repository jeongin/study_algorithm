class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        count_zero = 0
        max_multiply = 1
        for num in nums:
            if num != 0:
                max_multiply *= num
            else:
                count_zero += 1

        results = []
        for num in nums:
            if count_zero >= 2:
                results.append(0)
            elif count_zero == 1:
                if num != 0:
                    results.append(0)
                else:
                    results.append(max_multiply)
            else:
                results.append(int(max_multiply / num))

        return results

        
        