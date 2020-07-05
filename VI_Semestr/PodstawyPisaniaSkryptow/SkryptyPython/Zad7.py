from collections import Counter

def count10common(*argv):
    for arg in argv:
        with open (arg) as myfile:
            x = Counter(myfile.read().split()).most_common(10)
            f = open(arg,"a+")
            for i in x:
                f.write(str(i) + "\n")
            f.close()


count10common("test1.txt","test2.txt")