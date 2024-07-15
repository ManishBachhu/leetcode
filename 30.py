def getSubstringIndices(s: str, words: dict, word_len: int, max_len: int):
    '''
    Return starting indices of all valid substrings
    '''
    curr_words = {}
    out = []
    l = 0
    r = 0
    while r < len(s):
        word = s[r: r + word_len]
        if words.get(word):
            curr_words[word] = curr_words.get(word, 0) + 1
            print(curr_words)
            # If word is more than freq, need to prune until first instance
            # of that word is removed
            while words[word] < curr_words[word]:
                curr_words[s[l:l + word_len]] -= 1
                l += word_len
            # Valid substring has formed
            if (r + word_len) - l == max_len:
                out.append(l)
                # remove first word in window has limit is reached 
                curr_words[s[l:l + word_len]] -= 1
                l += word_len
            r += word_len
        # if word doesn't exist, valid substring cannot be formed
        else:
            curr_words = {}
            l = r = r + word_len
    return out

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_len = len(words[0])
        max_len = word_len * len(words)
        max_count = {}
        output = []

        for word in words:
            max_count[word] = max_count.get(word, 0) + 1

        for start in range(0, word_len):
            for idx in getSubstringIndices(s[start:], max_count, word_len, max_len):
                output.append(start + idx)

        return output
