package com.company;

public class IndexesBinsearch{

    public static void main(String[] args){

        binarySearchTests();
    }

    public static void find(int tab[], int target, int findex, int lindex){
        if (tab == null)
            return;

        int low = 0, high = tab.length - 1;

        int startIndex = -1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (tab[mid] > target) {
                high = mid - 1;
            } else if (tab[mid] == target) {
                startIndex = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        int endIndex = -1;
        low = 0;
        high = tab.length - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (tab[mid] > target) {
                high = mid - 1;
            } else if (tab[mid] == target) {
                endIndex = mid;
                low = mid + 1;
            } else
                low = mid + 1;
        }
        System.out.print("Indexes of array that contain " + target + ": ");
        if (startIndex != -1 && endIndex != -1){
            for(int i=0; i+startIndex<=endIndex;i++){
                if(i>0)
                    System.out.print(',' + " ");
                System.out.print(i+startIndex);
            }
        }

        System.out.println();

    }

    public static void binarySearchTests(){

        find(new int[]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1, 0, 9);
        find(new int[]{1, 1, 1, 1, 1, 1, 2, 2, 3, 4}, 1, 0, 5);
        find(new int[]{0, 0, 0, 1, 1, 1, 3, 4, 5, 5}, 1, 3, 5);
        find(new int[]{1, 1, 1, 1, 1, 1, 7, 7, 8, 9}, 9, 9, 9);
        find(new int[]{1, 1, 1, 1, 1, 1, 7, 7, 8, 9}, 10, -1, -1);

    }
}