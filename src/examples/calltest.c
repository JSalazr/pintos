#include <stdio.h>
#include <syscall.h>

struct mini_thread{
  pid_t tid;
  int cant_sleep;
  int cant_run;
  int priority;
};

int
main (int argc, char **argv)
{
  struct mini_thread mt[4];
  pid_t idk1, idk2, idk3, idk4;

  idk1 = exec("printtest2");
  idk2 = exec("echo 2");
  idk3 = exec("arraytest2");
  idk4 = exec("echo 17");

  int val;
  mt[0].tid = idk1;
  val = test(&mt[0]);
  mt[1].tid = idk2;
  val = test(&mt[1]);
  mt[2].tid = idk3;
  val = test(&mt[2]);
  mt[3].tid = idk4;
  val = test(&mt[3]);

  while(mt[0].priority != 0 || mt[1].priority != 0 || mt[2].priority != 0 || mt[3].priority != 0){    
    if(mt[0].priority != 0)
      printf("PID %d, Priority %d, Cant Run, %d, Cant Sleep %d\n", mt[0].tid, mt[0].priority, mt[0].cant_run, mt[0].cant_sleep);
    
    if(mt[1].priority != 0)
      printf("PID %d, Priority %d, Cant Run, %d, Cant Sleep %d\n", mt[1].tid, mt[1].priority, mt[1].cant_run, mt[1].cant_sleep);

    if(mt[2].priority != 0)
      printf("PID %d, Priority %d, Cant Run, %d, Cant Sleep %d\n", mt[2].tid, mt[2].priority, mt[2].cant_run, mt[2].cant_sleep);

    if(mt[3].priority != 0)
      printf("PID %d, Priority %d, Cant Run, %d, Cant Sleep %d\n", mt[3].tid, mt[3].priority, mt[3].cant_run, mt[3].cant_sleep);
    
    val = test(&mt[0]);
    val = test(&mt[1]);
    val = test(&mt[2]);
    val = test(&mt[3]);
  }

  return EXIT_SUCCESS;
}
