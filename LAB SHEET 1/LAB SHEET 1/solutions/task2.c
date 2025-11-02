//TASK 2
import os
import subprocess

def task2_exec_commands(commands):
    print(f"[Parent] PID: {os.getpid()} - Executing {len(commands)} commands...\n")

    for i, cmd in enumerate(commands):
        print(f"[Child {i+1}] Executing: {cmd}")

        try:
            result = subprocess.run(cmd, capture_output=True, text=True, shell=True)
            print(f"[Child {i+1}] Output:\n{result.stdout}")
        except Exception as e:
            print(f"[Child {i+1}] Failed to execute: {cmd}")
            print(f"Error: {e}")

    print("\n[Parent] All commands executed.")

if __name__ == "__main__":
    commands = [
        "ls -l",     # List directory
        "date",      # Show date
        "ps -aux",   # Show processes
    ]
