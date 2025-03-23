
// Main function
int main() {
    int ch, n;
    struct priorityqueue node;

    while (1) {
        printf("\n\tADAPTIVE REAL TIME SCHEDULER\n");
        printf("1. Insert Process\t2. Run Scheduler\t3. Monitor System\t4. Check Deadlines\n");
        printf("5. Handle Errors\t6. Display Results\t7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter number of processes: ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++) {
                    printf("Enter PID, Arrival Time, Burst Time, Priority for Process-%d: ", i + 1);
                    scanf("%d %d %d %d", &node.pid, &node.arrtime, &node.burst, &node.priority);
                    node.burst_copy = node.burst;

                    allocate_resources(node.pid);
                    if (node.priority > 100) {
                        q1 = insert(&node, q1);
                    } else if (node.priority > 50) {
                        q2 = insert(&node, q2);
                    } else {
                        q3 = insert(&node, q3);
                    }
                }
                break;

            case 2:
                run_processes();
                break;

            case 3:
                adjust_scheduling_parameters();
                break;

            case 4:
                check_deadlines();
                break;

            case 5:
                handle_errors();
                break;

            case 6:
                display_result(r);
                break;

            case 7:
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
