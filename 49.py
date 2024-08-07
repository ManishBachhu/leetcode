class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Init dict with list if key is not present
        ans = defaultdict(list)

        for word in strs:
            # Create a freq array for all alphabets
            freq_list = [0 for _ in ascii_lowercase]
            for ch in word:
                freq_list[ord(ch) - ord('a')] += 1
            # Use tuple(list) as key and value as list of words
            ans[tuple(freq_list)].append(word)

        return ans.values()
