#ifndef PROJECT_02_STRUCTURES_H
#define PROJECT_02_STRUCTURES_H

/*
 * TIME data structure
 * full_time - "hour" converted into minutes + "minute"
 * time_str - time shown in digital form (HH:MM)
 */
typedef struct {
    int hour, minute, full_time;
    char time_str[6];
} TIME;

/*
 * BUS data structure
 * name - stores the bus' name (to be generated from station details)
 * departure_time - departure time of bus in all forms
 */
typedef struct {
    char *name;
    TIME departure_time;
} BUS;

/*
 * Dynamic queue - depot
 * queue's data is of type BUS
 * first enters into depot, first leaves (FIFO)
 * depot has a capacity
 */
typedef struct queueNode {
    BUS bus_data;
    struct queueNode *next;
} queueNode;

/*
 * Binary Search Tree - platform
 * data of the tree is of type BUS
 * sorting happens based on the departure time of a bus
 * early < late
 * platform has a capacity
 */
typedef struct BST_Node {
    BUS bus_data;
    struct BST_Node *left, *right;
} BST_Node;

/*
 * STATION data structure
 * root - binary search tree
 * first - dynamic queue
 * city - name of the city where the station is
 * name - name of the station itself
 * also stores both the capacity of its platform and depot
 */
typedef struct {
    BST_Node *root;
    queueNode *first, *last;
    char *city, *name, *abbreviation;
    int platform_capacity, depot_capacity;
    int platform_size, depot_size;
} STATION;

#endif //PROJECT_02_STRUCTURES_H
