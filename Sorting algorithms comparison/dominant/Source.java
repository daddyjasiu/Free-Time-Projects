import java.util.*;

//The program firstly randomly fills the array with testsNum random numbers in the range of INT.
//Then, it performs sorting and counts dominant operations in these algorithms.
//Lastly it outputs these numbers to the console.
//I have made a graph with the values that I got from running
//this program and have tested this program for testsNum range 1k-50k.

public class Source {

    //variables responsible for counting dominant ops
    static long bubbleDom = 0;
    static long insertDom = 0;
    static long quickDom = 0;

    static void bubbleSort(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1]) {

                    //bubblesort dominant ops counting
                    bubbleDom++;

                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
    }

    static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {

                //insertion sort dominant ops counting
                insertDom++;

                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    static int partition(int[] arr, int low, int high) {

        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {

            if (arr[j] < pivot) {

                //quicksort dominant ops counting
                quickDom++;

                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void fillArrayRandom(int[] arr) {

        for (int i = 0; i < arr.length; i++) {

            arr[i] = new Random().nextInt();
        }

    }


    public static void main(String[] args) {

        int testsNum = 50000;

        int[] arr = new int[testsNum];

        //random fill and sorting
        fillArrayRandom(arr);
        bubbleSort(arr);

        //random fill again so that it
        //doesn't sort an already sorted array
        fillArrayRandom(arr);
        insertionSort(arr);

        fillArrayRandom(arr);
        quickSort(arr, 0, arr.length-1);

        //output
        System.out.println("bubbleDom: " + bubbleDom);
        System.out.println("insertDom: " + insertDom);
        System.out.println("quickDom: " + quickDom);

    }
}


