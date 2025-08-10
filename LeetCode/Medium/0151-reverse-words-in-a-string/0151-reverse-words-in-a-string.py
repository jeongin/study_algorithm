class Solution:
    def reverseWords(self, s: str) -> str:
        words = re.split(r"\s+", s.strip())
        reversed_words = words[::-1]

        return ' '.join(reversed_words)
        