create_staircase <- function(integers) {
  integers <- sort(integers, decreasing = TRUE)  # Sort the integers in descending order
  staircase <- list()  # Initialize the staircase as an empty list
  
  while (length(integers) != 0) {  # Continue until the list of integers is empty
    sublist_length <- length(staircase) + 1  # Determine the length of the next sublist
    sublist <- integers[1:sublist_length]  # Extract integers for the next sublist
    
    # Check if the sublist length matches the expected length
    if (length(sublist) != sublist_length) {
      return(FALSE)  # Unable to form a staircase
    }
    
    staircase <- c(staircase, list(sublist))  # Add the sublist to the staircase
    integers <- integers[-c(1:sublist_length)]  # This will remove the first 'sublist_length' elements from the 'integers' list
  }
  
  return(staircase)
}



# Example input
integers <- c(6, 5, 4, 3, 2, 1)

# Call the create_staircase function
staircase <- create_staircase(integers)

# Print the result
print(staircase)