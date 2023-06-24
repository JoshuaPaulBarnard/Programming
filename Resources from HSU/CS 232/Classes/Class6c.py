
mygenerator = (x * x for x in range (0, 3))
for i in mygenerator:
    print(i)

def create_generator():
    mylist = range(3)
    for i in mylist:
            yield i * i

mygenerator2 = create_generator()
print(mygenerator2)

for i in mygenerator2:
    print(i)
    j = input("This is to pause execution, enter a letter: ")
