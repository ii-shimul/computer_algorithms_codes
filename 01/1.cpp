#include <bits/stdc++.h> // include all header files
using namespace std;

// function merging two sorted arrays into one array
void merging(int arr[], int low, int mid, int high) {
  int m = mid - low + 1; // calculate the size of first array
  int n = high - mid; // calculate the size of second array
  int A[m], B[n]; // initialize array A and B two divide arr array into two array
  for (int i = 0; i < m; i++) A[i] = arr[low + i]; // copy first m elements to A
  for (int j = 0; j < n; j++) B[j] = arr[mid + 1 + j]; // copy first n elements to B

  int i = 0, j = 0, k = low; // intialize i and j with value 0, and k with low value so that we can keep track of the arr array's current index
  while (i < m && j < n) { // run a while loop until one array is empty
    if (A[i] > B[j]) { // if A[i] is greater than B[j]
      arr[k] = B[j]; // insert B[j] into arr[k]
      j++; // increment j by one so that we can move to the next element
      k++; // increment k by one so that we can insert into the next index
    }
    else { // else A[i] is less than B[j]
      arr[k] = A[i]; // insert A[i] into arr[k]
      i++; // increment i by one so that we can move to the next element
      k++; // increment k by one so that we can insert into the next index
    }
  }
  for (; i < m; i++) { // copy rest of the A array to arr
    arr[k] = A[i];
    k++;
  }
  for (; j < n; j++) { // copy rest of the B array to arr
    arr[k] = B[j];
    k++;
  }
}

// mergeSort function
void mergeSort(int low, int high, int arr[]) {
  if (low < high) { // if low is less then high, it means there are more than 1 element
    int mid = low + (high - low) / 2; // calculate the mid
    mergeSort(low, mid, arr); // call mergeSort from low to mid
    mergeSort(mid + 1, high, arr); // call mergeSort from mid + 1 to high one more time
    merging(arr, low, mid, high); // now merge the two results
  }
}

// function to sort an array using insertion sort
void insertionSort(int n, int arr[]) {
  for (int i = 0; i < n; i++) { // run a loop through the entire array
    int x = arr[i]; // store the current element to be inserted
    int j = i - 1; // initialize j as the index before i to compare with previous elements
    while (j >= 0 && arr[j] > x) { // run a while loop until j is valid and arr[j] is greater than x
      arr[j + 1] = arr[j]; // shift the larger element one position ahead
      j--; // decrement j by one to check the next previous element
    }
    arr[j + 1] = x; // insert x into its correct position
  }
}


// function to sort an array using selection sort
void selectionSort(int n, int arr[]) {
  for (int i = 0; i < n; i++) { // run a loop through the entire array
    for (int j = i + 1; j < n; j++) { // run a nested loop starting from the next element
      if (arr[i] > arr[j]) { // if the current element is greater than the next element
        swap(arr[i], arr[j]); // swap the two elements to place the smaller one at i
      }
    }
  }
}

// function to sort an array using bubble sort
void bubbleSort(int n, int arr[]) {
  for (int i = 0; i < n; i++) { // run a loop through the entire array
    for (int j = 0; j < n - i; j++) { // run a nested loop up to the unsorted portion
      if (arr[j] > arr[j + 1]) { // if the current element is greater than the next element
        swap(arr[j], arr[j + 1]); // swap the two elements to bubble up the larger one
      }
    }
  }
}


// function to partition the array around a pivot for quicksort
int partition(int L, int H, int arr[]) {
  int pivot = arr[L]; // set the pivot as the first element of the array
  int i = L, j = H, temp; // initialize i as the left index, j as the right index, and temp for swapping
  while (i < j) { // run a while loop until i and j cross
    while (arr[i] <= pivot) { // move i forward while elements are less than or equal to pivot
      i++; // increment i by one to check the next element
    }
    while (arr[j] > pivot) { // move j backward while elements are greater than pivot
      j--; // decrement j by one to check the next element
    }
    if (i < j) { // if i is still less than j
      temp = arr[i]; // store arr[i] in temp for swapping
      arr[i] = arr[j]; // replace arr[i] with arr[j]
      arr[j] = temp; // replace arr[j] with temp to complete the swap
    }
  }
  temp = arr[L]; // store the pivot in temp for final swap
  arr[L] = arr[j]; // move the element at j to the left position
  arr[j] = temp; // place the pivot in its final sorted position
  return j; // return the pivot’s final position
}

// function to sort an array using quicksort
void quickSort(int L, int H, int arr[]) {
  if (L < H) { // if the left index is less than the right index, there’s more than one element
    int j = partition(L, H, arr); // partition the array and get the pivot’s position
    quickSort(L, j, arr); // recursively sort the left subarray
    quickSort(j + 1, H, arr); // recursively sort the right subarray
  }
}

// main function to execute a sorting program
int main() {
  int n; // declare variable n to store the size of the array
  cin >> n; // input the size of the array from the user
  int arr[n]; // initialize array arr with size n
  for (int i = 0; i < n; i++) { // run a loop to input n elements
    cin >> arr[i]; // input each element into the array
  }
  int x; // declare variable x to store the user’s sorting choice
  cout << "Which algo do you want to use?" << endl << "1 - Bubble Sort\n2 - Merge Sort\n3 - Quick Sort\n4 - Selection Sort\n5 - Insertion Sort\n"; // display sorting options
  cin >> x; // input the user’s choice
  switch (x) { // use switch to select the sorting algorithm based on x
  case 1: // if user chooses 1
    bubbleSort(n, arr); // call bubbleSort to sort the array
    break; // exit the switch
  case 2: // if user chooses 2
    mergeSort(0, n - 1, arr); // call mergeSort from index 0 to n-1
    break; // exit the switch
  case 3: // if user chooses 3
    quickSort(0, n - 1, arr); // call quickSort from index 0 to n-1
    break; // exit the switch
  case 4: // if user chooses 4
    selectionSort(n, arr); // call selectionSort to sort the array
    break; // exit the switch
  case 5: // if user chooses 5
    insertionSort(n, arr); // call insertionSort to sort the array
    break; // exit the switch
  default: // if user enters an invalid choice
    cout << "Invalid input"; // display error message
    return 0; // exit the program
  }
  for (int i = 0; i < n; i++) { // run a loop to print the sorted array
    cout << arr[i] << " "; // output each element followed by a space
  }
}