
// Check for deadline violations
void check_deadlines() {
    struct priorityqueue *current;
    int missed_deadlines = 0;

    printf("\nChecking Deadlines...\n");

    if (q1) current = q1;
    else if (q2) current = q2;
    else current = q3;

    while (current) {
        if (current->arrtime + current->burst_copy < clock) {
            printf("Deadline missed by process %d.\n", current->pid);
            missed_deadlines++;
        }
        if (current->right == current) break;
        current = current->right;
    }

    if (missed_deadlines == 0) {
        printf("All processes met their deadlines.\n");
    }
}
