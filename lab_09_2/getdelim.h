# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>

#if !HAVE_DECL_GETDELIM
ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream);
#endif /* !HAVE_GETDELIM */