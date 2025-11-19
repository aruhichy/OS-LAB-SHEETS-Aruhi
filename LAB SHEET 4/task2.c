import time
log_data = []

def log(message):
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
    log_data.append(f"{timestamp} - {message}")

def process_task(name):
    log(f"{name} started")
    time.sleep(1)   # simulate work
    log(f"{name} terminated")

if __name__ == '__main__':
    print("System Booting...\n")

    # Simulated "processes"
    process_task("Process-1")
    process_task("Process-2")

    print("System Shutdown.\n")

    print("---- SYSTEM LOG ----")
    for entry in log_data:
        print(entry)
