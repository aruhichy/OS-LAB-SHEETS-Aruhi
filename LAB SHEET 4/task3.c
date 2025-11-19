import time

# PIPE simulation (shared memory buffer)
pipe_buffer = []

def parent_process():
    print("Parent: writing to pipe...")
    pipe_buffer.append("Hello from parent")
    print("Parent: waiting for child to finish...\n")
    time.sleep(1)  # simulate wait()

def child_process():
    time.sleep(0.5)  # ensure parent writes first
    if pipe_buffer:
        message = pipe_buffer.pop(0)
        print("Child received:", message)
    else:
        print("Child: No data found in pipe!")

if __name__ == '__main__':
    print("Simulating fork(), exec(), wait(), pipe() using Python functions\n")

    # Simulated fork: parent runs first, then child
    parent_process()
    child_process()

    print("\nSimulation complete.")
