#include <stdio.h>
#include <stdlib.h>

/* **argv:ポインター配列
*p で定義したポインタpを *p=argc[1]とすうことで、引数のポインタ配列を指すようにした
これにより、pもポインタ配列として使用することができるようになり、
p++で配列の次のアドレス（つまり次の要素）に移る。

*/

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  char *p = argv[1];
  

  printf(".intel_syntax noprefix\n");
  printf(".globl main\n");
  printf("main:\n");
  printf("  mov rax, %ld\n", strtol(p, &p, 10));
  while (*p) {
    if (*p == '+'){
      p++;
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if (*p == '-'){
      p++;
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "予期しない文字です： '%c'\n", *p);
    return 1;
  }





  printf("  ret\n");
  return 0;
}

