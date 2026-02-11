#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// 1. Struct
typedef struct {
    char *keyword;
    char *filename;
} SearchJob;

int main() {
    // 2. Setup the job
    SearchJob job;
    job.keyword = ""; // TODO: keyword to search for
    job.filename = ""; // TODO: path to rockyou

    printf("[Parent] Dispatching search for '%s'...\n", job.keyword);

    pid_t pid = // TODO: make a child process

    if (pid < 0) {
        perror("Child process creation failed");
        return 1;
    }

    if (pid == 0) {
        // --- CHILD PROCESS ---
        // The child inherits the 'job' struct copy
        
        // TODO: exec grep or your own mysearch (which requires redirection)
        
        // Only runs if exec failed!
        printf("Exec failed");
        exit(2);
    } 
    else {
        // --- PARENT PROCESS ---
        int status;
        
        // TODO: Wait for child, but save the status of the child to status

        if (WIFEXITED(status)) {  // gets the actual important bits for checking status
            // Get the actual integer exit code (0, 1, or 2)
            int exit_code = WEXITSTATUS(status);

            if (exit_code == 0) {
                printf("\n[Parent] Success: The keyword was FOUND.\n");
            } else if (exit_code == 1) {
                printf("\n[Parent] Failure: The keyword was NOT found.\n");
            } else {
                printf("\n[Parent] Error: grep encountered a problem.\n");
            }
        }
    }

    return 0;
}

