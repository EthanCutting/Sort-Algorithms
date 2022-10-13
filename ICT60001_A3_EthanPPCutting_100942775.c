/*

Swin University of Technology faculty of Science, Engineering and Techology
Operating Systems Management - ICT6001 - Assignment 3

Ethan PP Cutting 
Student ID: 100942775

Created: Monday, October 2, 2022 7:27:52 PM
Modified: Friday, October 7, 2022, 9:53:33 PM
Accessed: Today, October 7, 2022, 5 mintues ago

*/ 
 
#include <stdio.h> 
#include <windows.h> 
#include <time.h> 
#include <math.h>
 
#define ARRAYSIZE 10000 
/* don't use SIZE - it has already been defined in one of the header files*/ 
// adding the voids for all of the algorithms 
void heapSort(int arr[], int size);
void bubblesort(int array[], const int n); 
void selectionsort(int array[], const int n); 
void quickSort(int arr[], int low, int high); 
void insertionSort(int aro[], int n);
int partition (int arr[], int low, int high); 
void swap(int* a, int* b); 
void swapLong(long* a, long* b); 
void printArray(const int array[], const int n); 
void percolatDown(int data[], const int size, int index);
// add long functions for heap sor heap based 
long heapSortHeapBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    heapSort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for heap sort stack based
long heapSortStackBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    heapSort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for insertion
long insertionSortHeapBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    insertionSort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for selection
long SelectionSortHeapBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    selectionsort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for bubble
long bubbleSortHeapBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    bubblesort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for quick
long QuickSortHeapBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    quickSort(arr, 0, ARRAYSIZE - 1);
    stop = clock();
    return stop - start;
}
// add long functions for insert
long insertionSortStackBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    insertionSort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for select
long SelectionSortStackBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    selectionsort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for bubbles
long bubbleSortStackBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    bubblesort(arr, ARRAYSIZE);
    stop = clock();
    return stop - start;
}
// add long functions for quick
long QuickSortStackBased(int arr[])
{
    long elapsed;
    volatile clock_t start, stop;
    int i;
    for (i = 0; i < ARRAYSIZE; i++)
    {
        arr[i] = rand();
    }
    start = clock();
    quickSort(arr,0, ARRAYSIZE-1);
    stop = clock();
    return stop - start;
}
// adding a int to get largest sequence number
int largestSequenceNumber(int size)
{
    int h = 0;
    while (3 * h + 1 < size)
        h = 3 * h + 1;
    return h;
}
// adding void for insertion for shell sort
void insertionSortForShellSort(long* arr, int size, int gap, int start)
{
    for (int i = start; i < size; i += gap)
    {
        int j = i; 
        while (j > start && arr[j] < arr[j - gap])
        {
           
            swap(&arr[j], &arr[j - gap]);
            j -= gap;
        }
    }

}
// adding shell sort
void Shellsort(long* array, int size)
{
    
    int gap = largestSequenceNumber(size);
    while (gap != 0)
    {
        for (int a = 0; a < size; a++)
            insertionSortForShellSort(array, size, gap, a);
        gap = gap / 3;
    }
}

//selection sort algorithum
void selectionSortForTimSort(int* arr, int start, int end)
{
    //varible which hold index of small element
    int smal;
    for (int a = start; a < end; a++)
    {
        smal = a;
        //nested loop
        for (int b = a + 1; b < end; b++)
        {
            if (arr[smal] > arr[b])
                smal = b;
        }
        //swap cureent with samll element
        swap(&arr[smal], &arr[a]);
    }

}
// time sort function 
void timSort(int* A, int low, int high)
{
    while (low < high)
    {
        // switch to selection sort if the size is 10 or smaller
        if (high - low < 10)
        {
            selectionSortForTimSort(A, low, high );
            break;
        }
        else {
            int pivot = partition(A, low, high);

            // tail call optimizations � recur on the smaller subarray
            if (pivot - low < high - pivot)
            {
                timSort(A, low, pivot - 1);
                low = pivot + 1;
            }
            else {
                timSort(A, pivot + 1, high);
                high = pivot - 1;
            }
        }
    }
}
// adding sort time function
void sortByTime(long arr[],char*Arg[])
{
    int c, d, position, swap;
    for (c = 0; c < (14 - 1); c++)
    {
        position = c;

        for (d = c + 1; d < 14; d++)
        {
            if (arr[position] > arr[d])
                position = d;
        }
        if (position!= c)
        {
            swapLong(&arr[c], &arr[position]);
            char* temp = Arg[c];
            Arg[c] = Arg[position];
            Arg[position] = temp;
        }
    }
 }
 // adding main function 
int main() 
 { 
    long elapsed;
    volatile clock_t start, stop;
    int i;
  
    long reportOfTime[14]; int t = 0;
    char* argv[] = { "SelectionSortStackBased","BubbleSortStackBased","InsertionSortStackBased","QuickSortStackBased","HeapsortStackBase","ShellSortStackBased","TimSortStackBased" ,
    
    "SelectionSortHeapBased","BubbleSortHeapBased","InsertionSortHeapBased","QuickSortHeapBased","HeapsortHeapBase","ShellSortHeapBased","TimSortHeapBased" };
      srand(time(0)); 
      /*Sort on the stack - bigger arrays allowed. Declare a fixed-size array*/ 
      int number[ARRAYSIZE]; 
   
      /*decalare on the heap*/ 
      int * pNumber =  (int*) malloc (sizeof(int)*ARRAYSIZE); 
      if (pNumber == 0) //malloc failed 
      { 
        printf("Error allocating array on heap\n"); 
        return -1; 
      } 
   
      printf("*******************Sorting experiments using stack********************\n");
      /*time the selectionsort version*/ 
     
     reportOfTime[t++]= elapsed = SelectionSortStackBased(number); 
      printf("Selection sort on the stack time elapsed: %ld ms\n", elapsed); 
      /*time the bubblesort version*/ 
      reportOfTime[t++]=elapsed = bubbleSortStackBased(number); 
      printf("Bubble sort on the stack time elapsed: %ld ms\n", elapsed); 
      /*time the insertion sort version*/
      reportOfTime[t++]=elapsed = insertionSortStackBased(number);
      printf("insertion sort on the stack time elapsed: %ld ms\n", elapsed);
      /*time the quicksort version*/ 
      reportOfTime[t++] = elapsed = QuickSortStackBased(number);
      printf("Quicksort on the stack time elapsed: %ld ms\n", elapsed); 
      /*time the heap sort version*/
      reportOfTime[t++] = elapsed = heapSortStackBased(number);
      printf("heap sort on the stack time elapsed: %ld ms\n", elapsed);

      for (i = 0; i < ARRAYSIZE; i++)
      {
          number[i] = rand();
      }
      start = clock();
      Shellsort(number, ARRAYSIZE);
      stop = clock();
      reportOfTime[t++] = elapsed = stop - start;
      printf("shell sort on the stack time elapsed: %ld ms\n", elapsed);


      for (i = 0; i < ARRAYSIZE; i++)
      {
          number[i] = rand();
      }
      start = clock();
      timSort(number, 0,ARRAYSIZE-2);
      stop = clock();
      reportOfTime[t++] = elapsed = stop - start;
      printf("timSort sort on the stack time elapsed: %ld ms\n", elapsed);
      printf("\n\n\n\*******************Sorting experiment using heap********************\n");

      /*time the selectionsort heap version*/ 
      reportOfTime[t++] = elapsed =SelectionSortHeapBased(pNumber);
      printf("Selection sort on the heap time elapsed: %ld ms\n", elapsed); 
   
    /*time the bubblesort heap version*/ 
     
      reportOfTime[t++] = elapsed = bubbleSortHeapBased(pNumber);
      printf("Bubble sort on the heap time elapsed: %ld ms\n", elapsed); 

      /*time the insertion sort version*/  
      reportOfTime[t++] = elapsed=insertionSortHeapBased(pNumber);
      printf("insertion sort on the heap time elapsed: %ld ms\n", elapsed);

 
      /*time the quicksort heap version*/ 
    
      reportOfTime[t++] = elapsed =QuickSortHeapBased(pNumber);
      printf("Quicksort on the heap time elapsed: %ld ms\n", elapsed); 

      /*time the heap sort version*/
   
    reportOfTime[t++]=  elapsed = heapSortHeapBased(pNumber);
      printf("heap sort on the heap time elapsed: %ld ms\n", elapsed);
      for (i = 0; i < ARRAYSIZE; i++)
      {
          number[i] = rand();
      }
      start = clock();
      Shellsort(number, ARRAYSIZE);
      stop = clock();
     reportOfTime[t++]= elapsed = stop - start;
      printf("shell sort on the heap time elapsed: %ld ms\n", elapsed);


      for (i = 0; i < ARRAYSIZE; i++)
      {
          pNumber[i] = rand();
      }
      start = clock();
      timSort(pNumber, 0,ARRAYSIZE-1);
      stop = clock();
      reportOfTime[t++] = elapsed = stop - start;
      printf("timSort sort on the heap time elapsed: %ld ms\n", elapsed);
  
      //    printArray(pNumber, ARRAYSIZE);

      free(pNumber);
      printf("\n\n\n\n****************Summarized Test Report Sorted By Time*****************\n");
      sortByTime(reportOfTime,argv);
      for (int a = 0; a < 14; a++)
      {
          printf("%s: ", argv[a]);
          printf("%dms\n", reportOfTime[a]);
     }
  return 0; 
} 
/*Selection sort 
*https://www.programmingsimplified.com/c/source-code/c-program-selection-sort 
* @param array - integer array (input, output) 
* @param n - number of elements to be sorted 
* pre - array must contain n integers 
* post - array will be sorted 
*/ 
void selectionsort(int array[], const int n) 
{ 
  int c, d, position, swap; 
  for (c = 0; c < (n - 1); c++)
  {
      position = c;

      for (d = c + 1; d < n; d++)
      {
          if (array[position] > array[d])
              position = d;
      }
      if (position != c)
      {
          swap = array[c];
          array[c] = array[position];
          array[position] = swap;
      }
  }

} 

  // A utility function to swap two elements  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void swapLong(long* a, long* b)
{
    long t = *a;
    *a = *b;
    *b = t;
}



//this function will convert into build heap 
//convert array into heap
void percolatDown(int data[], const int size, int index)
{
    //max Heap
    int i = index;
    int n = 2 * i + 1;  

    //loop run and going down and down and check heap property is nt violated
    while (n + 1 < size && (data[i] < data[n] || data[i] < data[n + 1]))
    {
        if (data[n] > data[n + 1])
        {
            swap(&data[i], &data[n]);
            i = n;
        }
        else
        {
            swap(&data[i], &data[n + 1]);
            i = n + 1;
        }
        n = 2 * i + 1;
    }
    //last index
    if (n < size && data[i] < data[n])
        swap(&data[i], &data[n]);
}
void heapSort(int arr[], const int size)
{

    //will convert array into heap
    for (int a = size / 2; a >= 0; a--)
        percolatDown(arr, size, a);


    //now sort the array and reduce size of heap
    for (int a = 0; a < size; a++)
    {
        swap(&arr[0], &arr[size - a - 1]);   //swap first element of heap wih last element of heap
        percolatDown(arr, size - 1 - a, 0);
    }
}
void insertionSort (int aro[], int n)
{ 
    int i, unlock, j;
  for (i = 1; i < n; i++)
  {
    unlock = aro[i];
    j = i - 1;
    while (j >= 0 &&aro[j] > unlock)
    {
      aro[j + 1] = aro[j];
      j = j -1;
    }
    aro[j + 1] = unlock;
  }
}
void outputthearray(int aro[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  printf("%d ", aro[i]);
  printf("\n");
}



/*sorts an int array lowest first 
* @param array - integer array (input, output) 
* @param n - number of elements to be sorted 
* pre - array must contain n integers 
* post - array will be sorted 
*/ 
void bubblesort(int array[], const int n) 
{ 
   
    int sorted;
    int i = 0;
    int temp;
    do
    {
        sorted = 1;
        for (i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                /*swap*/
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0;
            }
        }
    } 
    while (sorted == 0);
        return;

    
} 
/* display an integer array 
* @param array - the array to be printed 
* @param n - number of elements to be printed 
* @returns nothing 
* pre - array must contain n integers 
* post - no change 
*/ 
void printArray(const int array[], const int n) 
{ 
  int i; 
  for (i = 0 ; i < n ; i++) 
  { 
    printf("%i\n", array[i]); 
  } 
  printf("\n"); 
} 
 
 
 
   
/* This function takes last element as pivot, places  
   the pivot element at its correct position in sorted  
    array, and places all smaller (smaller than pivot)  
   to left of pivot and all greater elements to right  
   of pivot 
   *  
   *  https://www.geeksforgeeks.org/quick-sort/ 
   * 
    */ 
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];    // pivot  
    int i = (low - 1);  // Index of smaller element  
   
    for (int j = low; j <= high- 1; j++)  
    {  
        // If current element is smaller than or  
        // equal to pivot  
        if (arr[j] <= pivot)  
        {  
            i++;    // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
   
/* The main function that implements QuickSort 
 arr[] --> array to be sorted,  
  low  --> Starting index,  
  high  --> Ending index  
*  https://www.geeksforgeeks.org/quick-sort/ 
*/ 
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
           at right place */ 
        int pi = partition(arr, low, high);  
   
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  