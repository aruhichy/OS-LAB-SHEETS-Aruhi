def script1():
    print("This is script 1 running...")
def script2():
    print("This is script 2 running...")
def script3():
    print("This is script 3 running...")
scripts = [script1, script2, script3]
for script in scripts:
    print(f"\n>>> Executing {script.__name__} ...")
    script()
    print(f"{script.__name__} executed successfully.\n")
