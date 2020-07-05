from pathlib import Path
import os

def getListOfFiles(dirpath):
    listOfFile = os.listdir(dirpath)
    allFiles = list()

    for entry in listOfFile:
        fullPath = os.path.join(dirpath,entry)
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            s = fullPath.rfind("\\")
            if fullPath[s+1:] in allFiles:
                pass
            else:
                allFiles.append(fullPath[s + 1:])

    return allFiles



print(getListOfFiles("M:/Programming/VISemestr/SkryptyPython/venv"))