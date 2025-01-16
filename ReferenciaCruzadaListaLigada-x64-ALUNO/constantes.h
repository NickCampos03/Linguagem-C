#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define BUFFER_SIZE 2048
#define MAX_WORD_SIZE 80

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#endif // CONSTANTES_H_INCLUDED
