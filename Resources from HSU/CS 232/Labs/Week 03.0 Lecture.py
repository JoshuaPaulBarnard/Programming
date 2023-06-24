# CS 232 Spring 2016
# Week 03 Demonstration File

# Python Lists

# The split method of the string data type
# creates a list from a string.  An argument
# of a string can specify what separates the
# items of the list - the default is a space

>>> a_string = "arf woof meow"
>>> a_string.split()
['arf', 'woof', 'meow']

# A list is an ordered grouping of
# data, which can be of any type

>>> a_list =  [ True, 'A', 37.4, 6 ]

# Items in a list can be addressed using
# an index, like in an array

>>> a_list[0]
True
>>> a_list[3]
6

# The index can also be used to mutate
# (change) an item in a list.  The type
# of a list item can also change

>>> a_list[3] = 7
>>> a_list
[True, 'A', 37.4, 7]
>>> a_list[3] = "FRED"
>>> a_list
[True, 'A', 37.4, 'FRED']

# A list is an object, just like a str or int

# A list is called a "molecular" object,
# as it's composed of elementary atomic
# objects (str, int, bool, float) and other
# molecular objects

# List Methods
# The remove method mutates the list by
# removing an item based on its value

>>> a_list = [1, 2, 3]
>>> a_list.remove(2)
>>> a_list
[1, 3]

# The del command (NOT a method!) can
# delete an item from a list based on its
# location (index) in the list

>>> a_list = [1, 2, 3]
>>> del a_list[2]
>>> a_list
[1, 2]

>>> a_list = [3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6]

# The len function (NOT a method) gives the length of
# a list.  It's not a method because len() works for
# multiple types (such as the length of a string)

>>> len(a_list)
14
>>> a_string = "1234567"
>>> len(a_string)
7

# The count method gives the number of items in a list
# that match the given value

>>> a_list.count(4)
3

# The append method will add an item to a list

>>> a_list.append("FRED")
>>> a_list
[3, 4, 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 'FRED']

# The insert method inserts an item at a specified
# index location

>>> a_list.insert(2, "WILMA")
>>> a_list
[3, 4, 'WILMA', 5, 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 'FRED']

# Note the following peculiar property of molecular objects
# such as lists - a list's "variable name" is actually a pointer
# so an assignment like the statement below doesn't copy the
# list.  It instead creates another pointer that points at the
# same list.  If you want to copy a list, there's a copy method
# to do that.

>>> b_list = a_list
>>> b_list.insert(4, "BARNEY")
>>> b_list
[3, 4, 'WILMA', 5, 'BARNEY', 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 'FRED']
>>> a_list
[3, 4, 'WILMA', 5, 'BARNEY', 6, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 'FRED']

# Note that a list can be an item in another list!  So the list
# object type is recursive!

>>> a_list = [1, 2, 3]
>>> b_list = [4, 5, 6]
>>> a_list.append(b_list)
>>> a_list
[1, 2, 3, [4, 5, 6]]
>>> a_list[3]
[4, 5, 6]

# Because a_list[3], the item in a_list, is a list itself,
# if can methods run on it

>>> a_list[3].remove(5)
>>> a_list
[1, 2, 3, [4, 6]]

# The extend method concatenates two lists into a single list
# Note that this is different from the append method above
# The + operator works similarly to extend, except that + does
# not mutate a list, while extend does mutate the list

>>> a_list = [1, 2, 3]
>>> b_list = [4, 6]
>>> a_list + b_list
[1, 2, 3, 4, 6]
>>> a_list.extend(b_list)
>>> a_list
[1, 2, 3, 4, 6]

# Suppose the following function is defined:

# string_it: list -> list
# purpose: expects a list of atomic objects
#    returns a list with all objects converted
#    to strings
def string_it(input_list):
    output_list = []
    for i in range (0,len(input_list)):
        output_list.append(str(input_list[i]))
    return output_list

# Import the module containing the above function, and...

================ RESTART: C:/Users/David/Desktop/string_it.py ================
>>> string_it([True, 1, -3.75, "Moo"])
['True', '1', '-3.75', 'Moo']
>>> the_list = string_it([True, 1, -3.75, "Moo"])
>>> the_list
['True', '1', '-3.75', 'Moo']

# The pop method removes the last item from a list,
# mutating the list, and also returns thevalue removed
# This mimics the action of a "pop" on a stack data structure

>>> a_list = [1, 2, 3, 4]
>>> last_val = a_list.pop()
>>> last_val
4
>>> a_list
[1, 2, 3]

# Two methods can sort a list (which all same-type items)
# The sort method mutates the list, rearranging in sorted order
# The sorted method does not mutate the list -- it instead
# returns a sorted list

>>> a_list = [4, 7, 1, 3, 9, 7, 4, 6]
>>> sorted(a_list)
[1, 3, 4, 4, 6, 7, 7, 9]
>>> a_list
[4, 7, 1, 3, 9, 7, 4, 6]

>>> a_list.sort()
>>> a_list
[1, 3, 4, 4, 6, 7, 7, 9]
>>> 
