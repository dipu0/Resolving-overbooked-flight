CSE207 – Data Structures
Project 15: Resolving overbooked flight


 Project Description: 

An airline company uses the formula shown below to determine the priority of passengers on the waiting list for overbooked flights. Priority number = A / 1000 + B – C where,

A is the customer’s total mileage in the past year
B is the number of years in his or her frequent flier program
C is a sequence number representing the customer’s arrival position when he or she booked the flight. 
Given a file of overbooked customers as shown in below Table, write a program that reads the file and determines each customer’s priority number. You have to build an application for the airline company that builds a priority queue using the priority number and prints a list of waiting customers in priority sequence.

 
For constructing the application you have to do the following: 
Bryan Devaux    53000 5 1
Amanda Trapp    89000 3 2
Baclan Nguyen   93000 3 3
Sarah Gilley    17000 1 4
Warren Rexroad  72000 7 5
Jorge Gonzales  65000 2 6
Paula Hung      34000 3 7
Lou Mason       21000 6 8
Steve Chu       42000 4 9
Dave Lightfoot  63000 3 10
Joanne Brown    33000 2 11

a.	Build a priority queue( binary heap) based on the priority number
b.	Build a stack to store information of customer who will get flight ticket later
In the project you have to do the following: 

1.  Builds a priority queue using the priority number 
2.  Prints a list of waiting customers in priority sequence.
3.  Print details of customer who took flight ticket later



