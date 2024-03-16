#  A bigram is a group of two words that appear together in a given sentence or text.
# This function works by splitting the input string into a list of words, then iterating over the list and creating a bigram by combining each word with the next word. The bigrams are then added to a list, which is returned by the function.


def get_bigrams(input_string):
    # Create an empty list to hold the bigrams
    bigrams = []
    
    # Convert the string to a list of words
    words = input_string.split()
    
    # Iterate over the list of words
    for i in range(len(words) - 1):
        # Create a bigram by combining the current word with the next word
        bigram = [words[i], words[i + 1]]
        
        # Add the bigram to the list of bigrams
        bigrams.append(bigram)
    
    # Return the list of bigrams
    return bigrams



print(get_bigrams("The quick brown fox jumps over the lazy dog"))   
