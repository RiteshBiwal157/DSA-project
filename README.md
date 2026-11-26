
# Call Center Customer Management System

A menu-driven, console-based Call Center Customer Management System developed in C using a Circular Queue. The program manages customer calls in First-In, First-Out (FIFO) order.

## Features

- Add a new customer call (Enqueue).
- Serve the next customer (Dequeue).
- Display all waiting customers.
- Search customers using Customer ID.
- Display total waiting calls.
- Check whether the queue is empty or full.
- Display available queue spaces.
- Reuse array positions using Circular Queue.

## Technologies Used

- Programming Language: C
- Interface: Console Based
- Data Structure: Circular Queue
- Concepts: Structures, Functions, Arrays, Searching and Loops.

## Customer Information

Each customer record contains:

- Customer ID
- Customer Name
- Phone Number
- Customer Issue

## Getting Started

### Requirements

- GCC Compiler
- Visual Studio Code (Optional)

### Compilation

Open the terminal in your project folder and execute:

```bash
gcc call_center.c -o call_center
```

### Run on Windows

```bash
.\call_center.exe
```

### Run on Linux / macOS

```bash
./call_center
```

## Main Menu

The program provides the following options:

1. Add Customer Call
2. Serve Customer Call
3. Display Waiting Customers
4. Search Customer
5. Queue Status
6. Exit

## Data Structure Used

### Circular Queue

A Circular Queue is a linear data structure that follows FIFO (First-In, First-Out).

In this project:

- Enqueue: Adds a new customer at the rear.
- Dequeue: Serves and removes the customer from the front.
- Front: Points to the first waiting customer.
- Rear: Points to the last added customer.
- Circular Movement: Uses the modulo (%) operator to reuse available array positions.

## Time Complexity

| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Display | O(n) |
| Search | O(n) |
| Queue Status | O(1) |

## Project Structure

Call-Center-Customer-Management-System/

    ├── call_center.c
    └── README.md

## Limitations

- The queue has a fixed capacity of 5 customers.
- Customer records are stored temporarily in memory.
- Data is not permanently saved after program termination.
- Search works only for customers currently waiting in the queue.

## Learning Outcomes

This project helps understand:

- Implementation of Circular Queue.
- FIFO operations.
- Enqueue and Dequeue operations.
- Structures in C.
- Functions and modular programming.
- Searching techniques.
- Basic problem-solving using DSA.

## Project Information

Project Name: Call Center Customer Management System

Project Type: Data Structures and Algorithms

Programming Language: C

Project Level: Intermediate

Application Type: Console-Based Application
