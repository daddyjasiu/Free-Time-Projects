import java.io.*;

//The program firstly fills the array with values 1...n.
//Then, it uses heap algorithm to find all the permutations.
//Lastly it sorts every permutation and counts their exec max, min and avg times.

public class Source {

    //variables for printing exec times
    static long bubbleSum = 0;
    static long bubbleMax = 0;
    static long bubbleMin = Long.MAX_VALUE;

    static long insertSum = 0;
    static long insertMax = 0;
    static long insertMin = Long.MAX_VALUE;

    static long quickSum = 0;
    static long quickMax = 0;
    static long quickMin = Long.MAX_VALUE;

    //array printing method
    static void printArr(int a[], int n)
    {
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();

    }

    //bubblesort algorithm
    static void bubbleSort(int[] arr)
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }

    }

    //insertion sort algorithm
    static void insertionSort(int[] arr)
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    //partition method for quicksort algorithm
    static int partition(int[] arr, int low, int high)
    {
        int pivot = arr[high];
        int i = (low-1);
        for (int j=low; j<high; j++)
        {

            if (arr[j] < pivot)
            {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

    //main recursive method of quicksort algorithm
    static void quickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }

    //heap algorithm for finding permutations (recursive)
    static void heapPermutation(int a[], int size, int n)
    {

        //if size == becomes 1 then calculate exec times
        //and save them to specific variables
        if (size == 1) {

            int[] bubbleArr = a;
            int[] insertArr = a;
            int[] quickArr = a;

            long bubbleStart = System.nanoTime();
            bubbleSort(bubbleArr);
            long bubbleEnd = System.nanoTime();

            if(bubbleEnd-bubbleStart<bubbleMin)
                bubbleMin = (bubbleEnd-bubbleStart);
            if(bubbleEnd-bubbleStart>bubbleMax)
                bubbleMax = (bubbleEnd-bubbleStart);

            bubbleSum+=(bubbleEnd-bubbleStart);

            long insertStart = System.nanoTime();
            insertionSort(insertArr);
            long insertEnd = System.nanoTime();

            if(insertEnd-insertStart<insertMin)
                insertMin = (insertEnd-insertStart);
            if(insertEnd-insertStart>insertMax)
                insertMax = (insertEnd-insertStart);

            insertSum+=(insertEnd-insertStart);

            long quickStart = System.nanoTime();
            quickSort(quickArr, 0, quickArr.length-1);
            long quickEnd = System.nanoTime();

            if(quickEnd-quickStart<quickMin)
                quickMin = (quickEnd-quickStart);
            if(quickEnd-quickStart>quickMax)
                quickMax = (quickEnd-quickStart);

            quickSum+=(quickEnd-quickStart);

        }

        for (int i = 0; i < size; i++) {
            heapPermutation(a, size - 1, n);

            //if size is odd, swap first and last element
            if (size % 2 == 1) {
                int temp = a[0];
                a[0] = a[size - 1];
                a[size - 1] = temp;
            }

            //if size is even, swap ith and last element
            else {
                int temp = a[i];
                a[i] = a[size - 1];
                a[size - 1] = temp;
            }
        }
    }

    //main driver method
    public static void main(String[] args){

        //number of permutations (n! exec times of n! arrays of size n will be calculated)
        int n = 10;
        int a[] = new int[n];

        //filling the array with sorted values 1-n
        for (int i = 0; i < a.length; i++) {
            a[i]=i+1;
        }

        //finding permutations using heap and putting them in list
        heapPermutation(a, a.length, a.length);

        //printing final results
        System.out.println("For " + n + " permutations speeds of algorithms are:\n");

        System.out.println("Bubblesort");
        System.out.println("optimal time: " + bubbleMin);
        System.out.println("pesimistic time: " + bubbleMax);
        System.out.println("average time: " + (bubbleSum/n) + "\n");

        System.out.println("Insertion sort");
        System.out.println("optimal time: " + insertMin);
        System.out.println("pesimistic time: " + insertMax);
        System.out.println("average time: " + (insertSum/n) + "\n");

        System.out.println("Quicksort");
        System.out.println("optimal time: " + quickMin);
        System.out.println("pesimistic time: " + quickMax);
        System.out.println("average time: " + (quickSum/n) + "\n");

    }

}
