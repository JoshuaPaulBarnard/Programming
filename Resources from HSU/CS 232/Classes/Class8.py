
import sys
for i in sys.path:
    print(i)

import moo
moo.mooo("abcde")

from fun import arf
arf.fib_create(10)

my_dict = ['a':1, 'b': 2, 'c': 3]
dict.get(my_dict, 'a')

a = ['Name': 'Katie', 'Age': 7]
a.setdefault('ZIP', 90210)

from collections import defaultdict
periodic_table = defaultdict(int)
periodic_table['H'] = 1
periodic_table['He'] = 2

def no_idea():
    return 'Huh?'

b = defaultdict(no_idea)
b['A'] = "Abominable Snowman"
b['B'] = "Basilisk"
b.update({'C': 'Chimera'})
b['D'] = "Dragon"

# Now using a Lambda Function:
c = defaultdict(lambda: "Huh?")
c['D']
dict(c)

from collections import Counter
dict(Counter([1,2,3,1,2,1,4,5,4,3,2,3,5,1,2,3,3,4]))
dict(Counter(a=2, b=3, c=1))
dict(Counter(x='WOOF', y='MEOW', z='OINK'))

breakfast = ['spam', 'spam', 'eggs', 'spam']
breakfast_counter = Counter(breakfast)
breakfast_counter

d = Counter()
d.update('abcdaab')
d1 = Counter(['a', 'b', 'c', 'b', 'b'])
d2 = Counter('alphabet')

e1 = {'a':1, 'b':2}
e2 = {'a':3, 'b': 4}
e3 = e1 + e2
e4 = e1 - e2
e5 = e1 / e2




