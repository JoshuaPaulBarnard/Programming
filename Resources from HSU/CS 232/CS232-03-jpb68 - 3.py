# CS232-03-jpb68.py
# Name:  Joshua P. Barnard
# Last Modified: 4/14/16

# Adapted from MIT 6.189, MIT Open COurseware
# Project 1: Hangman template
# hangman_template.py

# Import statements: DO NOT write code above this!
from random import randrange
from string import *
import os

# Uncomment the next statement and place the directory where
# the Python module and words.txt files are located
os.chdir("T:\My Documents\Academia\CS 232")

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
    correctLetters = list(secret_word)

    for i in range(len(secret_word)):
        if letters_guessed[i] not in correctLetters:
            return False
        else:
            return True

            

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
    blanks = '_' * len(secret_word)
    correctLetters = list(secret_word)

    for i in range(len(letters_guessed)):
        if letters_guessed[i] in correctLetters:
            blanks = blanks[:i] + letters_guessed[i] + blanks[i+1:]

    for letters_guessed in blanks: 
        print(letters_guessed, end = ' ')
    print()


# play_hangman: void -> void
# purpose: expects nothing, anf return nothing
# This function should control the playing of the game Hangman by choosing a
# secret word, asking the player for letters to guess, and displaying both
# the Hangman image and displaying how much of the word has been guessed after
# each letter is entered
hangman_images = ['''
        __________
        |    |       
        |
        |
        |
        |
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |
        |
        |
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |    |
        |    |
        |
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |   /|
        |    |
        |
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   /
        |_________
        ''', '''
        __________
        |    |       
        |    O
        |   /|\\
        |    |
        |   / \\
        |_HANGED!_

        ''']

def GameBoard(print_hangman_images, missedLetters, correctLetters, secret_word):
    global letters_guessed
    print(print_hangman_images[mistakes])
    print()
    blanks = '_' * len(secret_word)
    correctLetters = list(secret_word)
    mistakes = 0
    print('Missed letters:', end=' ')
        

    for i in range(len(letters_guessed)):
        if letters_guessed[i] in correctLetters:
            blanks = blanks[:i] + letters_guessed[i] + blanks[i+1:]

    for i in range(len(letters_guessed)):
        if letters_guessed[i] not in correctLetters:
            missedLetters = missedLetters + letters_guessed[i]

    for letters_guessed in blanks: 
        print(letters_guessed, end = ' ')
    print()

def getGuess(alreadyGuessed):
    while True:
        print('Guess a letter: ')
        guess = input()
        guess = guess.lower()
        if len(guess) != 1:
            print('Please enter a single letter.')
        elif guess in alreadyGuessed:
            print('You have already guessed that letter. Please Choose again.')
        elif guess not in 'abcdefghijklmnopqrstuvwxyz':
            print('Please enter a single letter only.')
        else:
            return guess


def playAgain():
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')

def play_hangman():
    global secret_word
    global letters_guessed
    mistakes_made = 0
    secret_word  = get_word()
    print('H A N G M A N')
    missedLetters = ''
    correctLetters = ''
    gameIsDone = False

    while True:
        GameBoard(print_hangman_images, missedLetters, correctLetters, secret_word)
        guess = getGuess(missedLetters + correctLetters)
        if guess in secret_word:
            correctLetters = correctLetters + guess

    foundAllLetters = True
    for i in range(len(secret_word)):
        if secret_word[i] not in correctLetters:
            foundAllLetters = False
            break
    if foundAllLetters:
        print('Yes! The secret word is "' + secretWord + '"! You have won!')
        gameIsDone = True
    else:
        missedLetters = missedLetters + guess

    if len(missedLetters) == len(print_hangman_images) - 1:
        displayBoard(print_hangman_images, missedLetters, correctLetters, secret_word)
        print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' missed guesses and ' + str(len(correctLetters)) + ' correct guesses, the word was "' + secret_word + '"')
        gameIsDone = True

    if gameIsDone:
        if playAgain():
            missedLetters = ''
            correctLetters = ''
            gameIsDone = False
            secret_word  = get_word()


