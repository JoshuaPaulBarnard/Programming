#  Exam #2:  Thursday April 21st
#           50 minute exam in Lab


#  Class of Objects

#  Properties - Fields of Data
#  Create Instance Object - __init__


class Person ():
    def __init__(self, name):
        self.name = name

    def introduce (self):
        print("I'm " + self.name)

dave = Person("David Tuttle")
dave
dave.name
dave.introduce()
Person.introduce(dave)


#  Python Class:
#   Instance is Object -> Data Fields
#   Function is Method
#   Data Fields


class Student(Person):
    def __init__(self, name, major, student_id, year):
        Student.count += 1
        super().__init__(name)
        self.major = major
        self.student_id = student_id
        self.year = year
        if self.__year == 2019:
            self.__grad_class = "First-Year"
        elif self.__year == 2018:
            self.__grad_class = "Sophomore"
        elif self.__year == 2017:
            self.__grad_class = "Junior"
        elif self.__year == 2016:
            self.__grad_class = "Senior"
        else:
            self.__grad_class = "weirdo"

    #def get_major(self):
    #    return self.major

    #def change_major(self, new_major):
    #    self.major = new_major

    @property
    def major(self):
        return self.__major

    @major.setter
    def major(self, new_major):
        self.__major = new_major

    def introduce(self):
        print("I'm ", self.name, " and I'm a ", self.__grad_class)

    #major = property(get_major, change_major)

    @classmethod
    def num_students(cls):
        print("There are ", cls.count, " student entered.")

    def __eq__(self, other_student):
        student1 = self.name.split()
        print("student1 is ", student1)
        student 2 = other_student.name.split()
        print("student2 is ", student2)
        if student1[0].lower() == student2[0].lower():
            print("Same first name of ", student1[0], " !!!")
        
        


joe = Student("Joe", "Comp Sci", 1234567, 2016)
joe.name
joe.introduce()
joe.student_id
joe.year
joe.major
major = property(get_major, change_major)
dave = Student("David Tuttle", "Comp Sci", 2345567, 2018)
william = Student("William Walker", "Comp Sci", 9864435, 2018)
Student.num_students()
rebecca = Student("Rebecca Williams", "Comp Sci", 9585949, 2017)
Student.num_students()
dave.count
rebecca.count

# __init__ <- Built in Functions
# + in string operations

# == has name __eq__


#  property(_get_value_, _set_value_)


josh_a = Student("Josh Alpert", "Comp Sci", 4534546, 2018)
josh_b = Student("Josh Barnard", "Psychology", 029484849, 2016)
josh_a == josh_b

