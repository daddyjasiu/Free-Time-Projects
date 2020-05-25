class RecursiveDivideAndConquer {

    static int DAC(int arr[], int l, int m, int h){

        int sum = 0;
        int left_sum = Integer.MIN_VALUE;

        for (int i = m; i >= l; i--){
            sum = sum + arr[i];
            if (sum > left_sum)
                left_sum = sum;
        }

        sum = 0;
        int right_sum = Integer.MIN_VALUE;

        for (int i = m + 1; i <= h; i++){
            sum = sum + arr[i];
            if (sum > right_sum)
                right_sum = sum;
        }

        return left_sum + right_sum;
    }

    static int DAC(int arr[], int l, int h){

        if (l == h)
            return arr[l];

        int m = (l + h)/2;

        return Math.max(Math.max(DAC(arr, l, m),
                DAC(arr, m+1, h)),
                DAC(arr, l, m, h));
    }

    public static void main(String[] args){

        int arr[] = {-8, 7, 5, -2, 4, -5, 2, 3, -1}; // 7 + 5 + (-2) + 4 + (-5) + 2 + 3 = 14
        int n = arr.length;
        int max_sum = DAC(arr, 0, n-1);

        System.out.println("Maximum sum: " + max_sum);

    }
}