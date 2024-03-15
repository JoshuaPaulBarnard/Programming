def decode(message_file):
    # Read in the input text file
    with open(message_file, 'r') as file:
        lines = file.readlines()

    # Create a dictionary with the number-word pairs
    number_to_word_dictionary = {}
    for line in lines:
        number, word = line.split()
        number_to_word_dictionary[int(number)] = word

    # Sort the dictionary by keys
    number_to_word_dictionary = dict( sorted( number_to_word_dictionary.items() ) )

    # Create a staircase
    staircase = []
    for staircase_iterator in range(1, len(lines) + 1):
        if staircase_iterator in number_to_word_dictionary:
            staircase.append(number_to_word_dictionary[ staircase_iterator ])

    # Decode the message
    message = []
    for message_iterator in range(1, len( staircase ) + 1):
        if message_iterator * ( message_iterator + 1 )//2 <= len(staircase):
            message.append(staircase[ message_iterator * ( message_iterator + 1 )//2 - 1])
    
    # Convert decoded message into a string
    decoded_message = ' '.join(message)
    
    return decoded_message




# Example usage:
message_file = 'B:\\Documents\\GitHub\\coding_qual_input.txt'  # Path to the encoded message file
message_file = 'B:\\Documents\\GitHub\\message_file2.txt'  # Path to the encoded message file
decoded_message = decode(message_file)
print(decoded_message)