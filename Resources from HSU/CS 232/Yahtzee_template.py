# Yahtzee_template.py
# Created by David C. Tuttle
# Last modified: April 17, 2016

import random
import collections

SIDES = 6
NUM_DICE = 5
NUM_ROLLS = 3
NUM_TESTS = 1000

# Insert code here to create Die() class and methods


# is_yahtzee: list of Die objects -> boolean
# purpose:  expects a list of Die objects
#    returns True if all values of Die object match (a Yahtzee)
#    returns False otherwise
def is_yahtzee(the_dice):
    result = True
    for i in range(1, NUM_DICE):
        if the_dice[i].value() != the_dice[i-1].value():
            result = False
    return result

# print_dice: list of Die objects -> nothing
# purpose: expects a list of Die objects
#    returns nothing
# side effect: prints to screen the values on the dice
def print_dice(the_dice):
    print("The dice values are: {}".format([the_dice[i].value() for i in range(0,NUM_DICE)]))

# best_value_to_keep: list of Die objects -> int
# purpose: expects a list of Die objects
#    examines the values of the dice, and determines which value is most common
#    returns that most common value
# Examples: the_dice values of [1, 5, 4, 5, 5] will return 5
#           the_dice values of [2, 6, 2, 6, 4] will return 6

def best_value_to_keep(the_dice):
    # Create a counter dictionary of the values in the_dice
    dice_counter = collections.Counter(the_dice[i].value() for i in range(0, NUM_DICE))
    
    # Look for the highest number of dice that match each other
    dice_that_match = max(dice_counter.values())
    
    # Find which value on the dice (that is, which key in the counter)
    # corresponds to dice_that_match
    for i in list(dice_counter.keys()):
        if dice_counter[i] == dice_that_match:
            value_to_keep = i
            
    # value_to_keep now is the most commonly found value on the dice
    return value_to_keep

# *************** play_yahtzee code goes here ********************

# play_yahtzee: list of Die objects -> boolean
# purpose: expects a list of Dir objects
#     plays Yahtzee with the dice to try to get a Yahtzee
#     returns True if a Yahtzee is made or False otherwise
# side effect: prints to the screen the values of the dice
#     (using print_dice) after each roll, and a single-line
#     "Yahtzee" or "No Yahtzee" message at the end



# *************** end play_yahtzee code **************************

# *** The "main" code goes here ***

# First, create a list called my_dice of Die objects

# Then, either call play_yahtzee(my_dice) once, or write a
# loop to call play_yahtzee(my_dice) multiple times, based
# on NUM_TESTS, and print the results


