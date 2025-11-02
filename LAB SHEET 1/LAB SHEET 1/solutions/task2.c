//TASK 2
import os
import subprocess

def task2_exec_commands(commands):
    print(f"[Parent] PID: {os.getpid()} - Executing {len(commands)} commands...\n")

    for i, cmd in enumerate(commands):
        print(f"[Child {i+1}] Executing: {' '.join(cmd)}")

        try:
            result = subprocess.run(cmd, capture_output=True, text=True, check=True)
            print(f"[Child {i+1}] Output:\n{result.stdout}")
        except subprocess.CalledProcessError as e:
            print(f"[Child {i+1}] Failed to execute command: {e}")
            print(f"Error Output:\n{e.stderr}")

    print("\n[Parent] All commands executed.")

if __name__ == "__main__":
    commands = [
        ["cmd", "/c", "dir"],         # Windows version of 'ls'
        ["cmd", "/c", "date /T"],     # Windows version of 'date'
        ["cmd", "/c", "tasklist"]     # Windows version of 'ps aux'
    ]

    task2_exec_commands(commands)
