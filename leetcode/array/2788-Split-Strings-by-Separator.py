class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for i in words:
            for j in i.split(separator):
                if j:
                    ans.append(j)
        return ans