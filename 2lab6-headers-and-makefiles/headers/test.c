#include "span.h"    // for struct string_span
#include "queries.h" // for getQueries
#include <stdlib.h>  // for free
#include <stdio.h>   // for printf

int main() {
    char url[] = "https://lab6.cse29.site/?Section=Makefiles";
    struct string_span span = getQueries(url);

    char *span_copy = span_alloc_copy(&span);
    printf("%s\n", span_copy);
    
    span_free(&span);
    free(span_copy);
}
