#include <stdio.h>
#include <string.h>
#include <slang.h>

#define BUF_SIZE 256

int main(int argc, char *argv[])
{
unsigned char buf[BUF_SIZE];
SLRegexp_Type regex;
unsigned char *bp;

if ( argc != 3 ) {
fprintf(stderr, "slmatch: Usage: slmatch pattern string\n");
exit(2);
}

regex.pat = (unsigned char *)argv[1];
regex.buf = buf;
regex.buf_len = BUF_SIZE;
regex.case_sensitive = 0;

SLang_regexp_compile(&regex);

bp = SLang_regexp_match( (unsigned char *)argv[2], strlen(argv[2]),
&regex);

if ( bp == NULL ) {
printf("no match\n");
exit(1);
}

printf("match: %s\n", bp);

return 0;
}
