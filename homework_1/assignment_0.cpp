#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>


int main()
{
    std::string indentation = "";

    pid_t pid = fork();
    if (pid == 0) {
      indentation += "-";
    }
    printf("%sA\n", indentation.c_str());

    pid = fork();
    if (pid == 0) {
      indentation += "-";
    }
    printf("%sB\n", indentation.c_str());


    pid = fork();
    if (pid == 0) {
      indentation += "-";
    }
    printf("%sC\n", indentation.c_str());
    return 0;
}