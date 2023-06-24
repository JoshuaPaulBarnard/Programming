# CS 232 - Spring 2016
# Week 4 In-Class Demonstration File

# (My apologies, I didn't capture the lecture file!
# I'll try to recreate much of it here...)

# Tuples are like lists, except that they are "immutable,"
# that is, the items in a tuple cannot be changed
# This means tuples are like "const" declarations in C++
# Parentheses () are used to indicate a tuple

>>> a_tuple = ("John", "Paul", "George", "Ringo")

# The tuple() function can turn a list into a tuple

>>> b_list = ["Pete", "Roger", "Peter", "Keith"]
>>> b_tuple = tuple(b_list)
>>> b_tuple
('Pete', 'Roger', 'Peter', 'Keith')
>>> b_tuple[1]
'Roger'
>>> 

# We played with lists as items of tuples (perfectly legal!)
# and determined that you could mutate the list in a tuple --
# it comes down to what the "lowest level" type is

# Dictionaries are unordered lists that use something
# other than the standard non-negative integer for their
# index values (called "keys")

# Dictionaries consist of "key : value" pairs
# Braces {} are used to indicate a dictionary

>>> a_dict = { 'a': 1 , 'e': 5 , 'i': 9, 'o': 15 , 'u': 21 }

# Because the dictionary has no "order", when it is displayed
# the entries may be in any order

>>> a_dict
{'o': 15, 'e': 5, 'u': 21, 'a': 1, 'i': 9}

# The key value is used in place of the numeric index

>>> a_dict['i']
9

# Dictionaries are mutable

>>> a_dict['i'] = 99
>>> a_dict
{'o': 15, 'e': 5, 'u': 21, 'a': 1, 'i': 99}

# Note that this means values used for keys must be unique,
# that is, there is only one value for a_dict['i']
# Dictionaries, however, can have lists for values
# Here is an example of some integers and their factors

>>> factors = {
	6 : (1,2,3,6), 8 : (1,2,4,8), 24 : (1,2,3,4,6,8,12,24) }
>>> factors
{8: (1, 2, 4, 8), 24: (1, 2, 3, 4, 6, 8, 12, 24), 6: (1, 2, 3, 6)}

# A "quick" dictionary can be made using the dict() function
# from a group of 2-lists, 2-tuples, or even 2-character strings

>>> quick_dict = dict(((1,'a'),(2,'b'),(3,'c')))
>>> quick_dict
{1: 'a', 2: 'b', 3: 'c'}

# The update() method is the cleanest way (not the only way!) to
# add a new "entry" (key:value pair) to a dictionary
# We played with several ways to do this, but I won't reproduce
# them here

>>> quick_dict.update({4: 'd'})
>>> quick_dict
{1: 'a', 2: 'b', 3: 'c', 4: 'd'}

# The del command (not a method, not a function!) removes an entry

>>> del quick_dict[4]
>>> quick_dict
{1: 'a', 2: 'b', 3: 'c'}

# clear() empties a dictionary

>>> quick_dict.clear()
>>> quick_dict
{}

# The "in" keyword is very useful here, both for searching for a
# key in a dictionary, and to iterate through a dictionary's keys

>>> a_dict = { 'a': 1 , 'e': 5 , 'i': 9, 'o': 15 , 'u': 21 }
>>> 'u' in a_dict
True
>>> for the_letter in a_dict:
	print("The letter is ", the_letter,
	      " and the number is ", a_dict[the_letter])
The letter is  o  and the number is  15
The letter is  e  and the number is  5
The letter is  u  and the number is  21
The letter is  a  and the number is  1
The letter is  i  and the number is  9
>>> 

# Some useful dictionary methods:
# keys() will extract the keys from a dictionary
# values() will extract the values from a dictionary
# items() will extract the pairs from a dictionary
# These can then be inputted into list() or tuple()
>>> list(a_dict.keys())
['o', 'e', 'u', 'a', 'i']
>>> tuple(a_dict.values())
(15, 5, 21, 1, 9)
>>> a_dict.items()
dict_items([('o', 15), ('e', 5), ('u', 21), ('a', 1), ('i', 9)])

# Sets are essentially dictionary keys without associated values
# This closely mimics the proerties of a mathematical set, where
# separate items with duplicate values are folded into one item

>>> a_set = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }
>>> a_set
{1, 2, 3, 4, 5}

# Sets can be quickly made from a string using the set() function
>>> set("Mississippi")
{'M', 'p', 's', 'i'}

# Operations on sets are also available:
# & is intersection (items in both sets)
# | is union (items in either set)
# - is difference (items in first set that are not in second)
#   NOTE: The - operation is *not* symmetric!
# ^ is XOR (exclusive OR) - items in one of the sets but NOT both

# Boolean operations are also available:
# < for proper subset
# > for proper superset
# <= for subset
# >= for superset
# == for exact match of sets

# The IHOP Omlette example from class:
# Define a dictionary where the key is the name of the omlette
# on the IHOP menu, and the value is a set of the ingredients
# in the omlette (except the eggs, which all have, of course)

IHOP_omlettes = {
    "Big Steak" : {"steak", "hashbrowns", "peppers", "onions",
                   "mushrooms", "tomatoes", "cheese"},
    "Country" : {"ham", "cheese", "onions", "hashbrowns",
                 "sour cream"},
    "Hearty Ham & Cheese" : {"ham", "cheese"},
    "Bacon Temptation" : {"bacon", "cheese", "tomatoes"},
    "Spinach & Mushroom" : {"spinach", "mushrooms", "onions",
                            "cheese", "tomatoes"},
    "Colorado" : {"bacon", "sausage", "beef", "ham", "onions",
                  "peppers", "cheese"},
    "Garden" : {"broccoli", "mushrooms", "tomatoes", "cheese"},
    "Chicken Fajita" : {"chicken", "onions", "peppers", "salsa",
                        "cheese", "sour cream"}}

# with_ingredient: str -> list
# purpose: expects an ingredient name
#   returns a list of all IHOP omlettes containing that ingredient
def with_ingredient(the_ingredient):
    style_list = []
    for style, contents in IHOP_omlettes.items():
        if the_ingredient in contents:
            style_list.append(style)
    return style_list

