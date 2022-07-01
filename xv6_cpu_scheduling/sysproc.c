#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_setPriority(void)
{
  int priority, pid;
  argint(0, &priority);
  argint(1, &pid);
  return setPriority(priority, pid);
}


int
sys_changePolicy(void)
{
  int policyId;
  argint(0, &policyId);
  return changePolicy(policyId);
}

uint
sys_getProcStatus(void)
{
  int pid;
  int type;
  argint(0, &pid);
  argint(1, &type);
  return getProcStatus(pid, type);
}

int
sys_waitWithStatus(void)
{
  int *ctime;
  int *ttime;
  int *rntime;
  int *rdtime;
  argptr(0, (char**) &ctime, sizeof(int));
  argptr(1, (char**) &ttime, sizeof(int));
  argptr(2, (char**) &rntime, sizeof(int));
  argptr(3, (char**) &rdtime, sizeof(int));
  return waitWithStatus(ctime, ttime, rntime, rdtime);
}