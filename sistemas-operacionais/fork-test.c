#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {

  printf("--begginning of program\n");
  int counter = 0;
  pid_t pid = fork();
  printf("asdf\n");
  pid_t pid2 = fork();

  if (pid == 0) {
    int i = 0;
    for (; i < 100; ++i) {
      printf("child process: counter=%d pid=%d\n", ++counter, getpid());
      sleep(1);
    }
  }

  else if (pid > 0) {
    int j = 0;
    for (; j < 100; ++j) {
      printf("parent process: counter=%d pid=%d\n", ++counter, getpid());
      sleep(1);
    } 
  }
  
  else {
    printf("fork() failed!\n");
    return 1;
  }

  printf("--end of program--\n");
  return 0;
}