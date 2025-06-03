
#ifndef PLATFORM_POSIX_PORTABLE_H_
 #define PLATFORM_POSIX_PORTABLE_H_

 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
 #include <limits.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <signal.h>
 #include <pthread.h>
#include <stdint.h>
 
 #define PRIVILEGED_FUNCTION
 
 #define configTOTAL_HEAP_SIZE (128 * 1024)
 
 #define portBYTE_ALIGNMENT 8
 
 #if portBYTE_ALIGNMENT == 8
 #define portBYTE_ALIGNMENT_MASK (0x0007)
 #endif
 
 #define mtCOVERAGE_TEST_MARKER()
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 /*
  * Map to the memory management routines required for the port.
  */
 void *pvPortMalloc(size_t xSize) PRIVILEGED_FUNCTION;
 void vPortFree(void *pv) PRIVILEGED_FUNCTION;
 void vPortInitialiseBlocks(void) PRIVILEGED_FUNCTION;
 size_t xPortGetFreeHeapSize(void) PRIVILEGED_FUNCTION;
 size_t xPortGetMinimumEverFreeHeapSize(void) PRIVILEGED_FUNCTION;
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif /* PLATFORM_POSIX_PORTABLE_H_ */
 