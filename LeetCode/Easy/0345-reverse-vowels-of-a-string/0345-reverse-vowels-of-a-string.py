class Solution:
    def reverseVowels(self, s: str) -> str:
        index_list = []
        char_list = []
        origin_list = []
        for idx, char in enumerate(s):
            origin_list.append(char)

            if char.lower() in ['a', 'e', 'i', 'o', 'u']:
                index_list.append(idx)
                char_list.append(char)
        
        for n in range(len(index_list)):
            origin_list[index_list[n]] = char_list[len(index_list) - n - 1]

        result = ''.join(origin_list)

        return result

        