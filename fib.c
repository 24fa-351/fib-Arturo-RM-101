#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Iterates the function by N placed into int X
// Variables are set to keep track of current and
// previous numbers to allow Fibonacci
int Iterate_Function(int Nth) {
   int Prev_Num = 0;
   int Save_Num = 0;
   int Curr_Num = 1;

   if(Nth == 0) {
      return Prev_Num;
   }
   for(int i = 2; i <= Nth; i++) {
      Save_Num = Prev_Num + Curr_Num;
      Prev_Num = Curr_Num;
      Curr_Num = Save_Num;
   }
   return Save_Num;
}

// Recursive function that has N placed into X along with 
// other variables mentioned in main respectively
// Variables prevNum, saveNum, and currNum are used the same as iterative
int Recursive_Function(int Nth) {
   if(Nth <= 1) {
      return Nth;
   } else {
      return Recursive_Function(Nth - 1) + Recursive_Function(Nth - 2);
   }
}

// Main paramaters are utilized to grab command line string to 
// be used through this part
int main(int argc, char* argv[]) {
   // FILE is used and as a pointer to indicate the usage of 
   // the data stored with file
   FILE* File;
   // TextNum is used in order to store the number kept inside
   // the specified text file
   int Text_Num;

   // Fopen is used to open an existing file
   // Specified by the first paramter with "r" representing read
   File = fopen(argv[3], "r");
   // Fscanf is used to go through the data in file which
   // is then stored into textNum
   fscanf(File, "%d", &Text_Num);

   if(argv[3] == NULL) {
      printf("No such file has been found\n");
      return 1;
   }

   // Both the user command line and the text file numbers are added together
   int Nth = atoi(argv[1]) + Text_Num;
   // N is subtracted by 1 as a required thing in Fibonacci sequencing
   Nth -= 1;

   if(strcmp(argv[2], "i") == 0) {
      printf("%d\n", Iterate_Function(Nth)); 
   } else if(strcmp(argv[2], "r") == 0) {
      printf("%d\n", Recursive_Function(Nth));
   }
   return 0;
}
