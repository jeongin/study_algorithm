class Solution:
    def myAtoi(self, s: str) -> int:
        
        # step 1
        s = s.strip()
        
        # step 2
        answer_str:str = None
        
        for c in s:
            if not answer_str:
                if c.isdigit() or c in {'-', '+'}:
                    answer_str = c
                else:
                    break
            else:
                if c.isdigit():
                    answer_str += c
                else:
                    break
        
        # step 3
        if not answer_str or answer_str in {'-', '+'}:
            return 0
        
        answer = int(answer_str)
        
        if answer < -(2**31):
            return -(2**31)
        if answer > (2**31)-1:
            return (2**31) - 1
        
        return answer