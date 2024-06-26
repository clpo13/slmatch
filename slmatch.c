/**
 * Test S-Lang regex matching on an arbitrary string.
 * Useful for testing patterns in the slrn newsreader's scorefile.
 *
 * Originally by Matthias Friedrich
 * See <https://groups.google.com/g/de.comm.software.newsreader/c/wldgrhtISrA/m/A5K7zKxC4eMJ>
 * or search de.comm.software.newsreader for message ID <slrn9u07di.93n.matt@endeavour.mafr.de>.
 *
 * Compile with `gcc -o slmatch slmatch.c -lslang`
 */

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
