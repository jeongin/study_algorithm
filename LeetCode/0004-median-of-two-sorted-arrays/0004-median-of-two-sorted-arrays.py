class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            temp = nums1
            nums1 = nums2
            nums2 = temp
        
        len1 = len(nums1)
        len2 = len(nums2)
        total_len = len1 + len2
        
        left1 = 0
        left2 = 0
        
        answer = []
        
        while left1 < len1 or left2 < len2:
            if left1 == len1:
                answer.append(nums2[left2])
                left2 += 1
            elif left2 == len2:
                answer.append(nums1[left1])
                left1 += 1
            else:
                num1 = nums1[left1]
                num2 = nums2[left2]
                
                if num1 <= num2:
                    answer.append(num1)
                    left1 += 1
                else:
                    answer.append(num2)
                    left2 += 1
            
            if len(answer) >= (total_len // 2) + 1:
                break
        
        if total_len % 2 == 0:
            return (answer[-1] + answer[-2]) / 2
        else:
            return answer[-1]
    
        