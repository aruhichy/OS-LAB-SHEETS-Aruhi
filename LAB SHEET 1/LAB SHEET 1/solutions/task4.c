//task 4
import psutil
import os

def print_proc_status(proc):
    print("\n---- Process Status Info ----")
    print(f" Name       : {proc.name()}")
    print(f" PID        : {proc.pid}")
    print(f" Status     : {proc.status()}")
    print(f" Memory (MB): {proc.memory_info().rss / 1024 / 1024:.2f}")
    print(f" CPU Usage  : {proc.cpu_percent(interval=0.1)}%")

def print_exe_path(proc):
    print("\n---- Executable Path ----")
    try:
        print(f" {proc.exe()}")
    except Exception as e:
        print(f" Failed to get executable path: {e}")

def print_open_files(proc):
    print("\n---- Open File Descriptors ----")
    try:
        fd_path = f"/proc/{proc.pid}/fd"
        fds = os.listdir(fd_path)
        print(f" {fds}")
    except Exception as e:
        print(f" Failed to list file descriptors: {e}")

def task4_inspect_process(pid):
    try:
        proc = psutil.Process(pid)

        print_proc_status(proc)
        print_exe_path(proc)
        print_open_files(proc)

    except psutil.NoSuchProcess:
        print("❌ No such process. Use a valid PID.")

if __name__ == "__main__":
    pid = int(input("Enter PID to inspect: "))
    task4_inspect_process(pid)
