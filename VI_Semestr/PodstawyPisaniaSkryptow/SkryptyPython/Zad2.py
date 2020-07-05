from collections import Counter

def licznik(zdanie):
    for a, b in zdanie:
        if b>1:
            print(a)

zdanie = Counter(input()).most_common()
licznik(zdanie)
