
// Time quantum for various queues
int time_q1 = 3;
int time_q2 = 2;
int time_q3 = 1;

// Global clock
int clock = 0;

// Run simulation with adaptive feedback-based scheduling
void run_processes() {
    struct priorityqueue *current;
    int time_slice;

    printf("\nStarting Adaptive Scheduling...\n");
    while (q1 || q2 || q3) {
        if (q1) {
            current = q1;
            time_slice = time_q1;  // Highest priority time slice
        } else if (q2) {
            current = q2;
            time_slice = time_q2;  // Medium priority time slice
        } else {
            current = q3;
            time_slice = time_q3;  // Lowest priority time slice
        }

        if (current->arrtime <= clock) {
            int execute_time = (current->burst < time_slice) ? current->burst : time_slice;
            clock += execute_time;
            current->burst -= execute_time;

            if (current->burst == 0) {
                struct result res = {current->pid, current->arrtime, current->burst_copy, clock};
                r = insert_result(&res, r);
                printf("Process %d completed at time %d\n", current->pid, clock);

                if (current == q1) q1 = (q1->right == q1) ? NULL : q1->right;
                else if (current == q2) q2 = (q2->right == q2) ? NULL : q2->right;
                else q3 = (q3->right == q3) ? NULL : q3->right;

                free(current);
            } else {
                current = current->right;
            }
        } else {
            clock++;
        }
    }
    printf("\nScheduling and Execution Completed.\n");
}
