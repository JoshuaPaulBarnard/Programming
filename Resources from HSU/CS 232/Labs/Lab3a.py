name = 'Cleese Gilliam\tChapman        Idle \t Jones'
name.split()
name.split('e')
actors = name.split()
actors



#join - a string method
#       can take a list as a new argument,
#       and it returns a new string consisting
#       of the list elements seperated by
#       copies of the calling string

' '.join(actors)
actors
'SPAM'.join(actors)

#when you write a function in a Python
#       module (a file whose name ends in .py),
#       then import that module,
#       you can refer to the functions in
#       the module using the syntax:
#   <module-name>.<functname>(...)

#You can import modules within other
#       Python modules, so if you want to
#       write a (seperate) test module, you
#       just put an import statement (importing
#       the function 
