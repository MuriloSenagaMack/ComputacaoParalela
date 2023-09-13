#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num = 14;

    int numProcesses = 4;  
    int result = 1;
    pid_t pid ; // armazenar os IDs dos processos

    for (int i = 0; i < numProcesses; i++) {
        pid = fork();

        if (pid < 0) { //erro na criação do processo filho
            printf("Fork failed\n");
            exit(1);
        } else if (pid == 0) {  // Processo filho
            int start = (i * num / numProcesses) + 1;
            int end = ((i + 1) * num / numProcesses);

            if (i == numProcesses - 1) {
                end = num;
            }

            int localResult = 1;
            for (int j = start; j <= end; j++) {
                localResult *= j;
            }

            exit(localResult);
        }
    }

    // Processo pai espera todos os processos filhos terminarem
    int status;
    for (int i = 0; i < numProcesses; i++) {
        wait(&status);
        result *= WEXITSTATUS(status);
    }

    printf("The factorial of %d is %d\n", num, result);

    return 0;
}
