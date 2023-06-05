# To create ADT that implements the "set" concept.
# a. Add(new Element) - Place a value into the set,
# b. Remove(element) Remove the value
# c. Contains(element) Return true if element is in collection,
# d. Size() Return number of values in collection Iterator() Return an iterator used to loop over collection,
# e. Intersection of two sets,
# f. Union of two sets,
# g. Difference between two sets,
# h. Subset

class Set:
    def __init__(self):
        self.set = []

    def size(self):
        print(f"Size of set is {len(self.set)}")
        return self.size

    def add(self, element):
        if element not in self.set:
            self.set.append(element)

    def remove(self, element):
        if element in self.set:
            self.set.remove(element)

    def contains(self, element):
        if element in self.set:
            print("element present in set")
            return True
        else:
            print("element not found in set")
            return False

    def iterator(self):
        return iter(self.set)

    def intersection(self, other):
        intersection = Set()
        for element in self.set:
            if element in other.set:
                intersection.add(element)
        return intersection

    def union(self, other):
        union = Set()
        for element in self.set:
            union.add(element)
        for element in other.set:
            union.add(element)
        print(union.set)
        return union

    def difference(self, other):
        difference = Set()
        for element in self.set:
            if element not in other.set:
                difference.add(element)

        print(difference.set)
        return difference

    def subset(self, other):
        for element in other.set:
            if element not in self.set:
                return False
        return True

    def display(self):
        print(set1.set)


def createSet():
    set = Set()
    size = int(input("Enter the number of elements you want to enter : "))
    for a in range(size):
        set.add(input(f"Enter the element {a+1} : "))
    return set

# ========================================== MAIN ===================================================


set1 = Set()
while True:
    print("""Select the operation
    1.insert element
    2.delete element
    3.display all elements
    4.display size
    5.intersections of sets
    6.union of sets
    7.difference of sets
    8.Exit program """)

    operationChoice = int(input())
    if operationChoice == 1:
        set1.add(input("Enter the element : "))
    elif operationChoice == 2:
        set1.remove(input("Enter the element : "))
    elif operationChoice == 3:
        set1.display()
    elif operationChoice == 4:
        set1.size()
    elif operationChoice == 5:
        set2 = createSet()
        set1.intersection(set2)
    elif operationChoice == 6:
        set2 = createSet()
        set1.union(set2)

    elif operationChoice == 7:
        set2 = createSet()
        set1.difference(set2)

    elif operationChoice == 8:
        break
    else:
        print("Invalid choice")
