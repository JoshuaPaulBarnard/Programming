def pig_latin(word):
        lst = ['sh', 'gl', 'ch', 'ph', 'tr', 'br', 'fr', 'bl', 'gr', 'st', 'sl', 'cl', 'pl', 'fl']
        word = word.split()
        for k in range(len(word)):
                i = word[k]
                if i[0] in ['a', 'e', 'i', 'o', 'u']:
                        word[k] = i+'-ay'
                elif t(i) in lst:
                        word[k] = i[2:] + '-' + i[:2]+'ay'
                elif i.isalpha() == False:
                        word[k] = i
                else:
                        word[k] = i[1:]+ '-' + i[0]+'ay'
        return ' '.join(word)

def t(str):
        return str[0]+str[1]

if __name__ == "__word__":
        x = word()
        print(x)
