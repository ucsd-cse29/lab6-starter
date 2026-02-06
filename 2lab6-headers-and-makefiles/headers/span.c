#include <stdlib.h>
#include <string.h>
#include "span.h"

// Because of the #include above, we don't need to declare the struct here.
// It is already defined!

struct string_span span_entire_string(char *string) {
    struct string_span out = { string, 0, strlen(string) };
    return out;
}

int span_length(struct string_span *span) {
    return span->end - span->start;
}

void span_free(struct string_span *span) {
    free(span->string);
}

char span_at(struct string_span *span, int index) {
    return span->string[span->start + index];
}

char *span_alloc_copy(struct string_span *span) {
    int size = sizeof(char) * (span_length(span) + 1);
    char *copy = malloc(size);
    if (copy == NULL) {
        return NULL;
    }
    strncpy(copy, &span->string[span->start], size);
    return copy;
}
