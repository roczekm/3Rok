import re

def deleteComments(string):
    string = re.sub(re.compile("/\*.*?\*/\n",re.DOTALL ) ,"" ,string)
    string = re.sub(re.compile("//.*?\n" ) ,"" ,string)
    return string


print("Podaj nazwe pliku")
filename = input()
f = open(filename, "rt")
text = f.read()
g = open(filename, "w")

g.write(deleteComments(text))
g.close()

