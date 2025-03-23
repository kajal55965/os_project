#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for priority queue
struct priorityqueue {
    int pid;
    int priority;
    int arrtime;
    int burst;
    int burst_copy;
    struct priorityqueue *left;
    struct priorityqueue *right;
} *q1 = NULL, *q2 = NULL, *q3 = NULL;

// Structure for result queue
struct result {
    int pid_result;
    int arrtime_result;
    int burst_result;
    int clock_result;
    struct result *left;
    struct result *right;
} *r = NULL;

// Insert into priority queue
struct priorityqueue* insert(struct priorityqueue* node, struct priorityqueue* q) {
    struct priorityqueue *newnode = (struct priorityqueue*) malloc(sizeof(struct priorityqueue));
    *newnode = *node; // Copying data
    newnode->left = NULL;
    newnode->right = NULL;

    if (!q) {
        q = newnode;
        q->right = q;
        q->left = q;
    } else {
        struct priorityqueue *last = q;
        while (last->right != q) {
            last = last->right;
        }
        last->right = newnode;
        newnode->left = last;
        newnode->right = q;
        q->left = newnode;
    }
    printf("\nProcess with PID %d inserted successfully!\n", node->pid);
    return q;
}

// Insert into result queue
struct result* insert_result(struct result* node, struct result* q) {
    struct result *newnode = (struct result*) malloc(sizeof(struct result));
    *newnode = *node;
    newnode->left = NULL;
    newnode->right = NULL;

    if (!q) {
        q = newnode;
    } else {
        struct result *last = q;
        while (last->right) {
            last = last->right;
        }
        last->right = newnode;
        newnode->left = last;
    }
    return q;
}

