#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) {
    int ret = execl ("/usr/bin/grep", "grep", "main", "test.txt", NULL);
    if (ret == -1) {
      printf("Failed to load the grep program\n");
    }
  } else {
    printf("Parent process done\n");
  }

  return 0;
}