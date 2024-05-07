class Solution:
    def __init__(self):
        self.items = []

    def isValid(self, s: str) -> bool:
        for i in s:
            my_Solution.push(i)

        popped_items = []

        for item in my_Solution.items[:]:
            print(item)
            if item == ")" or item == "}" or item == "]":
                item = my_Solution.pop()
                popped_items.append(item)

        for i in range(len(my_Solution.items)):
            if my_Solution.items[i] == '(':
                my_Solution.replace('(', 1)
            if my_Solution.items[i] == '{':
                my_Solution.replace('{', 2)
            if my_Solution.items[i] == '[':
                my_Solution.replace('[', 3)
        # popped_items = []

        popped_items = list(reversed(popped_items))


        for i in range(len(popped_items)):
            if popped_items[i] == ')':
                popped_items[i] = 1
            if popped_items[i] == '}':
                popped_items[i] = 2
            if popped_items[i] == ']':
                popped_items[i] = 3

        valid = self.check(popped_items)
        return valid





    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            print("Solution is empty")
    

    def replace(self, old_item, new_item):
        for i in range(len(self.items)):
            if self.items[i] == old_item:
                self.items[i] = new_item


    def check(self , popped_items):
        check = True
        for i in popped_items:
            Solution = my_Solution.pop()
            print(Solution , i)
            if i == Solution:
                check = True
            else:
                check = False
                return False
            
            if check == True:
                h = self.is_empty()
                print("this is h = " , h)
                print("this is stack = " , my_Solution.items)
                if h == True:
                    return True
                else:
                    return False

# Example usage:
my_Solution = Solution()

print("is empty = " , my_Solution.isValid("{([])}"))

