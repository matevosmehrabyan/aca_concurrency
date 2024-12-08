#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    printf("Faild to fork!");
    return 1;
  } else if (pid == 0) {
    int ret = execl ("/usr/bin/ls", "ls", NULL);
    if (ret == -1) {
      printf("Failed to load the ls program\n");
    }
  } else {
    printf("Parent process done\n");
    wait(NULL); // NOTE: We may also check exit status
  }

  return 0;
}