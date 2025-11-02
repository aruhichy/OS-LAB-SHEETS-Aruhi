# Sub-Task 3: Create & run two processes concurrently
# Objective: Use multiprocessing to run tasks in parallel

import multiprocessing
import logging

if __name__ == '__main__':
    print("System Starting...")

    # Create processes
    p1 = multiprocessing.Process(target=system_process, args=("Process-1",))
    p2 = multiprocessing.Process(target=system_process, args=("Process-2",))

    # Start processes
    p1.start()
    p2.start()

    # Wait for both processes to finish
    p1.join()
    p2.join()

    print("System Execution Completed ✅")
