list = []
n = int(input("Enter number of students who attended the training program."))

def read():
    print("Enter roll numbers of the students who attended the training program.")
    for i in range(n):
        rollno = int(input())
        list.append(rollno)
    print("List of students :", list)
    
read()

def sort():
    for i in range(n):
        for j in range(0, n-1):
            if list[j]>list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
    print("Sorted list :", list)
    
sort()

low = 0
high = n-1
key = int(input("Enter the roll number to be searched."))

def binary(list, low, high, key):
    if low <= high:
        mid = (low+high)//2
        if key == list[mid]:
            print("Student was present for the training program.")
        elif key < list[mid]:
            binary(list, low, mid-1, key)
        elif key > list[mid]:
            binary(list, mid+1, high, key)
    else:
        print("Student was absent for the training program,")
            
binary(list, 0, n-1, key)

def fibonacci_search(list, key):
    m = 0
    while fib(m) < n:
        m += 1
    
    offset = -1
    while fib(m) > 1:
        i = min(offset + fib(m - 2), n - 1)
        
        if list[i] < key:
            m -= 1
            offset = i
        
        elif list[i] > key:
            m -= 2
        
        else:
            return i
    
    if offset != -1 and list[offset + 1] == key:
        return offset + 1
    
    return -1

def fib(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a

fibonacci_search(list, key)
            
    
        
