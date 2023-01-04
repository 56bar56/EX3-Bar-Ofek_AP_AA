# EX3-Bar-Ofek_AP_AA
EX3 AP_AA
exercise 3 of our project - Bar and Ofek
server - client

Let's start by explaining our solution: we use the project of exercise 2
in general we created 2 "programs" one for our server and one for our client. 
we connected them with socket and then starts the connection, the client gets from the user
k vector and distance kind, them the client sends the information to the server
who takes the information and start running the main from the last exercise to get the kind of 
the flower by our vector, k and distance kind. 
now the server sends again to the client the kind of the flower and waits for the next request
of the client, if the client wants to close the connection he will send to the server "-1"
and then the server will know that the client wants to close the connection and will close the socket.
in this case the server will wait fo the next client (the server won't be close in any case).
if the client get from the user invalid arguments then the server will send to the client
kinds of massages that the client will know that the arguments are invalid.
like "invalid input" and so on.

Some other explanations and optimizations : here all the optimizations we have done
is also the optimizations from the last exercise we will add the solution and the optimizations here.
now we created the server to use the code from the other exercise, one big optimization we have done
is to change the file reading, in the beginning we read the file lots of times, every time the client
sends a request the server will read again and again the file, we changed it to read one time for all
the connections between the server and all the clients who will connect him. one time and that's it.

Some other explanations and optimizations from last exercise:
we get all the vectors from the given file and start reading the vectors from them, and we calculate
the distances and create a new object who will hold the vector,kind,distance. at the beginning we thought to use
maximum heap in order to throw the biggest number every time, but we choose more effective way. then we use 'Select'
to optimize our run time code, then we do it on the given number 'k' and get all the first k into a new
array. now 'Select' is an algorithm who find the object in index k and behind all the one's who lower
and after the index k all the one's who bigger then him so we know in O(1) who the ones we need and take
them in O(k). until now we are in O(n) when n is the size of the vectors from the file.
now we use algorithm who alphabetically sort the array by the names of the flowers we need to check and
then we just go throw the array with counter and check who is the flower that found the most in the
array and return the flower, for the alphabetically sort we use mergeSort that takes O(klog(K)) and
go throw the array and found the one who there the most is O(k) - in general our run time is O(klog(k)+n).


Describe the libraries we worked with : all the server client libraries that we will explain here and the libraries from the last exercize.
server-client libraries :  #include <sys/socket.h> - this include will help us create the connection
and connect between the client and the server.

libraries from last exercise : #include - we use fstream to get the information from the file.
#include - we use iostream library to print or get some input in the project.
#include - It is used to set decimal precision.
#include - we use vector library instead of creating a new vector class.
#include <math.h> - we use this library in many function like abs to get the positive value of a variable.
#include - we use this library in order to use string.

with the make file we created for the exercise. to run the server after using make you will need
to write - server.out to run the client after using make you will need to write - client.out 