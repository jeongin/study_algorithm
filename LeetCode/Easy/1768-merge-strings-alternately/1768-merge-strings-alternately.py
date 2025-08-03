class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """

        w1_cursor = 0
        w2_cursor = 0

        w1_length = len(word1)
        w2_length = len(word2)

        merged_word = []

        while w1_cursor < w1_length or w2_cursor < w2_length:
            if w1_cursor < w1_length:
                merged_word.append(word1[w1_cursor])
                w1_cursor += 1
            
            if w2_cursor < w2_length:
                merged_word.append(word2[w2_cursor])
                w2_cursor += 1
        
        return ''.join(merged_word)