## AUT Operating System course project

### Phase 1
Add the following system calls to the xv6 operating system:

1. The ```getTicks``` system call allows the user to read the ticks passed by since the OS has started working.

2. The ```getProcInfo``` system call prints the pid and creation time of all the processes currently in the RUNNING state.

The functionality of these parts can be tested using ```getTicksTest``` and ```getProcInfoTest``` commands.

#####  _⤷ The source code of this phase can be found at_ [_this repository_](https://github.com/NegarMov/xv6-Add-System-Call)_._

### Phase 2

Add thread implementation to the xv6 operating system and the 3 following system calls to support it:
  
1. The ```thread_create``` system call allows the user to create a new thread which uses the same address space as its parent.
  
2. The ```thread_id``` system call returns the tid (thread id) of the new thread.
  
3. The ```thread_join``` system call makes the thread's parent wait for it until it finishes its job.

The functionality of these parts can be tested using ```threadTest``` command.
  
#####  _⤷ The source code of this phase can be found at_ [_this repository_](https://github.com/NegarMov/xv6-Thread-Implementation)_._

### Phase 3

Make the xv6 operating system work with the following CPU scheduling algorithms:
  
1. **Round Robin scheduling** with a default time quantum set in ```param.h```.
  
2. **preemptive priority scheduling** with a default time quantum also set in ```param.h```. Each process has a priority ranging from 1 to 6 (with 1 as the highest priority) which can be set using the ```setPriority``` system call.
  
3. **Multilevel Queue scheduling** with a different time quantum for each queue depending on its priority. The priority of the processes can be set using ```setPriority``` system call here as well. The processes of each queue will start running (in a RR manner) only if there is no process in any queue with a higher priority.

4. **Lottery scheduling** which chooses the processes in a random way. The chance of each process being chosen is directly propotional to its number of tickets, which can be set using ```setTickets``` system call.

It's possible to switch between these policies using ```changePolicy``` system call. Zero represents the xv6 default scheduling algorithm and the other algorithms can be set in the order above. The functionality of each of these algorithms can be tested using its corresponding test command (namely ```roundRobinTest```, ```prioritySchedTest```, ```multiLayeredQueuedTest``` and ```lotteryTest```). You can also measure the "CBT", "Turnaround Time" and "Waiting Time" for every process created during the test.

#####  _⤷ The source code of this phase can be found at_ [_this repository_](https://github.com/NegarMov/xv6-CPU-scheduling)_._

---

### Booting the Operating System
Use the following commands to build and boot the xv6 operating system:

```plaintext
make clean
make
make qemu
```
