//Jan Skwarczek - grupa 8.

import java.util.Arrays;

class Source{

    static void merge(char tab[], int l, int m, int r){

        int n1 = m - l + 1;
        int n2 = r - m;

        char L[] = new char [n1];
        char R[] = new char [n2];

        for (int i=0; i<n1; ++i)
            L[i] = tab[l + i];

        for (int j=0; j<n2; ++j)
            R[j] = tab[m + 1+ j];

        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                tab[k] = L[i];
                i++;
            }
            else
            {
                tab[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            tab[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            tab[k] = R[j];
            j++;
            k++;
        }
    }

    static void sort(char tab[], int l, int r){

        if (l < r){

            int m = (l+r)/2;

            sort(tab, l, m);
            sort(tab , m+1, r);

            merge(tab, l, m, r);
        }
    }

    static int shellSort(int tab[]){

        int n = tab.length;

        for (int gap = n/2; gap > 0; gap /= 2)
        {

            for (int i = gap; i < n; i += 1)
            {

                int temp = tab[i];

                int j;
                for (j = i; j >= gap && tab[j - gap] > temp; j -= gap)
                    tab[j] = tab[j - gap];

                tab[j] = temp;
            }
        }
        return 0;
    }

    static int getMax(char[] tab, int n)
    {
        int mx = tab[0];
        for (int i = 1; i < n; i++)
            if (tab[i] > mx)
                mx = tab[i];
        return mx;
    }

    static void countSort(char[] tab, int n, int exp)
    {
        char output[] = new char[n];
        int i;
        int count[] = new int[10];
        Arrays.fill(count,0);

        for (i = 0; i < n; i++)
            count[ (tab[i]/exp)%10 ]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[ (tab[i]/exp)%10 ] - 1] = tab[i];
            count[ (tab[i]/exp)%10 ]--;
        }

        for (i = 0; i < n; i++)
            tab[i] = output[i];
    }

    static void radixsort(char[] tab, int n)
    {

        int m = getMax(tab, n);

        for (int exp = 1; m/exp > 0; exp *= 10)
            countSort(tab, n, exp);
    }

    public static int partition (int[] tab, int low, int high)
    {
        int swapPivot = tab[high], pivotloc = low;
        for (int i = low; i <= high; i++)
        {

            if(tab[i] < swapPivot)
            {
                int temp = tab[i];
                tab[i] = tab[pivotloc];
                tab[pivotloc] = temp;
                pivotloc++;
            }
        }

        int temp = tab[high];
        tab[high] = tab[pivotloc];
        tab[pivotloc] = temp;

        return pivotloc;
    }

    public static int smallestKth(int[] tab, int low, int high, int k)
    {
        int partition = partition(tab,low,high);

        if(partition == k)
            return tab[partition];

        else if(partition < k )
            return smallestKth(tab, partition + 1, high, k );

        else
            return smallestKth(tab, low, partition-1, k );
    }

    public static void printSelect (int[] tab){

        for(int i=0; i<tab.length; i++){

            System.out.print(tab[i] + " ");

        }
    }

    static void printArrayRadix(char[] tab, int n)
    {
        for (int i=0; i<n; i++)
            System.out.print(tab[i]+" ");

        System.out.println();
    }

    static void printArrayMerge(char[] tab){

        int n = tab.length;
        for (int i=0; i<n; ++i)
            System.out.print(tab[i] + " ");
        System.out.println();
    }

    static void printArrayShell(int[] tab){

        int n = tab.length;
        for (int i=0; i<n; ++i)
            System.out.print(tab[i] + " ");
        System.out.println();
    }

    public static void main(String args[])
    {
        int shellTab[] = {12, 34, 54, 2, 3};

        System.out.print("SHELL SORT\nBEFORE: ");
        printArrayShell(shellTab);
        shellSort(shellTab);
        System.out.print("AFTER: ");
        printArrayShell(shellTab);

        char mergeTab[] = {'c', 'd', 'r', 'a', 'b', 'x'};

        System.out.println("\nMERGE SORT ON CHARS\nBEFORE:");
        printArrayMerge(mergeTab);
        sort(mergeTab, 0, mergeTab.length-1);
        System.out.println("AFTER: ");
        printArrayMerge(mergeTab);

        char radixTab[] = {'c', 'd', 'r', 'a', 'b', 'x'};
        int n = radixTab.length;

        System.out.println("\nRADIX SORT ON CHARS\nBEFORE:");
        printArrayRadix(radixTab, n);
        radixsort(radixTab, n);
        System.out.println("AFTER: ");
        printArrayRadix(radixTab, n);

        int[] selectTab = new int[]{10, 4, 5, 8, 6, 11, 26};
        int[] arraycopy = new int[]{10, 4, 5, 8, 6, 11, 26};
        int kPosition = 3;
        int length = selectTab.length;

        System.out.println();
        printSelect(selectTab);
        System.out.println("\nSMALLEST k-th ELEMENT: " + smallestKth(arraycopy, 0, length - 1, kPosition - 1));

    }
}