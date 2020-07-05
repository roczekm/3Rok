from pathlib import Path

def foo(word,filepath):
    for path in Path(filepath).iterdir():
        if path.is_file():
            current_file = open(path, "r")
            if word in current_file.read():
                s = current_file.name.rfind("\\")
                #print(current_file.name)
                print(current_file.name[s+1:])

            current_file.close()


foo("Lorem","M:/Programming/VISemestr/SkryptyPython/venv/Nowy folder")