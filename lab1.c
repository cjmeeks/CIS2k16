#include <stdin.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char[27] alphabet = {'ABCDEFGHIJKLMNOPQRSTUVWXYZ'};
  char[] key;
  printf("Please enter a Key: ", );
  scanf("%s\n",&key );


  return 0;
}
char[] createAlphabetAtChar(char[] bet, int charAt){
  char[27] new;
  int count = 0;
  for (size_t i = charAt; i != charAt-1; i++) {
    if(i == 26) i=0;
    &new[i] = &bet[count];
        /* code */
  }
}
