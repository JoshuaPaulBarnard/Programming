def letter_freq(word):
    word = word.lower()
    letterfreq={}
    for letter in word:
        letterfreq[letter] = 0
    for letter in word:
        letterfreq[letter] += 1
    return letterfreq
