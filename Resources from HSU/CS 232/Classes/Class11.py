#  Python Programming - CS 232
#  HSU - Spring 2016
#  Class #11

class Person():
    def __init__(self, name):
        self.name = name
    

#  me = Person()
#  me.__class__()
#  spouse = Person('David Tuttle')
#  spouse
#  spouse.name
#  spouse.name = 'David C. Tuttle'
#  spouse.name

class Student(Person):
    def __init__(self, name, id_num):
        super().__init__(name)
        self.id_num = id_num

#  max = Student("Max Lemos", 1234567)
#  max.id_num
#  max.name

class Car():
    def __init__(self, model):
        self.model = model

#  my_car = Car('Yugo')
#  my_car.model

class Instructo(Person):
    pass

#  sharon = Instructor("Sharon Tuttle")
#  sharon.name
#  type(sharon)

class Person():
    def __init__(self, name):
        self.name = name
    def introduce(self):
        print("Hello, I'm " + self.name)

#  terry = Person("Terry Tuttle")
#  terry.name
#  terry.introduce()
#  max = Student("Max Lemos", 1234567)
#  max.introduce()
#  max.id_num
#  max.name

class Person(Person):
    def __init__(self, name, id_num, major):
        super().__init__(name)
        self.id_num = id_num
        self.major = major
    def change_major(self, new_major):
        self.major = new_major
    def introduce(self):
        print("Hi, I'm " + self.name + "and my major is " + self.major

#  shyaka = Student("Shyaka Laniesse", 2345678, "Art")
#  shyaka
#  shyaka.major
#  shyaka.introduce()
#  shyaka.change_major("Computer Science")
#  shyaka.major
#  sharon = Person("Sharon Tuttle")
#  sharon.change_major
#  sharon.change_major("Computer Science")
#  shannon = Student("Shannon Carey", 345678, "EMP")
#  shannon.major
#  shannon.introduce()
#



