list = []
n = int(input("Enter number of students who attended the training program."))

def read():
    print("Enter roll numbers of the students who attended the training program.")
    for i in range(n):
        rollno = int(input())
        list.append(rollno)
    print("List of students :", list)
    
read()    

def linear():
    x = int(input("Enter the roll number to be searched."))
    for i in range(n):
        if x == list[i]:
            return i+1
            break
    return -1

def linear2():
    a = linear()
    if a == -1:
        print("Student was absent for the training program.")
    else:
        print("Student attended the training program and is at position", a)
        
def sentinel():
    x = int(input("Enter the roll number to be searched."))
    last = list[n-1]
    list[n-1] = x
    
    for i in range(n):
        if x == list[i]:
            break
    if i<n-1 or last==x:
        print("Student attended the training program and is at position", i+1)
    else:
        print("Student was absent for the training program.")
            
    list[n-1] = last
    
    
linear2()
sentinel()
