# Sub-Task 4: Ensure proper termination and verify logs
# Objective: Wait for processes to complete and confirm shutdown

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

    # Wait for processes to complete
    p1.join()
    p2.join()

    print("✅ All processes finished successfully.")
    print("⚙️  System Shutdown.")

    # Display logs from file
    print("\n📄 LOG OUTPUT:")
    with open("process_log.txt", "r") as f:
        print(f.read())
