// The typical boilerplate for a key-value object
// A structure plus new/copy/free functions

#include <stdlib.h> //malloc
#include <strings.h> //strcasecmp (from POSIX)
#include "keyval.h"

keyval *keyval_new(char *key, void *value) {
    keyval *out = malloc(sizeof(keyval));
    *out = (keyval){.key = key, .value=value};
    return out;
}

/** Copy a key-value pair. The new pair has pointers to the values in the old
 * pair, not copies of their data. Recall that this struct is all pointers.
 */
keyval *keyval_copy(keyval const *in) {
    keyval *out = malloc(sizeof(keyval));
    *out = *in;
    return out;
}

void keyval_free(keyval *in){ free(in); }

int keyval_matches(keyval const *in, char const *key) {
    return !strcasecmp(in->key, key);
}

