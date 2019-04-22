# Node Class
class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

# Linked List class
class SinglyList:

    # Constructor for the List Class
    def __init__(self):
        self.head = None
        self.size = 0

    # Check is the list is empty
    # Run-Time: O(1)
    # Space-Complexity: O(1)
    def is_empty(self):
        if self.size == 0:
            return True
        
        return False

    # Append node to the front of the list
    # Run-Time: O(1)
    # Space-Complexity: O(1)
    def push_front(self, data):
        if self.head == None:
            self.head = Node(data)
        
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp
        
        self.size = self.size + 1
    
    # Append node to back of the list
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def push_back(self, data):
        if self.head == None:
            self.head = Node(data)

        else:
            temp = self.head
            # Get the last node
            while temp.next != None:
                temp = temp.next

            new_node = Node(data)
            temp.next = new_node

        self.size = self.size + 1

    # Remove the back node of the list
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def pop_back(self):
        if self.is_empty():
            print("The list is empty")
            return None
            
        temp = self.head

        # Case for one node in the list
        if self.size == 1:
            self.head = None
            return

        # Get the second to last node
        while temp.next.next != None:
            temp = temp.next
        
        node = temp.next
        temp.next = None
        self.size = self.size - 1
        return node.data

    # Remove the front node of the list
    # Run-Time: O(1)
    # Space-Complexity: O(1)
    def pop_front(self):
        if self.is_empty():
            print("The list is empty")
            return

        node = self.head
        self.head = self.head.next
        self.size = self.size - 1
        return node.data

    # Remove a specific node
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def remove_node(self, data):
        if self.is_empty():
            print("The list is empty")
            return None

        temp = self.head
        # Get the node before the node we want to delete
        while temp.next != None and temp.next.data != data:
            temp = temp.next
        
        # If not found in the list
        if temp.next == None:
            print(f"Cannot find {data} in the list")
            return None

        # Set the node's next to skip the node we want to delete
        node = temp.next
        temp.next = temp.next.next
        self.size = self.size - 1
        return node.data

    # Remove at a specific positon (starting at one)
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def remove_at(self, pos):
        if self.is_empty():
            print("The list is empty")
            return None

        temp = self.head

        # Get the previous node where we want to delete
        while pos - 2 != 0:
            temp = temp.next
            pos = pos - 1
        
        node = temp.next
        temp.next = temp.next.next
        self.size = self.size - 1

        return node.data

    # Print the entire list
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def print(self):
        temp = self.head
        if temp == None:
            print("The list is empty")
            return

        while temp != None:
            print(f"{temp.data} -> ", end="")
            temp = temp.next

        print("NULL")

    # Destroy the entire list
    # Run-Time: O(N)
    # Space-Complexity: O(1)
    def destroy(self):
        while self.head != None:
            print(f"Removing {self.head.data}")
            self.pop_front()

# Test Code
myList = SinglyList()
for i in range(10):
    myList.push_back(i)

myList.print()

print("\nTesting pop_back")
myList.pop_back()
myList.print()

print("\nTesting pop_front")
myList.pop_front()
myList.print()

print("\nTesting remove_node")
myList.remove_node(4)
myList.print()

print("\nTesting remove_at")
myList.remove_at(6)
myList.print()

print("\nTesting destroy()")
myList.destroy()
myList.print()