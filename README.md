# OS_Lab3
Use the pthreads and Monte Corlo algorithm to approximate the value of PI

An interesting way of calculating π is to use a technique known as Monte Carlo, which involves randomization.

Part 1
Write a multithreaded program of this algorithm that creates a separate thread to generate a number of random points. 
The thread will count the number of points that occur within the circle and store that result in a global variable. 
When this thread has exited, the parent thread will calculate and output the estimated value of π.

Part 2
Modify your program to create several threads, each of which generates random points and determines if the points 
fall within the circle. Each thread have to update the global count of all points that fall within the circle. 
You have to protect against race conditions on updates to the shared global variable by using mutex locks.
