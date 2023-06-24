# CS232-03-jpb68.py
# Name:  Joshua P. Barnard
# Last Modified: 4/14/16


from random import randrange
from string import *
import os
os.chdir("T:\My Documents\Academia\CS 232")
WORDLIST_FILENAME = "words.txt"
secret_word = 'claptrap' 
letters_guessed = []

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

words_dict = load_words()

def get_word():
    """
    Returns a random word from the word list
    """
    word = words_dict[randrange(0, len(words_dict))]
    return word


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
    secret_letters = list(secret_word)
    count = 0
    i = 0

    for i in range(len(secret_word)):
        if secret_word[i] in letters_guessed:
            count = count + 1

    if count == len(secret_word):
        return True
    else:
        return False


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

def GameBoard(hangman_images, missedLetters, correctLetters, secret_word):
    print(hangman_images[len(missedLetters)])
    print()
    blanks = '_' * len(secret_word)
    
    print('Letters Guessed:', end=' ')
    for letter in missedLetters:
        print(letter, end=' ')
    print()

    for i in range(len(secret_word)):
        if secret_word[i] in correctLetters:
            blanks = blanks[:i] + secret_word[i] + blanks[i+1:]

    for letter in blanks: 
        print(letter, end = ' ')
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
    secret_word  = get_word()
    print('H A N G M A N\n    Please Enter a Letter')
    missedLetters = ''
    correctLetters = ''
    gameIsDone = False
    countCorrect = 0

    while gameIsDone == False:
        GameBoard(hangman_images, missedLetters, correctLetters, secret_word)
        guess = getGuess(missedLetters + correctLetters)
        
        if guess in secret_word:
            correctLetters = correctLetters + guess
            foundAllLetters = True
            countCorrect = countCorrect + 1
            
            for i in range(len(secret_word)):
                 if secret_word[i] not in correctLetters:
                    foundAllLetters = False
                    break
            
            if foundAllLetters == True:
                print('Yes! The secret word is "' + secret_word + '"! You have won!')
                gameIsDone = True

        else:
            missedLetters = missedLetters + guess

            if len(missedLetters) == len(hangman_images) - 1:
                GameBoard(hangman_images, missedLetters, correctLetters, secret_word)
                print('You have run out of guesses!\nAfter ' + str(len(missedLetters)) + ' wrong guesses and ' + str(len(correctLetters)) + ' correct guesses, the word was "' + secret_word + '"')
                gameIsDone = True

                if gameIsDone == True:
                    if playAgain() == True:
                        missedLetters = ''
                        correctLetters = ''
                        gameIsDone = False
                        secret_word  = get_word()
                else:
                    break


