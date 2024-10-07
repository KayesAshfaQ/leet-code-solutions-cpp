class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        for digit in digits:
            num = num * 10 + digit

        num += 1
        digits.clear()
        while num > 0:
            digits.insert(0, num % 10)
            num //= 10

        return digits
