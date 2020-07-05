def readPhoneNumber(nr):
    numer = str()
    for ch in nr:

        if ch >= '0' and ch <='9':
            numer += ch
        else:
            pass


    return numer

nr = "+4-8-6-0-3-2-1-8-9-1-3"
print(readPhoneNumber(nr))

print("Podaj numer telefonu")
nr = input()

print(readPhoneNumber(nr))
