#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SYMBOLS "!@#$%^&*()-_=+"
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

void gen(char *pw, size_t pw_size);

int main(int argc, char* argv[]) {
  srand((unsigned) time(NULL));
  if (argc > 2) { return EXIT_SUCCESS; }
  char pw[13] = "";
  gen(pw, sizeof pw);
  printf( "pw = \"%s\"\n", pw);
  return 0;
}

// one symbol, one upper- and one lowercase letter, one number, min. 13
void gen(char *pw, size_t pw_size) {
  rand(); // initialize broken rand 
  int random_symbol_index = rand() % (sizeof SYMBOLS);
  char random_symbol = SYMBOLS[random_symbol_index];
  int random_number = rand() % 10;

  pw[0] = random_symbol;
  for (size_t i = 1; i < pw_size - 1; i++) {
    int random_char_index = rand() % (26);
    char random_char = ALPHABET[random_char_index];
    if (i % 2 == 0) {
      random_char = toupper((unsigned char)random_char);
    }
    pw[i] = random_char;
  }
  pw[pw_size - 1] = ((rand() % 10) + '0'); 
  pw[pw_size] = 0; // excess string
}
