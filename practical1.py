# Consider telephone book database of N clients. Make use of a hash table implementation to
# quickly look up client‘s telephone number. Make use of two collision handling techniques
# and compare them using number of comparisons required to find a set of telephone
# numbers


class hashTable:
    def __init__(self):
        self.MAX = 100
        self.table = [None] * self.MAX

    def getHash(self, key):
        h = 0
        for char in key:
            h += ord(char)
        return h % self.MAX

    def display(self):
        for i in range(self.MAX):
            if self.table[i] is not None:
                print(f"index :{i} \ndata :{self.table[i]}\n")

    def _linearProbe(self, index):
        return (index + 1) % self.MAX

    def _quadraticProbe(self, index, i):
        return (index + i**2) % self.MAX

    def insertByLinearProbing(self, key, value):
        index = self.getHash(key)

        while self.table[index] is not None:
            print(
                f"Collision detected while inserting {key} into table at index {index}")
            index = self._linearProbe(index)

        self.table.insert(index, {key: value})

        print(f"Inserted at index: {index} \n {self.table[index]}")
        self.display()

    def getByLinearProbing(self, key):
        index = self.getHash(key)
        while self.table[index] is not None:
            for k, v in self.table[index].items():
                if k == key:
                    return self.table[index]

            index = self._linearProbe(index)
        print("Elements not found")
        return None

    def insertByQuadraticProbing(self, key, value):
        index = self.getHash(key)
        i = 0
        while self.table[index] is None:
            i += 1
            print(
                f"Collision detected while inserting {key} into table at index {i}")
            index = self._quadraticProbe(index, i)

        self.table.insert(index, {key: value})

    def getByQuadraticProbing(self, key):

        index = self.getHash(key)
        i = 0

        while self.table[index] is not None:
            for k, v in self.table[index].items():
                if k == key:
                    return self.table[index]
            i += 1
            index = self._linearProbe(index)
        print("Elements not found")
        return None

    def remove(self, key):
        index = self.getHash(key)
        self.table[index] = None

# ========================================== MAIN ===================================================


print("Please enter which collision technique to use \n1.Linear probing \n2.Quadratic probing")
probingChoice = int(input())
hashmap = hashTable()

while True:
    print("""Select the operation 
    1. Insert
    2. Display
    3. get item
    4. exit Program
    """)

    operationChoice = int(input())
    if operationChoice == 1:
        key = input("Enter the name of contact: ")
        value = input("Enter the phone number: ")
        if probingChoice == 1:
            hashmap.insertByLinearProbing(key, value)
        else:
            hashmap.insertByQuadraticProbing(key, value)
    elif operationChoice == 2:
        hashmap.display()
    elif operationChoice == 3:
        key = input("Enter the key: ")
        if probingChoice == 1:
            print(hashmap.getByLinearProbing(key))
        else:
            print(hashmap.getByQuadraticProbing(key))
    elif operationChoice == 4:
        break
    else:
        print("Invalid choice")
