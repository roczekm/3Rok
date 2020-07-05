from datetime import date

def diffrence(date1,date2):
    diff=abs(date1-date2)
    print(diff.days)

print("Podaj pierwsza date w formacie :  DD.MM.RRRR")
date1 = input().split(".")
print("Podaj druga date w formacie :  DD.MM.RRRR")
date2 = input().split(".")

date1 = date(int(date1[2]), int(date1[1]), int(date1[0]))
date2 = date(int(date2[2]), int(date2[1]), int(date2[0]))

diffrence(date1,date2)