class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class List:
    def __init__(self):
        self.head = None
        
    def push_front(self, data):
        if self.head == None:
            self.head = Node(data)
        
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp
    
    def push_back(self, data):
        if self.head == None:
            return

        else:
            temp = self.head
            # get the last node
            while temp.next != None:
                temp = temp.next

            new_node = Node(data)
            temp.next = new_node

    def print(self):
        temp = self.head
        while temp != None:
            print(f"{temp.data} -> ", end="")
            temp = temp.next

        print("NULL")

myList = List()
for i in range(10):
    myList.push_front(i)
myList.print()