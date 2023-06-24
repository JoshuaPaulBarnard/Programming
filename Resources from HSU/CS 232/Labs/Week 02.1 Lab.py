# CS 232 Spring 2016
# Lab 02 Demonstraion File

# First, a basic conditional statement
# that shows how to determine the data
# type of a variable

# is_string: object -> bool
# purpose: expects an object
#    returns True if the object is a
#    string, and False otherwise

def is_string(input_value):
    if type(input_value) == str:
        return True
    else:
        return False

# Next, a function that demonstrates
# type conversion, string concatenation,
# and if - else if - else conditionals
# Also, a first example of output formatting

# yell_it: object -> str
# purpose: expects an object
#   if object is a string, return string + "!!"
#   if object is a float, return object converted to
#     a string with 3 decimal places, append "!!" to it
#   if any other type, convert to string and append "!!" to it

def yell_it(input_val):
    if type(input_val) == str:
        return input_val + "!!"
    elif type(input_val) == float:
        return "%.3f" % input_val + "!!"
    else:
        return str(input_val) + "!!"

# Finally, a first look at a Python list
# A list is a grouping of multiple values
# that can be accessed using a numerical
# index, similar to an array

# The split() method for string objects will
# create a list of strings from a single string
# If no argument is given, each element in the
# output list is a separate word (that is, each space
# in the input string determines where to split the
# string into its component words).  A different
# "delimiter" character (such as comma, colon, etc)
# can be used as an argument to split the string

# The len() built-in function is used to determine the
# length (number of elements) in a Python list

# split_it: str -> void
# purpose: expects a multi-word string
#   returns nothing
# side effect: prints to the screen each word, one at a time

def split_it(input_string):
    input_words = input_string.split()
    # print(input_words) # Uncomment to see the whole list
    for i in range (0, len(input_words)):
        print(input_words[i])




