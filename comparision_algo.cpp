#include <algorithm> // for std::swap
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;
// Bubble Sort
void bubbleSort(vector<int> &arr) {
  int n = arr.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}
// Selection Sort
void selectionSort(vector<int> &arr) {
  int n = arr.size();
  int minIdx;
  for (int i = 0; i < n - 1; i++) {
    minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    
    if (i != minIdx)
      swap(arr[i], arr[minIdx]);
  }
}
// Insertion Sort
void insertionSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
// Helper function to find the median of three
int medianOfThree(vector<int> &arr, int low, int mid, int high) {
  if ((arr[low] < arr[mid] && arr[mid] < arr[high]) ||
      (arr[high] < arr[mid] && arr[mid] < arr[low]))
    return mid;
  else if ((arr[mid] < arr[low] && arr[low] < arr[high]) ||
           (arr[high] < arr[low] && arr[low] < arr[mid]))
    return low;
  else
    return high;
}
// Partition function with median-of-three
int partition_mot(vector<int> &arr, int low, int high) {
  int mid = low + (high - low) / 2;
  int medianIndex = medianOfThree(arr, low, mid, high);
  // Swap the median value with the high element to use it as pivot
  swap(arr[medianIndex], arr[high]);
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}
void quickSort_mot(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition_mot(arr, low, high);
    quickSort_mot(arr, low, pi - 1);
    quickSort_mot(arr, pi + 1, high);
  }
}
// Quick Sort
int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}
void quickSort(vector<int> &arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[mid + 1 + i];
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}
void mergeSort(vector<int> &arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}
// Heap Sort
void heapify(vector<int> &arr, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}
void heapSort(vector<int> &arr) {
  int n = arr.size();
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
// Function to generate a random vector of size N
vector<int> generateRandomVector(int N) {
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    arr[i] = rand() % 100000; // Random value assignment
    // arr[i] = i + 1; // Ascendingly sorted values
    // arr[i] = N - i; // Descendingly sorted values
    // arr[i] = 1; // Duplicate values
  }
  return arr;
}
void print_vector(vector<int> vec) {
  for (auto v : vec)
    cout << v << " ";
  cout << endl;
}
int main() {
  int N = 10000; // Change N as needed
  vector<int> arr;
  arr = generateRandomVector(N);
  
  // cout << "Original array: ";
  // print_vector(arr);
  // cout << endl;
  
  cout << "Case 1: Sorting a random array ascendingly\n";
  
  // cout << "Case 2: Sorting an already ascendingly sorted array ascendingly\n";
  
  // cout << "Case 3: Sorting a nearly ascendingly sorted array ascendingly\n";
  // Make an array less sorted
  // int num_rounds = 10;
  // for (int round = 1; round <= num_rounds; round++) {
  //   int first_index = rand() % N;
  //   int second_index = rand() % N;
  //   swap(arr[first_index], arr[second_index]);
  // }
  
  // print_vector(arr);
  // cout << "Case 4: Sorting an already descendingly sorted array ascendingly\n";
  
  // cout << "Case 5: Sorting an array with all duplicates ascendingly\n";
  
  // cout << "Case 6: Sorting an array with many duplicates ascendingly\n";
  // // Remove duplicates in an array
  // int num_rounds = 1000;
  // for (int round = 1; round <= num_rounds; round++) {
  //   int index = rand() % N;
  //   arr[index] = rand() % 10000;
  // }
  // Bubble Sort
  vector<int> tmp_arr_bs(arr);
  // print_vector(tmp_arr_bs);
  auto start = high_resolution_clock::now();
  bubbleSort(tmp_arr_bs);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Bubble Sort took " << duration.count() << " microseconds" << endl
       << endl;
  // Selection Sort
  vector<int> tmp_arr_ss(arr);
  // print_vector(tmp_arr_ss);
  start = high_resolution_clock::now();
  selectionSort(tmp_arr_ss);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Selection Sort took " << duration.count() << " microseconds" << endl
       << endl;
  // Insertion Sort
  vector<int> tmp_arr_is(arr);
  start = high_resolution_clock::now();
  // print_vector(tmp_arr_is);
  insertionSort(tmp_arr_is);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Insertion Sort took " << duration.count() << " microseconds" << endl
       << endl;
  // Merge Sort
  vector<int> tmp_arr_ms(arr);
  // print_vector(tmp_arr_ms);
  start = high_resolution_clock::now();
  mergeSort(tmp_arr_ms, 0, N - 1);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Merge Sort took " << duration.count() << " microseconds" << endl
       << endl;
  // Quick Sort
  vector<int> tmp_arr_qsl(arr);
  // print_vector(tmp_arr_qsl);
  start = high_resolution_clock::now();
  quickSort(tmp_arr_qsl, 0, N - 1);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Quick Sort using last-element pivot took " << duration.count()
       << " microseconds" << endl
       << endl;
  // Quick Sort using Median of Three pivot
  vector<int> tmp_arr_qs3(arr);
  // print_vector(tmp_arr_qs3);
  start = high_resolution_clock::now();
  quickSort_mot(tmp_arr_qs3, 0, N - 1);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Quick Sort using median-of-3 pivot took " << duration.count()
       << " microseconds" << endl
       << endl;
  // Heap Sort
  vector<int> tmp_arr_hs(arr);
  // print_vector(tmp_arr_hs);
  start = high_resolution_clock::now();
  heapSort(tmp_arr_hs);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Heap Sort took " << duration.count() << " microseconds" << endl
       << endl;
  // Intro Sort
  vector<int> intro_arr(arr);
  // print_vector(intro_arr);
  start = high_resolution_clock::now();
  sort(intro_arr.begin(), intro_arr.end());
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Intro Sort took " << duration.count() << " microseconds" << endl
      << endl;
  return 0;
}

