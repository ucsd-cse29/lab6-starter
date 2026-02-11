#include "queries.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct string_span getQueries(char *url) {
    int length = strlen(url);
    char *lowercased = malloc(length + 1);
    // Assume successful allocation
    int question_mark_index = -1;

    for (int i = 0; url[i] != '\0'; ++i) {
        lowercased[i] = tolower(url[i]);
        if (url[i] == '?') question_mark_index = i;
    }
    lowercased[strlen(url)] = '\0';

    if (question_mark_index == -1) {
        // Return an empty span. The indices don't matter
        struct string_span span = { lowercased, 0, 0 };
        return span;
    }
    
    struct string_span span = { lowercased, question_mark_index + 1, length };
    return span;
}
