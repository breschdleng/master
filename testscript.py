import os


class Employee:
    def __init__(self,age, name, gender):
        self.age = age
        self.name = name
        self.gender =gender
  
    def _printattributes(self):
        print("Age {}, Name {}, Gender {}".format(self.age, self.name, self.gender))


if __name__ == "__main__":

    emp1 = Employee(27,"Bow","Male")
    emp1._printattributes()
    print(emp1.age)
    print("Inside Main")
    emp2 = Employee(29,"cow","Female")

    
