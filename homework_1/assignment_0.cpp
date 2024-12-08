#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <queue>


int main()
{
    std::string indentation = "";
    std::queue<pid_t> procToWait;

    // TODO: Make a function that will fork and print
    //       to eliminate code duplication.
    pid_t pid = fork();
    if (pid == -1) {
      printf("Failed to fork! Location 1.");
      return 1;
    } else if (pid == 0) {
      indentation += "-";
    } else {
      procToWait.push(pid);
    }
    printf("%sA\n", indentation.c_str());

    pid = fork();
    if (pid == -1) {
      printf("Failed to fork! Location 2.");
      return 1;
    } else if (pid == 0) {
      indentation += "-";
    } else {
      procToWait.push(pid);
    }
    printf("%sB\n", indentation.c_str());

    pid = fork();
    if (pid == -1) {
      printf("Failed to fork! Location 3.");
      return 1;
    } else if (pid == 0) {
      indentation += "-";
    } else {
      procToWait.push(pid);
    }

    printf("%sC\n", indentation.c_str());

    while (!procToWait.empty()) {
      int status;
      pid_t current = procToWait.front();
      procToWait.pop();
      waitpid(current, &status, 0);
      if (status) {
        printf("Child with pid %d finished with ErrNo %d", current, status);
      }

    }

    return 0;
}