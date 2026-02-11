#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    char *filename;
    char *keyword1;
    char *keyword2;
} DualSearchJob;

// Helper function to print exit status
void print_result(char *keyword, int status) {
    if (WIFEXITED(status)) {
        int code = WEXITSTATUS(status);
        if (code == 0) printf("  [Result] '%s': FOUND\n", keyword);
        else           printf("  [Result] '%s': NOT FOUND\n", keyword);
    }
}

int main() {
    DualSearchJob job;
    char *filename = ""; // TODO: path to rockyou
    char *parent_keyword = "alpaca";
    char *child_keyword = "hello";

    printf("[Parent] Starting parallel search...\n");

    // --- LAUNCH CHILD 1 ---
    pid_t pid1 = ; // TODO: create child1

    if (pid1 == 0) {
        // TODO: exec with grep or mysearch for keyword1
        exit(2); // Error if exec fails
    }

    // --- LAUNCH CHILD 2 ---
    pid_t pid2 = ; // TODO: create child2

    if (pid2 == 0) {
        // TODO: exec with grep or mysearch for keyword2
        exit(2); // Error if exec fails
    }

    // --- PARENT WAITS ---
    int status;
    pid_t finished_pid;

    // Loop exactly twice because we have 2 children
    for (int i = 0; i < 2; i++) {
        
        // Block until ANY child finishes
        finished_pid = wait(&status);

        if (finished_pid == pid1) {
            print_result(keyword1, status);
        } else if (finished_pid == pid2) {
            print_result(keyword2, status);
        }
    }

    return 0;
}
