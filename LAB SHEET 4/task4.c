import platform
import getpass

# ------- Part 1: System Details (Shell Script Simulation) -------

print("Kernel Version:")
print(platform.release())  # Simulates: uname -r

print("\nUser:")
print(getpass.getuser())   # Simulates: whoami

print("\nHardware Info (Virtualization):")
print("Virtualization info cannot be fetched in online compilers")  
# Online compilers do not support: lscpu | grep 'Virtualization'


# ------- Part 2: VM Detection in Python -------

def detect_vm():
    try:
        # Online compilers don't have this path, so we simulate safely
        with open("/sys/class/dmi/id/product_name") as f:
            name = f.read().lower()

        vm_keywords = ["virtual", "vmware", "kvm", "qemu", "virtualbox", "hyper-v"]

        for kw in vm_keywords:
            if kw in name:
                return "System is running inside a Virtual Machine"
        return "System is running on Physical Hardware"
        
    except:
        return "VM Detection not supported in online compilers"

print("\nVM Detection:")
print(detect_vm())
