//TASK 3 
import os
import time

def create_zombie():
    pid = os.fork()
    if pid == 0:
        print(f"[Child] PID {os.getpid()} exiting immediately (Zombie Created)")
        os._exit(0)
    else:
        print(f"[Parent] PID {os.getpid()} sleeping. Child PID {pid} becomes zombie.")
        time.sleep(20)  # Keep parent alive so zombie is visible
        os.wait()
        print("[Parent] Reaped zombie child and exiting.")

if __name__ == "__main__":
    create_zombie()

import os

def read_proc_info(pid):
    try:
        print(f"\n📌 Reading /proc/{pid} info\n")

        # Read status
        with open(f"/proc/{pid}/status", "r") as file:
            status_data = file.read()

        print("---- Process Status ----")
        for line in status_data.split("\n"):
            if line.startswith(("Name:", "State:", "VmSize:")):
                print(line)

        # Executable path
        exe_path = os.readlink(f"/proc/{pid}/exe")
        print(f"\nExecutable Path: {exe_path}")

        # File Descriptors
        fd_list = os.listdir(f"/proc/{pid}/fd")
        print(f"\nOpen File Descriptors: {fd_list}")

    except FileNotFoundError:
        print(f"❌ No process exists with PID {pid}")

if __name__ == "__main__":
    pid = int(input("Enter PID to inspect: "))
    read_proc_info(pid)
