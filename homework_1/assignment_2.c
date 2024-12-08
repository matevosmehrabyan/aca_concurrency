#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1 = fork();
  if (pid1 == -1) {
    printf("Failed to create the first child process!");
    return 1;
  
  } else if (pid1 == 0) {
    int ret = execl ("/usr/bin/ls", "ls", NULL);
    if (ret == -1) {
      printf("Failed to load the ls program\n");
    }
  
  } else {
    pid_t pid2 = fork();
    if (pid2 == -1) {
      printf("Failed to create the second child process!");
      return 1;
    } else if (pid2 == 0) {
      int ret = execl ("/usr/bin/date", "date", NULL);
      if (ret == -1) {
        printf("Failed to load the date program\n");
      }
    } else {
      printf("Parent process done\n");
      wait(NULL);  // NOTE: We may also check exit status
    }
    wait(NULL);  // NOTE: We may also check exit status
  }

  return 0;
}