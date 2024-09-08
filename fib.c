#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iterateFunc(int x) {
   int prevNum = 0;
   int saveNum = 0;
   int currNum = 1;
   if(x == 0) {
      return 0;
   }
   for(int i = 0; i < x; i++) {
      prevNum = saveNum;
      saveNum = currNum;
      currNum = saveNum + prevNum;
   }
   return saveNum;
}

// Needs fixing
int recursiveFunc(int N, int saveNum, int currNum, int prevNum) {
   if(N == 0) {
      return saveNum;
   } else {
      prevNum = saveNum;
      saveNum = currNum;
      currNum = saveNum + prevNum;
      recursiveFunc(N - 1, saveNum, currNum, prevNum);
   }
}

int main(int argc, char* argv[]) {
   int prevNum = 0;
   int saveNum = 0;
   int currNum = 1;
   if(strcmp(argv[2], "i") == 0) {
      int N = atoi(argv[1]);
      if(N == 0){
         printf("%d\n", iterateFunc(N));
      } else {
         printf("%d\n", iterateFunc(N));
      }  
   } else if(strcmp(argv[2], "r") == 0) {
      int N = atoi(argv[1]);
      if(N == 0) {
         printf("%d\n", N);
      } else {
         printf("%d\n", recursiveFunc(N, saveNum, currNum, prevNum));
      }
   }
   return 0;
}
