// 75 Sort Colors 
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red, white and blue. 
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note:
// You are not suppose to use the library's sort function for this problem.
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array
// with total number of 0's, then 1's and followed by 2's.
// Could you come up with an one-pass algorithm using only constant space?
class Solution {
public:
    void sortColors(int A[], int n) {
        int nColor[3]={0,0,0};
        for(int i = 0; i < n; i++){
            nColor[A[i]]++;
        }
        int j = 0;
        for(int i = 0; i < n; i++){
            while(nColor[j] == 0) j++;
            nColor[j]--;
            A[i] = j;
        }
    }
};

class Solution {
public:
    void sortColors(int A[], int n) {
        int second=n-1, zero=0;
        for (int i=0; i<=second; i++) {
            while (A[i]==2 && i<second) swap(A[i], A[second--]);
            while (A[i]==0 && i>zero) swap(A[i], A[zero++]);
        }
    }
};

public void sortColors(int[] A) {
       if(A==null || A.length<2) return;
       int low = 0; 
       int high = A.length-1;
       for(int i = low; i<=high;) {
           if(A[i]==0) {
              // swap A[i] and A[low] and i,low both ++
              int temp = A[i];
              A[i] = A[low];
              A[low]=temp;
              i++;low++;
           }else if(A[i]==2) {
               //swap A[i] and A[high] and high--;
              int temp = A[i];
              A[i] = A[high];
              A[high]=temp;
              high--;
           }else {
               i++;
           }
       }
   }