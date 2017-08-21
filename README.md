# AlgorithmComplexity

   There is a couple of complexity types and much more of algorithm types, and most of them was already analyzed in complexity way. Of course the best way to learn something theoretical is to make own measurements which allows to get some own thoughts as well.  Main assumption of this project is to create program which is able to measure and make analysis of sorting algorithms.

## Assumptions:

Measured complexities:
-	Time complexity
-	“Transition” complexity

Sorting algorithms to be measured:
-	Bubble sort
-	Quick sort
-	Insertion sort
-	Merge sort
-	Counting sort
-	Heap sort

Sets used in application:
-	Sorted set
-	Random set
-	Backward sorted set
-	Sorted Set with first random value
-	Backward sorted set with last random value


## System requirements:

-	Data set generator – class which is responsible for handling datasets generation. From the optimization point of view it is good to consider working on original or copied containers.

-	Abstract class – to aggregate class connected with specific sort algorithm. Projecting system with the given approach allows to develop scalable and easy to debug application.

-	Export module – by default it’s going to send results to csv file, to make data analysis more comfortable. Of course there is also another option to use specific libraries for data presenting i.e gnuplot etc.

-	Unified class template - which makes adding new sorting algorithm much easier. Mentioned scalability.

-	Basic GUI – interface where user can choose specific datasets, algorithms and complexity type to calculate.   

-	MySQL DB Connection – module that basically allows to put results into DB. This kind of module should contain operations like GET data from Db and SEND data to DB.

-	Memory management – consider how to manage memory while using huge datasets like 100k values and more.

## Basic design rules:

-	UseCamelCase to improve codeReadability

-	Try to keep atomic method functionalities - basically one method for one job

-	Names of methods and fields have to tell as much as possible like: static void sortDatasetBackwards () {}

-	Each class and method or even sometimes field when necessary should contain comment about functionality(documentation) e.g.

<center>/* Responsible for</br>
/ […]</br>
/</br></br>

static void sortDataSetBackwards () {</br>
 // some code</br>
}</br></br></center>

-	Committing single change, avoid committing many functionalities at once. It allows to make easier amendments in the future

-	Try to set design rules that allows to think code was written by one person. It is very difficult but it makes code very readable. (imagine what mess in bigger projects without design rules)

-	Write code with keeping in mind this question: “What if we have to add new functionality?”  - it helps to write better solutions


## Created by:
 - Jan Lepa </br>
 - Piotr Wroblewski </br>
 - Bartlomiej Krzyminski (Supervisor)</br>
