def fcfs(processes):
    processes.sort(key=lambda x: x[1])  # sort by arrival time
    wt, tat = [], []
    current = 0
    for p in processes:
        if current < p[1]:
            current = p[1]
        wt.append(current - p[1])
        current += p[2]
        tat.append(current - p[1])

    print("\n--- FCFS Scheduling ---")
    print("PID\tAT\tBT\tWT\tTAT")
    for i, p in enumerate(processes):
        print(f"{p[0]}\t{p[1]}\t{p[2]}\t{wt[i]}\t{tat[i]}")
def sjf(processes):
    n = len(processes)
    completed, current = 0, 0
    visited = [False]*n
    wt, tat = [0]*n, [0]*n
    print("\n--- SJF Scheduling ---")
    while completed < n:
        idx = -1
        min_bt = 9999
        for i in range(n):
            if processes[i][1] <= current and not visited[i] and processes[i][2] < min_bt:
                min_bt = processes[i][2]
                idx = i
        if idx == -1:
            current += 1
            continue

        visited[idx] = True
        start = current
        current += processes[idx][2]
        wt[idx] = start - processes[idx][1]
        tat[idx] = current - processes[idx][1]
        completed += 1

    print("PID\tAT\tBT\tWT\tTAT")
    for i, p in enumerate(processes):
        print(f"{p[0]}\t{p[1]}\t{p[2]}\t{wt[i]}\t{tat[i]}")

def priority_scheduling(processes):
    processes.sort(key=lambda x: (x[3], x[1]))  # sort by priority then arrival
    wt, tat = [], []
    current = 0

    print("\n--- Priority Scheduling ---")
    for p in processes:
        if current < p[1]:
            current = p[1]
        wt.append(current - p[1])
        current += p[2]
        tat.append(current - p[1])
    print("PID\tAT\tBT\tPR\tWT\tTAT")
    for i, p in enumerate(processes):
        print(f"{p[0]}\t{p[1]}\t{p[2]}\t{p[3]}\t{wt[i]}\t{tat[i]}")

def round_robin(processes, quantum):
    n = len(processes)
    rem_bt = [p[2] for p in processes]
    t = 0
    wt, tat = [0]*n, [0]*n
    print("\n--- Round Robin Scheduling ---")
    while True:
        done = True
        for i in range(n):
            if rem_bt[i] > 0:
                done = False
                if rem_bt[i] > quantum:
                    t += quantum
                    rem_bt[i] -= quantum
                else:
                    t += rem_bt[i]
                    wt[i] = t - processes[i][2]
                    rem_bt[i] = 0
        if done:
            break
    for i in range(n):
        tat[i] = wt[i] + processes[i][2]
    print("PID\tAT\tBT\tWT\tTAT")
    for i, p in enumerate(processes):
        print(f"{p[0]}\t{p[1]}\t{p[2]}\t{wt[i]}\t{tat[i]}")
print("CPU Scheduling Algorithms")
print("1. FCFS\n2. SJF\n3. Priority\n4. Round Robin")
choice = int(input("Enter your choice: "))

n = int(input("Enter number of processes: "))
processes = []

if choice == 3:
    print("Enter PID, Arrival Time, Burst Time, Priority:")
    for _ in range(n):
        p = input().split()
        processes.append([p[0], int(p[1]), int(p[2]), int(p[3])])
else:
    print("Enter PID, Arrival Time, Burst Time:")
    for _ in range(n):
        p = input().split()
        processes.append([p[0], int(p[1]), int(p[2])])

if choice == 1:
    fcfs(processes)
elif choice == 2:
    sjf(processes)
elif choice == 3:
    priority_scheduling(processes)
elif choice == 4:
    quantum = int(input("Enter time quantum: "))
    round_robin(processes, quantum)
else:
    print("Invalid Option!")
