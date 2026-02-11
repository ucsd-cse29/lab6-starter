// This module re-implements getQueries using the string_span struct from span.h.

// Necessary to refer to "struct string_span"
#include "span.h"

struct string_span getQueries(char *url);
