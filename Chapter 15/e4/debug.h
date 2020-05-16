#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#define DEBUG

#ifdef DEBUG
#define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n);
#else
#define PRINT_DEBUG(n)
#endif



#endif // DEBUG_H_INCLUDED
