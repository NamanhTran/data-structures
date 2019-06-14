# Java code from Algorithm Part 1, Princeton University translated to Python

from os import chdir
from os import getcwd
from os import listdir

# Insertion sort implementation arr passed has to have a compare_to function attacted to each object
class Insertion:
    def sort(self, arr):
        # Goes through each element in the provided array
        for i in range(len(arr)):

            # Shift the element into proper position 
            for j in range(i, 0, -1):

                # If the element before the current element is greater, swap them
                if self.less(arr[j], arr[j - 1]):
                    self.exch(arr, j, j - 1)
                
                # Since insertion sort is always sorted at the i-th postition we break
                else:
                    break

    # Checks if a < b
    def less(self, a, b):
        return a.compare_to(a.val, b.val) < 0

    # Swap a and b in arr
    def exch(self, arr, a, b):
        swap = arr[a]
        arr[a] = arr[b]
        arr[b] = swap

# Class required for each data type to use insertion sort (probably could do better)
class Custom:
    # Constructor to put data into val and the compare_to function
    def __init__(self, data, funct):
        self.val = data
        self.compare_to = funct

    # Allows for print() to print object's string when passing object into print
    def __repr__(self):
        return str(self.val)

# Compares the two file names
def file_compare(a, b):
    if (a.lower() < b.lower()):
        return -1

    if (a.lower() > b.lower()):
        return 1

    return 0

def main():
    # Example use of the insertion sort using files names
    chdir('../')
    chdir('../')

    files = listdir(getcwd())

    for i in range(len(files)):
        files[i] = Custom(files[i], file_compare)

    algorithm = Insertion()
    algorithm.sort(files)

    print(files)

if __name__ == '__main__':
    main()