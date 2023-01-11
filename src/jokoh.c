#include <stdint.h> // uint64_t
#include <time.h> // clock_gettime

#include "jokoh.h"

__thread struct timespec __clkid;

/* clock_gettime API in nanoseconds */

uint64_t get_time_realtime(void)
{
  clock_gettime(CLOCK_REALTIME, &__clkid);
  return __clkid.tv_sec * 1000000000UL + __clkid.tv_nsec;
}

uint64_t get_time_monotonic(void)
{
  clock_gettime(CLOCK_MONOTONIC, &__clkid);
  return __clkid.tv_sec * 1000000000UL + __clkid.tv_nsec;
}

uint64_t get_time_monotonic_raw(void)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, &__clkid);
  return __clkid.tv_sec * 1000000000UL + __clkid.tv_nsec;
}

uint64_t get_time_process(void)
{
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &__clkid);
  return __clkid.tv_sec * 1000000000UL + __clkid.tv_nsec;
}

uint64_t get_time_thread(void)
{
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &__clkid);
  return __clkid.tv_sec * 1000000000UL + __clkid.tv_nsec;
}

/* clock_gettime API in seconds */

uint64_t get_time_realtime_sec(void)
{
  clock_gettime(CLOCK_REALTIME, &__clkid);
  return __clkid.tv_sec;
}

uint64_t get_time_monotonic_sec(void)
{
  clock_gettime(CLOCK_MONOTONIC, &__clkid);
  return __clkid.tv_sec;
}

uint64_t get_time_monotonic_raw_sec(void)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, &__clkid);
  return __clkid.tv_sec;
}

uint64_t get_time_process_sec(void)
{
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &__clkid);
  return __clkid.tv_sec;
}

uint64_t get_time_thread_sec(void)
{
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &__clkid);
  return __clkid.tv_sec;
}

/* x86/amd64 counter API */

#if defined(__x86_64__)

uint64_t get_time_x86(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtsc;\n"
     "shl $32, %%rdx;\n"
     "or %%rdx, %0;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     "rdx"
     );
  return cycles;
}

uint64_t get_time_x86_serialized(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtscp;\n"
     "shl $32, %%rdx;\n"
     "or %%rdx, %0;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     "rdx"
     );
  return cycles;
}

uint64_t get_time_amd64(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtsc;\n"
     "shl $32, %%rdx;\n"
     "or %%rdx, %0;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     "rdx"
     );
  return cycles;
}

uint64_t get_time_amd64_serialized(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtscp;\n"
     "shl $32, %%rdx;\n"
     "or %%rdx, %0;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     "rdx"
     );
  return cycles;
}

#elif defined(__i386__)

uint32_t get_time_x86(void)
{
  uint32_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtsc;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint32_t get_time_x86_serialized(void)
{
  uint32_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtscp;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint32_t get_time_amd64(void)
{
  uint32_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtsc;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint32_t get_time_amd64_serialized(void)
{
  uint32_t cycles = 0;
  asm volatile
    (
     // Assembly
     "rdtscp;\n"

     // outputs
     :
     "=a" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

#endif

/* aarch64 counter API */

#if defined(__aarch64__)

uint64_t get_time_aarch64_physical(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "mrs %0, cntpct_el0;\n"

     // outputs
     :
     "=r" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint64_t get_time_aarch64_physical_serialized(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "mrs %0, cntpctss_el0;\n"

     // outputs
     :
     "=r" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint64_t get_time_aarch64_virtual(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "mrs %0, cntvct_el0;\n"

     // outputs
     :
     "=r" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint64_t get_time_aarch64_virtual_serialized(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "mrs %0, cntvctss_el0;\n"

     // outputs
     :
     "=r" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

uint64_t get_time_aarch64_performance(void)
{
  uint64_t cycles = 0;
  asm volatile
    (
     // Assembly
     "mrs %0, pmccntr_el0;\n"

     // outputs
     :
     "=r" (cycles)

     // inputs
     :

     // clobbers
     :
     );
  return cycles;
}

#endif
