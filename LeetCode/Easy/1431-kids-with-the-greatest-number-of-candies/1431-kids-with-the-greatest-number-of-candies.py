class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies = 0
        for candy in candies:
            max_candies = max(candy, max_candies)

        results = []
        for candy in candies:
            if candy + extraCandies >= max_candies:
                results.append(True)
            else:
                results.append(False)

        return results
        