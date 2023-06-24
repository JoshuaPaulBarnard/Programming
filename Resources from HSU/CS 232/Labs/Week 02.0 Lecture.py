# CS 232 SPring 2016
# Week 02 Lecture Demonstration File

# Definition of Fahrenheit to Celsius function
# (similar to that presented in Week 01 Lab
#  but with no explicit "convert to float" statement)

def f_to_c(input_val):
    return (input_val - 32.0) * 5.0 / 9.0

# Demonstration of a while loop

i = 0
# Loop 10 times in a while loop
# (from i = 0 through i = 9)
while i < 10:
    print("Looping with i = ",i)
    i += 1

print("Left the while loop")

# Demonstraiton of a for loop

# Loop 10 times in a for loop
# (from i = 0 through i = 9)
for j in range (0,10):
    print("Looping with j = ", j)

# A for loop with a different "step" value
# In this case, j is decreased by 3 each time
for k in range (15,-24,-3):
    print("Looping with k = ", k)

# Another look at weak data typing
# In the statements below, we confirmed that input
# will deafult to type 'str'

sample_input = input("Enter a value: ")
print("Type of data entered is: ", type(sample_input))

# And that we can change a variable's data type 

sample_input = int(sample_input)
print("Type of data is now: ", type(sample_input))

# Also, different number types are supported
# Prepend 0b to binary numbers and 0x to hex numbers
# However, to print different number bases we need to
# specify a format (to be covered later) -- in this case,
# the number output will be in base 10

hex_value1 = 0x1e45
hex_value2 = 0xcd5f
print(hex_value1 + hex_value2)

# Some string methods
# A string is an object in Python, and the string
# object is defined with some methods (built-in functions)
# that are illustrated below

sample_string = "abcdefgh"
print(sample_string)
print("Replace c with $: ")
print(sample_string.replace('c','$'))

# The string can also be addressed as an array of characters
# The three values in the [::] notation are beginning, end,
# and step of the "slice" being taken out of the string

# Note: arrays start at position (offset) 0, and the second
# value in the slice is similar to the range value in a for
# loop -- the range 1:4 start at 1 and is 4-1 or 3 chars long
# so position #4 is *not* in the slice

print("substr from position 1 to position 3")
print(sample_string[1:4])
print("special slice, every other character")
print(sample_string[::2])
