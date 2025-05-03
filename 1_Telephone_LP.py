class TelephoneBook:
    def __init__(self, name, tel_no):  # Corrected constructor
        self.name = name
        self.tel_no = tel_no

def Insertion_LinearProbing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashValue = t % 10  # hash function
        j = 0  # Initialize the probing counter
        while hashtable[hashValue] is not None:
            j += 1  # Increment probe counter
            hashValue = (hashValue + j * j) % 10  # Quadratic probing
        hashtable[hashValue] = TelephoneBook(n, t)  # Insert record
    return hashtable

def Insertion_DoubleHashing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))
    for i in range(num_records):
        n = input("Enter name: ")
        t = int(input("Enter telephone no.: "))
        hashValue = t % 10  # First hash function
        step_size = 7 - (t % 7)  # Second hash function
        j = 0  # Initialize the probing counter
        while hashtable[hashValue] is not None:
            j += 1  # Increment probe counter
            hashValue = (hashValue + j * step_size) % 10  # Double hashing
        hashtable[hashValue] = TelephoneBook(n, t)  # Insert record
    return hashtable

def Display_LP(hash1):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash1):  # Use enumerate for proper index display
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

def Display_DH(hash2):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for i, obj in enumerate(hash2):  # Use enumerate for proper index display
        if obj is None:
            print(f"{i}\t-\t-")
        else:
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
    print("-------------------------------")

def Search(hash1, hash2):
    n = input("Enter name to search: ")
    found = False
    # Search in hash1 (Quadratic Probing)
    for i, obj in enumerate(hash1):
        if obj and obj.name == n:
            print("\nFound in Hashtable-1 !")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(f"{i}\t{obj.name}\t{obj.tel_no}")
            print("-------------------------------")
            found = True
            break  # Stop after finding the record in hash1
    # Search in hash2 (Double Hashing)
    if not found:
        for i, obj in enumerate(hash2):
            if obj and obj.name == n:
                print("\nFound in Hashtable-2 !")
                print("-------------------------------")
                print("Index\tName\tTelephone No.")
                print("-------------------------------")
                print(f"{i}\t{obj.name}\t{obj.tel_no}")
                print("-------------------------------")
                found = True
                break  # Stop after finding the record in hash2
    if not found:
        print("\nNot found !!!\n")

def Delete(hash1, hash2):
    name_to_delete = input("Enter name to delete: ")
    deleted = False
    # Try deleting from hash1 (Quadratic Probing)
    for i in range(len(hash1)):
        obj = hash1[i]
        if obj and obj.name == name_to_delete:
            hash1[i] = None  # Set slot to None to delete both name and telephone number
            print(f"Record with name {name_to_delete} and telephone number {obj.tel_no} deleted from Hashtable-1!")
            deleted = True
            break
    # Try deleting from hash2 (Double Hashing) if not found in hash1
    if not deleted:
        for i in range(len(hash2)):
            obj = hash2[i]
            if obj and obj.name == name_to_delete:
                hash2[i] = None  # Set slot to None to delete both name and telephone number
                print(f"Record with name {name_to_delete} and telephone number {obj.tel_no} deleted from Hashtable-2!")
                deleted = True
                break
    if not deleted:
        print("Record not found in either hash table.")

def main():
    hash1 = [None for _ in range(10)]
    hash2 = [None for _ in range(10)]
    while True:
        print("-------------------------")
        print("\t1.Insert Value")
        print("\t2.Display")
        print("\t3.Search")
        print("\t4.Delete")
        print("\t5.Exit")
        print("-------------------------")
        ch = int(input("Enter choice: "))
        if ch == 1:
            print("\nSelect collision method-")
            print("\t1.Linear Probing")
            print("\t2.Double Hashing")
            c = int(input("Enter choice: "))
            if c == 1:
                hash1 = Insertion_LinearProbing()
            elif c == 2:
                hash2 = Insertion_DoubleHashing()
        elif ch == 2:
            print("\t1.Display LP")
            print("\t2.Display DH")
            c1 = int(input("Enter choice: "))
            if c1 == 1:
                Display_LP(hash1)  # Quadratic probing method
            else:
                Display_DH(hash2)  # Double hashing method
        elif ch == 3:
            Search(hash1, hash2)
        elif ch == 4:
            Delete(hash1, hash2)
        elif ch == 5:
            print("End of Program")
            break  # Exit the loop gracefully
        else:
            print("! Enter valid choice.")

main()
