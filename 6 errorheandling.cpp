
// Error handling and anomaly detection
void handle_errors() {
    printf("\nChecking for scheduling anomalies...\n");
    if (clock > 100) {
        printf("Warning: Clock exceeded limit. Possible scheduling error.\n");
    }

    struct priorityqueue *current = q1 ? q1 : (q2 ? q2 : q3);
    while (current) {
        if (current->burst < 0) {
            printf("Error: Negative burst time detected for PID %d.\n", current->pid);
        }
        if (current->right == current) break;
        current = current->right;
    }
    printf("Error handling completed.\n");
}
