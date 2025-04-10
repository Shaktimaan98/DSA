import java.util.Scanner;

public class HeapSort {
    private static int N;

    public static void sort(int arr[]) {
        buildMaxHeap(arr);
        for (int i = N; i > 0; i--) {
            swap(arr, 0, i);
            N = N - 1;
            maxHeapify(arr, 0);
        }
    }

    public static void buildMaxHeap(int arr[]) {
        N = arr.length - 1;
        for (int i = N / 2; i >= 0; i--) {
            maxHeapify(arr, i);
        }
    }

    public static void maxHeapify(int arr[], int i) {
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index
        int max = i;

        if (left <= N && arr[left] > arr[max])
            max = left;

        if (right <= N && arr[right] > arr[max])
            max = right;

        if (max != i) {
            swap(arr, i, max);
            maxHeapify(arr, max);
        }
    }

    public static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements to be sorted:");
        int n = in.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter " + n + " integer elements:");
        for (int i = 0; i < n; i++)
            arr[i] = in.nextInt();

        sort(arr);

        System.out.println("After sorting:");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        
        System.out.println();
        in.close();
    }
}
