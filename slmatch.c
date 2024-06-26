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
#include <stdlib.h>
#include <string.h>
#include <slang.h>

int main(int argc, char *argv[])
{
    SLRegexp_Type *regex;
    char *bp;

    if ( argc != 3 ) {
        fprintf(stderr, "slmatch: Usage: slmatch pattern string\n");
        exit(2);
    }

    regex = SLregexp_compile(argv[1], SLREGEXP_CASELESS|SLREGEXP_UTF8);

    bp = SLregexp_match(regex, argv[2], strlen(argv[2]));

    if ( bp == NULL ) {
        printf("no match\n");
        SLregexp_free(regex);
        exit(1);
    }

    printf("match: %s\n", bp);

    SLregexp_free(regex);
    return 0;
}
