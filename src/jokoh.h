#ifndef _JOKOH_H_
#define _JOKOH_H_

#include <stdint.h>
#include <time.h>

extern __thread struct timespec __clkid;

/* clock_gettime API in nanoseconds */
uint64_t get_time_realtime(void);
uint64_t get_time_monotonic(void);
uint64_t get_time_monotonic_raw(void);
uint64_t get_time_process(void);
uint64_t get_time_thread(void);

/* clock_gettime API in seconds */
uint64_t get_time_realtime_sec(void);
uint64_t get_time_monotonic_sec(void);
uint64_t get_time_monotonic_raw_sec(void);
uint64_t get_time_process_sec(void);
uint64_t get_time_thread_sec(void);

/* x86/amd64 counter API */
#if defined(__x86_64__)
uint64_t get_time_x86(void);
uint64_t get_time_x86_serialized(void);
uint64_t get_time_amd64(void);
uint64_t get_time_amd64_serialized(void);
#elif defined(__i386__)
uint32_t get_time_x86(void);
uint32_t get_time_x86_serialized(void);
uint32_t get_time_amd64(void);
uint32_t get_time_amd64_serialized(void);
#endif

/* aarch64 counter API */
#if defined(__aarch64__)
uint64_t get_time_aarch64_physical(void);
uint64_t get_time_aarch64_physical_serialized(void);
uint64_t get_time_aarch64_virtual(void);
uint64_t get_time_aarch64_virtual_serialized(void);
uint64_t get_time_aarch64_performance(void);
#endif

#endif /* _JOKOH_H_ */
