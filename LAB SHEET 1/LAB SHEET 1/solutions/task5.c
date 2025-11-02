// task 5
import multiprocessing
import os
import time
import psutil

def cpu_intensive_task(nice_val, duration=5):
    p = psutil.Process(os.getpid())
    try:
        p.nice(nice_val)  # Set process priority
    except Exception as e:
        print(f"[PID {p.pid}] Failed to set nice({nice_val}): {e}")

    print(f"[PID {p.pid}] started with nice {p.nice()}")
    end_time = time.time() + duration
    count = 0

    while time.time() < end_time:
        count += 1

    print(f"[PID {p.pid}] finished after counting {count}")
    return count

def main():
    nice_values = [0, 5, 10, 15, 19]  # Different priorities
    duration = 5
    processes = []

    print(f"[Parent PID {os.getpid()}] Spawning processes...\n")

    for nv in nice_values:
        p = multiprocessing.Process(target=cpu_intensive_task, args=(nv, duration))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()

    print("\nAll processes have finished.")

if __name__ == "__main__":
    main()
