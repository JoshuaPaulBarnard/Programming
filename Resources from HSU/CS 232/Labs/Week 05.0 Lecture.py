# CS 232 Spring 2016
# Week 05 In-Class Presentation

# The "break" command can be used to exit a loop when
# a condition is met.  This is very useful in loops
# that have "while True" as their condition

>>> for i in range(0,20):
	if i > 5:
		break
	print("i is ", i)
	
i is  0
i is  1
i is  2
i is  3
i is  4
i is  5

>>> while True:
	input_val = input("Enter a value, or q to exit: ")
	if input_val == 'q':
		break
	print("You entered the value ", input_val)

	
Enter a value, or q to exit: 475
You entered the value  475
Enter a value, or q to exit: 234
You entered the value  234
Enter a value, or q to exit: -1
You entered the value  -1
Enter a value, or q to exit: q

# The "continue" command does not exit the loop, but
# instead skips execution of the rest of the code
# in the loop and goes directly back to the top of
# the looping code block

>>> for i in range (0,20):
	if i % 2 == 0:
		continue
	print("The value of i is ", i)
	
The value of i is  1
The value of i is  3
The value of i is  5
The value of i is  7
The value of i is  9
The value of i is  11
The value of i is  13
The value of i is  15
The value of i is  17
The value of i is  19

# "Zipping" lists together is easy with the zip function
# It will create tuples containing one element from each
# list. in order, until one of the lists has been exhausted

>>> animals = ["bear", "cougar", "owl", "aardvark"]
>>> foods = ["berries", "humans", "mice"]
>>> locations = ["forest", "restaurant", "tree", "jungle"]

>>> zip(animals, foods, locations)
<zip object at 0x038C7418>

# Note that zip() does not default to making a particular
# molecular data type -- using the list(), tuple(), set()
# (or if there are only 2 lists being zipped, dict()) is
# needed to make the desired data type.  This is a Python 3
# feature that helps with efficiency in using system resources

>>> list(zip(animals, foods, locations))
[('bear', 'berries', 'forest'), ('cougar', 'humans', 'restaurant'), ('owl', 'mice', 'tree')]

>>> zipped_list = zip(animals, foods, locations)
>>> zipped_list
<zip object at 0x038CE300>
>>> list(zipped_list)
[('bear', 'berries', 'forest'), ('cougar', 'humans', 'restaurant'), ('owl', 'mice', 'tree')]

# "Comprehensions" can quickly build list-type structures in an
# algorithmic way, by embedding code that can build and conditionally
# select 

>>> [number for number in range (0,10)]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

>>> {number: number + 3 for number in range (0,10)}
{0: 3, 1: 4, 2: 5, 3: 6, 4: 7, 5: 8, 6: 9, 7: 10, 8: 11, 9: 12}

>>> {number: number + 3 for number in range (0,10) if number % 2 == 1}
{1: 4, 3: 6, 9: 12, 5: 8, 7: 10}

# The prime number sieve example as presented in class
# (minus the false starts):
# First, a way to determine the factors of an integer

>>> [x for x in range(2,1000) if 1000 % x == 0]
[2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500]

# A prime number will generate a list of length 0

>>> [x for x in range(2,13) if 13 % x == 0]
[]

# Using the len() function will result in a 0
# This is how we'll detect whether a number is prime

>>> len([x for x in range(2,13) if 13 % x == 0])
0

>>> max_val = 500

# Now, we use the expression above to test all numbers
# "value" from 2 to max_val - if value passes the prime
# test (factor list has length 0), it is included in the list

>>> [value for value in range (2,max_val) \
 if len([x for x in range(2,value) if value % x == 0]) == 0]
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
 467, 479, 487, 491, 499]

# This is not the most efficient method, but it is relatively
# quick to code!

# Some fun and interesting properties of Python functions

# func: args -> float
# purpose: expects an arbitrary number of arguments
#    returns the sum of all the arguments that are of type
#    int or float
# side effect: prints arguments that are not of type int or
#    float

# "*args" means all values passed to the function will be
# placed in a tuple called "args" (args can be called anything,
# it's just traditional to use the identifier name "args")

# Also, the string at the beginning of the function is a docstring,
# not executed as code.  If the help() function is used by typing
# "help(func)" the docstring will be displayed.  It's a quick and
# useful way for a function's writer to provide a quick documentation
# to a function's user

def func(*args):
    'This function adds all numeric values passed to it'
    sum = 0
    for i in range(0,len(args)):
        if type(args[i]) == int or type(args[i]) == float:
            sum += args[i]
        else:
            print("Ignored ", args[i])
    return sum

>>> help(func)
Help on function func in module __main__:

func(*fred)
    This function adds all numeric values passed to it

>>> func(3,4,5)
12

>>> func(4, 5, 6, 7,8)
30

>>> func(4, 5, 6, "wilma", True, {'a':1, 'b':2})
Ignored  wilma
Ignored  True
Ignored  {'b': 2, 'a': 1}
15

# It's also possible to specify values for named parameters
# in a function.  Let's create a function for adding
# three values a, b, and c together
def add_func(a, b, c):
        return a + b + c

# If a user knows the names of the parameters, they can be
# specified in the function call.  In this way, they can
# even be presented out of "order"

>>> add_func(a=3, b=4, c=5)
12

>>> add_func(c=7, a=4, b=6)
17

# Note that positional arguments must come before the named
# arguments, so care must be taken when mixing the two
# argument passing methods

>>> add_func(4, b=6, c=7)
17

>>> add_func(b=6, c=7, 4)
SyntaxError: positional argument follows keyword argument

>>> add_func(4, a=6, b=7)
Traceback (most recent call last):
  File "<pyshell#57>", line 1, in <module>
    func(4, a=6, b=7)
TypeError: add_func() got multiple values for argument 'a'

# "**kwargs" makes use of the Python feature called "keyword
# arguments".  This allows a function call to send all arguments
# in the form "name=value", and the function will turn all arguments
# into dictionary entried of the form { name : value }

# "**kwargs" means all values passed to the function will be
# placed in a dictionary called "kwargs" (kwargs can be called
# anything, it's just traditional to use the identifier name "kwargs")

# func2: kwargs -> float
# purpose: expects an arbitrary number of keyword arguments
#    returns the sum of all the arguments whose keys are all lower-case
# side effect: prints all dictionary entries to the screen

def func2(**kwargs):
    '''
    This is a multi-line docstring!
    This function requires all arguments be passed as keywords
    This function assumes all keyword names are strings, and all
    values are int or float.  It returns the sum of all values
    whose keyword names are all lower-case
    '''
    sum = 0
    for i in kwargs:
        print("Dictionary entry is ", i, ", ", kwargs[i])
    #    lower_case_key = i.lower()
    #    if a == i.lower():
        if i.islower():
            sum += kwargs[i]
    return sum

>>> help(func2)
Help on function func2 in module __main__:

func2(**kwargs)
    This is a multi-line docstring!
    This function requires all arguments be passed as keywords
    This function assumes all keyword names are strings, and all
    values are int or float.  It returns the sum of all values
    whose keyword names are all lower-case

>>> func2(a=1,b=2,c=3)
Dictionary entry is a, 1
Dictionary entry is c, 3
Dictionary entry is b, 2
6

>>> func2(a=1,b=2,c=3,D=4,E=5,f=6)
Dictionary entry is E 5
Dictionary entry is f 6
Dictionary entry is c 3
Dictionary entry is b 2
Dictionary entry is a 1
Dictionary entry is D 4
12
>>> 

# As we saw above in the help() function:
# *** Functions can be passed as arguments ***

# In fact, it's even possible to fully define a function as
# an argument by making use of a "lambda" function.

# A "lambda" function is an "anonymous" (unnamed) function
# that can be created at runtime!  To demonstrate this, let's
# write a small function that takes a function as an argument

# perform_it: list -> list
# purpose: expects a list of numeric values, and a function
#    that expects a number and returns a number
#    returns a list where each element is the return value
#    or running the passed function on the input element 

def perform_it(num_list,the_func):
    output_list = []
    for num in num_list:
        output_list.append(the_func(num))
    return output_list

inc_value = 5

>>> perform_it([1, 2, 3, 4, 5], lambda x : x + inc_value)
[6, 7, 8, 9, 10]
