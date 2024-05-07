class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def create_linked_list(values):
    if not values:
        return None
    
    head = ListNode(values[0])
    current = head
    
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    
    return head

def print_linked_list(head):
    list = []
    current = head
    while current:
        list.append(current.val)
        # print(current.val, end=" -> ")
        current = current.next
    return list

    print("None")




class Solution:
    def mergeTwoLists(self, list1, list2):
        arr1 = print_linked_list(list1)
        arr2 = print_linked_list(list2)
        arr = sorted(arr1 + arr2)
        sorted_link_list = create_linked_list(arr)
        return sorted_link_list




obj = Solution()
lis = obj.mergeTwoLists(list1 , list2)
print_linked_list(lis)

