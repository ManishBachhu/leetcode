# Approach 2: Get roman by appending next value:
class Solution:
    def intToRoman(self, num: int) -> str:
        to_r = {
            1000: 'M',
            900: 'CM',
            500: 'D',
            400: 'CD',
            100: 'C',
            90: 'XC',
            50: 'L',
            40: 'XL',
            10: 'X',
            9: 'IX',
            5: 'V',
            4: 'IV',
            1: 'I'
        }

        roman = ''

        for i in to_r:
            while i <= num:
                num -= i
                roman += to_r[i]

        return roman

"""
# Approach 1: Get roman by building each digit
class Solution:
    def intToRoman(self, num: int) -> str:
        romanDict = {
            1: {
                1: "I",
                5: "V",
            },
            10: {
                1: "X",
                5: "L",
            },
            100: {
                1: "C",
                5: "D",
            },
            1000: {
                1: "M",
            },
        }

        ans = ""
        power = 1
        while num:
            digit = num % 10
            match digit:
                case 9:
                    ans = romanDict[power][1] + romanDict[power * 10][1] + ans
                case 4:
                    ans = romanDict[power][1] + romanDict[power][5] + ans
                case _:
                    if digit >= 5:
                        tmp = romanDict[power][5]
                        digit -= 5
                    else:
                        tmp = ""

                    while digit:
                        tmp += romanDict[power][1]
                        digit -= 1
                    ans = tmp + ans

            power *= 10
            num = int(num / 10)
            print(num, ans)

        return ans

"""
