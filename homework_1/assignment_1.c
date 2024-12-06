#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    int ret = execl ("/usr/bin/ls", "ls", NULL);
    if (ret == -1) {
      printf("Failed to load the ls program\n");
    }
  } else {
    printf("Parent process done\n");
  }

  return 0;
}