// The SPAN module implements a string "span" data structure, which represents
// a substring of an existing C-string. This data structure could have been
// useful for the losing_track.c exercise from Lab 4, where we tried to return
// a span of an existing string from getQueries.

struct string_span {
    // The entire C string in which this span can be found.
    char *string;
    // The index of the first character of this span in `string`.
    int start;
    // The index of the first character after this span in `string`.
    int end;
};

struct string_span span_entire_string(char *string);
int span_length(struct string_span *span);
void span_free(struct string_span *span);
char span_at(struct string_span *span, int index);
char *span_alloc_copy(struct string_span *span);

