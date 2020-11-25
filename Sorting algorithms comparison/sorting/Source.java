import java.util.Random;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

//Firstly, the program fills the array with n random numbers in the range of an INT.
//Then, it sorts the array with three algorithms - bubblesort, insertion sort and quicksort.
//It measures time of each sorting operation and saves the results in .txt files.
//The time is measured in nanoseconds, so that it is more accurate in algo comparison.
//I have presented the results on a graph in the added graphic file.
//The n range that I have tested this program for is 10-500k.

public class Source {

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

    static void quickSort(int[] arr, int low, int high)
    {
        if (low < high)
        {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }

    static void fillArrayRandom(int[] arr){

        for (int i = 0; i < arr.length; i++) {

            arr[i] = new Random().nextInt();
        }

    }

    static void bubbleSaveToFile(int[] arr, int testsNum){

        fillArrayRandom(arr);

        try {
            FileWriter myWriter = new FileWriter(testsNum + " bubble data.txt");

            long start, end;

            Random rand = new Random(System.currentTimeMillis());

            //time measurement
            start = System.nanoTime();
            bubbleSort(arr);
            end = System.nanoTime();

            myWriter.write(String.valueOf(end-start));

            myWriter.close();
            System.out.println("Bubblesort exec time file ready.");

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    static void insertionSaveToFile(int[] arr, int testsNum){

        fillArrayRandom(arr);

        try {
            FileWriter myWriter = new FileWriter(testsNum + " insertion data.txt");

            long start, end;

            Random rand = new Random(System.currentTimeMillis());

            //time measurement
            start = System.nanoTime();
            insertionSort(arr);
            end = System.nanoTime();

            myWriter.write(String.valueOf(end-start));


            myWriter.close();
            System.out.println("Insertion sort exec time file ready.");

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    static void quickSaveToFile(int[] arr, int testsNum){

        fillArrayRandom(arr);

        try {
            FileWriter myWriter = new FileWriter(testsNum + " quick data.txt");

            long start, end;

            Random rand = new Random(System.currentTimeMillis());

            //time measurement
            start = System.nanoTime();
            quickSort(arr, 0, arr.length-1);
            end = System.nanoTime();

            myWriter.write(String.valueOf(end-start));


            myWriter.close();
            System.out.println("Quicksort exec time file ready.");

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    public static void main(String[] args){

        int testsNum = 70000;

        int[] arr = new int[testsNum];

        bubbleSaveToFile(arr, testsNum);
        insertionSaveToFile(arr, testsNum);
        quickSaveToFile(arr, testsNum);

    }

}
