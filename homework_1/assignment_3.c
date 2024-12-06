#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    int ret = execl ("/usr/bin/echo", "echo", "Hello from the child process", NULL);
    if (ret == -1) {
      printf("Failed to load the echo program\n");
    }
  } else {
    printf("Parent process done\n");
  }

  return 0;
}