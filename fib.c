#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Iterates the function by N placed into int X
// Variables are set to keep track of current and previous numbers to allow Fibonacci
int iterateFunc(int x) {
   int prevNum = 0;
   int saveNum = 0;
   int currNum = 1;

   if(x == 0) {
      return prevNum;
   }
   for(int i = 2; i <= x; i++) {
      saveNum = prevNum + currNum;
      prevNum = currNum;
      currNum = saveNum;
   }
   return saveNum;
}

// Recursive function that has N placed into X along with other variables mentioned in main respectively
// Variables prevNum, saveNum, and currNum are used the same as iterative
int recursiveFunc(int N) {
   if(N <= 1) {
      return N;
   } else {
      return recursiveFunc(N-1) + recursiveFunc(N-2);
   }
}

// Main paramaters are utilized to grab command line string to be used through this part
int main(int argc, char* argv[]) {
   // FILE is used and as a pointer to indicate the usage of the data stored with file
   FILE* file;
   // TextNum is used in order to store the number kept inside the specified text file
   int textNum;

   // Fopen is used to open an existing file
   // Specified by the first paramter with "r" representing read
   file = fopen(argv[3], "r");
   // Fscanf is used to go through the data in file which is then stored into textNum
   fscanf(file, "%d", &textNum);

   if(argv[3] == NULL) {
      printf("No such file has been found\n");
      return 1;
   }

   // Both the user command line and the text file numbers are added together
   int N = atoi(argv[1]) + textNum;
   // N is subtracted by 1 as a required thing in Fibonacci sequencing
   N -= 1;

   if(strcmp(argv[2], "i") == 0) {
      printf("%d\n", iterateFunc(N)); 
   } else if(strcmp(argv[2], "r") == 0) {
      printf("%d\n", recursiveFunc(N));
   }
   return 0;
}

