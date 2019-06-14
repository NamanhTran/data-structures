# Java code from Algorithm Part 1, Princeton University translated to Python

# Selection sort implementation arr passed has to have a compare_to function attacted to each object
class Selection:
    def sort(self, arr):
        for i in range(len(arr)):
            min = i
            for j in range(i + 1, len(arr)):
                if self.less(arr[j], arr[min]):
                    min = j

            self.exch(arr, i, min)

    def exch(self, arr, a, b):
        swap = arr[a]
        arr[a] = arr[b]
        arr[b] = swap

    def less(self, a, b):
        return a.compare_to(a.val, b.val) < 0

# Class required for each data type to use insertion sort (probably could do better)
class Custom:
    # Constructor to put data into val and the compare_to function
    def __init__(self, data, funct):
        self.val = data
        self.compare_to = funct

    # Allows for print() to print object's string when passing object into print
    def __repr__(self):
        return str(self.val)

# Example date class
class Date:
    def __init__(self, month, day, year):
        self.month = month
        self.day = day
        self.year = year
    
    def __repr__(self):
        return str('{}/{}/{}'.format(self.month, self.day, self.year))

# Compare_to function for date class
def date_compare(a, b):
    if (a.year < b.year):
        return -1
    if (a.year > b.year):
        return 1
    if (a.month < b.month):
        return -1
    if (a.month > b.month):
        return 1
    if (a.day < b.day):
        return -1
    if (a.day > b.day):
        return 1
    return 0

# Example use of the sort
def main():
    date1 = Date(5, 17, 1999)
    date2 = Date(11, 16, 2002)
    date3 = Date(5, 7, 1996)

    arr = [date1, date2, date3]

    for i in range(len(arr)):
        arr[i] = Custom(arr[i], date_compare)

    algorithm = Selection()
    algorithm.sort(arr)

    print(arr)

if __name__ == "__main__":
    main()