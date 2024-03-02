class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        new_str = ["" for _ in range(numRows)]
        answer = ''
        
        row = 0
        move_down = True
        
        for c in s:
            if row == 0:
                move_down = True
            elif row == numRows - 1:
                move_down = False
            
            new_str[row] += c
            
            if move_down:
                row += 1
            else:
                row -= 1
        
        for i in range(numRows):
            answer += new_str[i]
            
        return answer