class Solution:
    def compress(self, chars: List[str]) -> int:
        idx = 0
        result = 0
        while idx < len(chars):
            group_length = 1
            # check same character
            while (idx + group_length < len(chars) and chars[idx + group_length] == chars[idx]):
                group_length += 1
            chars[result] = chars[idx]
            result += 1
            if group_length > 1:
                str_repr = str(group_length)
                chars[result:result+len(str_repr)] = list(str_repr)
                result += len(str_repr)
            idx += group_length
        return result