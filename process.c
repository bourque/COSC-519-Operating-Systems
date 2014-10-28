#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {

pid_t pids[4];
int n = 4;
int i;

for (i = 0; i < n; ++i) {

	// Create child process
	pids[i] = fork();

    // If an error occurred
    if (pids[i] < 0) { 
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    // Spawn child process
    else if (pids[i] == 0) {
        execlp("./hello.out", NULL);
    }
}

// Wait for children to exit.
int status;
pid_t pid;   
while (n > 0) {
    pid = wait(&status);
    printf("Child with PID %ld exited with status %x.\n", (long)pid, status);
    --n;
}
printf("All children processes complete.\n");

    return 0;
}