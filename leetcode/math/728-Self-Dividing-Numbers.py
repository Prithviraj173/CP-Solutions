class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        return [number for number in range(left, right+1) if '0' not in str(number) and all((number % int(char) == 0 for char in str(number)))]
