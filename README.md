# mutiple thread mergesort

this project implement the task asked in the following question.<br> <br>
A list of integers is divided into two smaller lists of equal size. Two separate threads (which we will term sorting threads) sort each sublist using a sorting algorithm of your choice. The two sublists are then merged by a third thread--a merging thread--which merges the two sublists into a single sorted list. <br> <br>


1. user input the number of item in the array
2. user input the array (arr1 is for the calculation of the separate array, arr2 for the calculation of the 
combination.)
3. set up the parameters to locate the array in the calculation
4. create child thread 1 and 2, use the parameters p1 and p2, and insertion sort the separate array in 
function sort
5. create child thread 3, merge the separate arrays in arr1 into arr2
6. output the sort. 
