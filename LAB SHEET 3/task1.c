# Priority Scheduling
processes = []
n = int(input("Enter number of processes: "))
for i in range(n):
    bt = int(input(f"Enter Burst Time for P{i+1}: "))
    pr = int(input(f"Enter Priority (lower number = higher priority) for P{i+1}: "))
    processes.append((i+1, bt, pr))
processes.sort(key=lambda x: x[2])
wt = 0
total_wt = 0
total_tt = 0
print("\nPriority Scheduling:")
print("PID\tBT\tPriority\tWT\tTAT")
for pid, bt, pr in processes:
    tat = wt + bt
    print(f"{pid}\t{bt}\t{pr}\t\t{wt}\t{tat}")
    total_wt += wt
    total_tt += tat
    wt += bt
print(f"Average Waiting Time: {total_wt / n}")
print(f"Average Turnaround Time: {total_tt / n}")

# ROUND ROBIN SCHEDULING
CODE-
print("\n----- ROUND ROBIN SCHEDULING -----")
n2 = int(input("Enter number of processes: "))
burst = []
for i in range(n2):
    bt = int(input("Enter Burst Time for P" + str(i+1) + ": "))
    burst.append(bt)
quantum = int(input("Enter Time Quantum: "))
rem = burst[:]       # remaining times
wt = [0] * n2        # waiting times
tat = [0] * n2       # turnaround times
t = 0                # current time

while True:
    done = True
    for i in range(n2):
        if rem[i] > 0:
            done = False
            if rem[i] > quantum:
                t += quantum
                rem[i] -= quantum
            else:
                t += rem[i]
                wt[i] = t - burst[i]
                rem[i] = 0

    if done:
        break

for i in range(n2):
    tat[i] = burst[i] + wt[i]

print("\nPID\tBT\tWT\tTAT")

for i in range(n2):
    print("P" + str(i+1) + "\t" + str(burst[i]) + "\t" + str(wt[i]) + "\t" + str(tat[i]))

print("\nAverage Waiting Time:", sum(wt)/n2)
print("Average Turnaround Time:", sum(tat)/n2)
