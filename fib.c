#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Iterates the function by N placed into int X
// Variables are set to keep track of current and
// previous numbers to allow Fibonacci
int Iterate_Function(int fib_num) {
   int prev_num = 0;
   int save_num = 0;
   int curr_num = 1;

   if(fib_num == 0) {
      return prev_num;
   }
   for(int ix = 2; ix <= fib_num; ix++) {
      save_num = prev_num + curr_num;
      prev_num = curr_num;
      curr_num = save_num;
   }
   return save_num;
}

// Recursive function that has N placed into X along with 
// other variables mentioned in main respectively
// Variables prevNum, saveNum, and currNum are used the same as iterative
int Recursive_Function(int fib_num) {
   if(fib_num <= 1) {
      return fib_num;
   } else {
      return Recursive_Function(fib_num - 1) + Recursive_Function(fib_num - 2);
   }
}

// Main paramaters are utilized to grab command line string to 
// be used through this part
int main(int argc, char* argv[]) {
   // FILE is used and as a pointer to indicate the usage of 
   // the data stored with file
   FILE* file;
   // TextNum is used in order to store the number kept inside
   // the specified text file
   int text_num;

   // Fopen is used to open an existing file
   // Specified by the first paramter with "r" representing read
   file = fopen(argv[3], "r");
   // Fscanf is used to go through the data in file which
   // is then stored into textNum
   fscanf(file, "%d", &text_num);

   if(argv[3] == NULL) {
      printf("No such file has been found\n");
      return 1;
   }

   // Both the user command line and the text file numbers are added together
   int fib_num = atoi(argv[1]) + text_num;
   // N is subtracted by 1 as a required thing in Fibonacci sequencing
   fib_num -= 1;

   if(strcmp(argv[2], "i") == 0) {
      printf("%d\n", Iterate_Function(fib_num)); 
   } else if(strcmp(argv[2], "r") == 0) {
      printf("%d\n", Recursive_Function(fib_num));
   }
   return 0;
}
