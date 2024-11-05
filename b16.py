def quicksort(arr, low, high):
    if low < high:
        # Partition the array and get the index of the pivot
        pivot_index = partition(arr, low, high)
        
        # Recursively sort the subarrays on either side of the pivot
        quicksort(arr, low, pivot_index - 1)
        quicksort(arr, pivot_index + 1, high)

def partition(arr, low, high):
    # Choose the pivot (for simplicity, we'll use the first element)
    pivot = arr[low]
    
    # Initialize indices for elements less than the pivot (p) and elements greater than the pivot (q)
    p = low + 1
    q = high
    
    # Iterate through the array from low+1 to high
    while True:
        # Find the first element from the left (p) that is greater than the pivot
        while p <= q and arr[p] <= pivot:
            p += 1

        # Find the first element from the right (q) that is less than the pivot
        while p <= q and arr[q] >= pivot:
            q -= 1

        # If there are elements to swap, do the swap; otherwise, break the loop
        if p <= q:
            arr[p], arr[q] = arr[q], arr[p]
        else:
            break
    
    # Swap the pivot (which is at index low) with the element at index q
    arr[low], arr[q] = arr[q], arr[low]
    
    # Return the index of the pivot after partitioning
    return q

# Example usage:
my_list = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
quicksort(my_list, 0, len(my_list) - 1)
print("Sorted Array:", my_list)
