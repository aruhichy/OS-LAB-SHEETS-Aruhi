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
