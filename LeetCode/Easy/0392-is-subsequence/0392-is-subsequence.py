class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s_list = list(s)
        t_list = list(t)

        s_idx = 0
        t_idx = 0

        if len(s_list) == 0:
            return True

        while s_idx < len(s_list) and t_idx < len(t_list):
            if s_list[s_idx] == t_list[t_idx]:
                s_idx += 1
                if s_idx == len(s_list):
                    return True
            
            t_idx += 1
        
        return False