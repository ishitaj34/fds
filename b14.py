list = []
n = int(input("Enter number of students in the class."))

#To store first year percentages in a list
def read():
    print("Enter the marks scored by each student.")
    for i in range(n):
        marks = float(input())
        list.append(marks)
    print("List :", list)
    
read()

l1 = []; l2 =[]
l1 = list.copy()
l2 = list.copy()

def selection():
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if l1[j] < l1[min_index]:
                min_index = j
        l1[i], l1[min_index] = l1[min_index], l1[i]
    print("Sorted list :", l1)
    

def bubblesort():
    for i in range(0, n):
        for j in range(0, n-1):
            if l2[j] > l2[j+1]:
                l2[j], l2[j+1] = l2[j+1], l2[j]
    print("Sorted list :", l2)
    

def topfive(l):
    l3 = []
    for i in range(n-1, n-6, -1):
        l3.append(l[i])
    print("Top five :", l3)
    
#selection()
topfive(l1)
        
        
    
