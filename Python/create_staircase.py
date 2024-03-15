def create_staircase(integers):
    integers.sort(reverse=True)  # Sort the integers in descending order
    staircase = []  # Initialize the staircase as an empty list
    
    while len(integers) != 0 :  # Continue until the list of integers is empty
        sublist_length = len(staircase) + 1  # Determine the length of the next sublist
        sublist = integers[:sublist_length]  # Extract integers for the next sublist
        
        # Check if the sublist length matches the expected length
        if len(sublist) != sublist_length:
            return False  # Unable to form a staircase
        
        staircase.append(sublist)  # Add the sublist to the staircase
        integers = integers[sublist_length:]  # Remove integers used in the sublist from the original list
    
    return staircase


result = create_staircase( [1,2,3,4,5,6] )
print(result)

result = create_staircase( [1,2,3,4,5,6,7] )
print(result)