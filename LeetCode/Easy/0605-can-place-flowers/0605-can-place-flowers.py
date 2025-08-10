class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # length_of_flowerbed
        lof = len(flowerbed)

        before = 0
        for slot in range(0, lof):
            # 첫번째 칸일 때
            if slot == 0:
                if flowerbed[slot] == 0 and flowerbed[min(slot + 1, lof - 1)] == 0:
                    flowerbed[slot] = 1
                    n -= 1
            # 마지막 칸일 때
            elif slot == lof - 1:
                if flowerbed[slot] == 0 and flowerbed[max(slot - 1, 0)] == 0:
                    flowerbed[slot] = 1
                    n -= 1

            # 중간 칸일 때
            else:
                if flowerbed[slot] == 0 and flowerbed[slot - 1] == 0 and flowerbed[slot + 1] == 0:
                    flowerbed[slot] = 1
                    n -= 1

            if n <= 0:
                return True

        return False


        