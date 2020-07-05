import calendar
import datetime
import locale

locale.setlocale(locale.LC_ALL, 'pl_PL')

print("Podaj miesiac i rok")
date = input()

month_name = date.split()[0]
year=date.split()[1]
datetime_object = datetime.datetime.strptime(month_name, "%B")
month_number = datetime_object.month
print(month_number)

kalendarz=calendar.TextCalendar(calendar.MONDAY)
str = kalendarz.formatmonth(int(year), month_number, 0, 0)
print(str)