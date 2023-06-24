
# Purpose:  Testing if the words are infact in order

import lab03

print("testing lab03 module for words_in_order:")

print( "lab03.words_in_order('The rain in Spain stays mainly in the plain')")
print("Should return: 'in, in, mainly, plain, rain, spain, stays, the, the'") 
print(lab03.words_in_order('the rain in Spain stays mainly in the plain'))


print( "lab03.words_in_order('Z x R w A c')")
print("Should return: 'a, c, r, w, x, z'") 
print(lab03.words_in_order("Z x R w A c"))
