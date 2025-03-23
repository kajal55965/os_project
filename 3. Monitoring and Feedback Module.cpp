
// Function to monitor system performance and adjust scheduling parameters
void adjust_scheduling_parameters() {
    float utilization = 0.0;
    int total_burst_time = 0, total_clock_time = clock;

    struct result *head = r;
    while (head) {
        total_burst_time += head->burst_result;
        head = head->right;
    }

    if (total_clock_time > 0) {
        utilization = ((float)total_burst_time / total_clock_time) * 100.0;
    }

    printf("\nSystem Performance Monitoring...\n");
    printf("CPU Utilization: %.2f%%\n", utilization);

    // Dynamic feedback adjustment based on CPU utilization
    if (utilization < 50) {
        time_q1 += 1;
        time_q2 += 1;
        printf("Low CPU utilization detected. Increasing time slices.\n");
    } else if (utilization > 80) {
        time_q1 = (time_q1 > 1) ? time_q1 - 1 : 1;
        time_q2 = (time_q2 > 1) ? time_q2 - 1 : 1;
        printf("High CPU utilization detected. Decreasing time slices.\n");
    } else {
        printf("CPU utilization is optimal.\n");
    }
}
