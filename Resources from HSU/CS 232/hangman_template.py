# CS232-03-___.py
# Name:
# Last Modified:

# Adapted from MIT 6.189, MIT Open COurseware
# Project 1: Hangman template
# hangman_template.py

# Import statements: DO NOT write code above this!
from random import randrange
from string import *
import os

# Uncomment the next statement and place the directory where
# the Python module and words.txt files are located
# os.chdir(" ")

# -----------------------------------
# Helper code
# (you don't need to understand this helper code, but it might help you to read it)

# Import hangman words

WORDLIST_FILENAME = "words.txt"

def load_words():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'rt')
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    print('Enter play_hangman() to play a game of hangman!')
    return wordlist

# actually load the dictionary (not a Python dictionary, just a list
# words in the English dictionary) and point to it with 
# the words_dict variable so that it can be accessed from anywhere
# in the program
words_dict = load_words()

# Run get_word() within your play_hangman() program to generate a random secret word
# by using a line like this within your program:
# secret_word = get_word()

# get_word: void -> str
# Purpose: expects nothing
#    returns a word rendomly selected from the file "words.txt" 
def get_word():
    """
    Returns a random word from the word list
    """
    word = words_dict[randrange(0, len(words_dict))]
    return word

# NOTE: original ASCII image created by internet artist sk
#       replaced with smaller images by David Tuttle, Spring 2016

# print_hangman_image: int -> void
# Purpose: expects an integer representing the number of incorrect guesses
#    during the Hangman game, and returns nothing
# Side effect: prints to the screen a drawing of the hangman based on the
# number of incorrect guesses
def print_hangman_image(mistakes=6):
  """Prints out a gallows image for hangman.
  The image printed depends on the number of mistakes (0-6)."""

  if mistakes <= 0:
    print('''
        __________
        |    |       
        |
        |
        |
        |
        |_________
        ''')

  elif mistakes == 1:
    print('''
        __________
        |    |       
        |    O
        |
        |
        |
        |_________
        ''')
  elif mistakes == 2:
    print('''
        __________
        |    |       
        |    O
        |    |
        |    |
        |
        |_________
        ''')
  elif mistakes == 3:
    print('''
        __________
        |    |       
        |    O
        |   /|
        |    |
        |
        |_________
        ''')
  elif mistakes == 4:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   
        |_________
        ''')
  elif mistakes == 5:
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   /
        |_________
        ''')
  else: # mistakes >= 6
    print('''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   / \\
        |_HANGED!_

        ''')
  
# end of helper code
# -----------------------------------

# CONSTANTS
MAX_GUESSES = 6

# GLOBAL VARIABLES 
secret_word = 'claptrap' 
letters_guessed = []

# TO BE FILLED IN BY THE PROGRAMMER

# word_guessed: void -> bool
# purpose:  expects nothing
#     returns True if the word in the global variable "secret_word"
#     has been guessed, based on the "letters_guessed" list
#     and returns False otherwise
def word_guessed():
    '''
    Returns True if the player has successfully guessed the word,
    and False otherwise.
    '''
    global secret_word
    global letters_guessed

    ####### YOUR CODE HERE ######
    pass # This tells your code to skip this function; delete "pass" when you
         # start working on this function


# print_guessed: void -> void
# purpose:  expects nothing and returns nothing
# side effect: prints to the screen (on one line) the part of the secret word
# that has been guessed -- for example, if the word is "claptrap" and the letters
# guessed are [a, e, p, t] then it should print "_ _ a p t _ a p"
def print_guessed():
    '''
    Prints out the characters you have guessed in the secret word so far
    '''
    global secret_word
    global letters_guessed
    
    ####### YOUR CODE HERE ######
    pass # This tells your code to skip this function; delete "pass" when you
         # start working on this function

# play_hangman: void -> void
# purpose: expects nothing, anf return nothing
# This function should control the playing of the game Hangman by choosing a
# secret word, asking the player for letters to guess, and displaying both
# the Hangman image and displaying how much of the word has been guessed after
# each letter is entered
def play_hangman():
    # Actually play the hangman game
    global secret_word
    global letters_guessed
    # Put the mistakes_made variable here, since you'll only use it in this function
    mistakes_made = 0

    # Update secret_word. Don't uncomment this line until you get to Step 8.
    # secret_word  = get_word()

    ####### YOUR CODE HERE ######
    return None

    
