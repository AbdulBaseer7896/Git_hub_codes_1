
class Solution:
    def romanToInt(self, s: str) -> int:
        if "I" or "V" or "X" or "L" or "C" or "D" or "M":
            symbols = list(s)
            # final_list = obj.symbol_values(my_list)
            symbol_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

            for i in range(len(symbols)):
                if symbols[i] in symbol_map:
                    symbols[i] = symbol_map[symbols[i]]
            print("This is the final list" , symbols)
            list_sum = sum(symbols)
            print(list_sum)

        else:
            print("Its does not word")



    # def symbol_values(self, symbols):
        
    #     symbol_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    #     for i in range(len(symbols)):
    #         if symbols[i] in symbol_map:
    #             symbols[i] = symbol_map[symbols[i]]

    #     print("Updated list:", symbols)
    #     return symbols




obj  = Solution()
obj.romanToInt("VIIC")

