#include <stdio.h>
#include <stdint.h>

#include "jokoh.h"

int main(void)
{
  uint64_t a = get_time_realtime();
  uint64_t b = get_time_monotonic();
  uint64_t c = get_time_monotonic_raw();
  uint64_t d = get_time_process();
  uint64_t e = get_time_thread();

  uint64_t f = get_time_realtime_sec();
  uint64_t g = get_time_monotonic_sec();
  uint64_t h = get_time_monotonic_raw_sec();
  uint64_t i = get_time_process_sec();
  uint64_t j = get_time_thread_sec();

#if defined(__x86_64__)
  uint64_t k = get_time_x86();
  uint64_t l = get_time_x86_serialized();
  uint64_t m = get_time_amd64();
  uint64_t n = get_time_amd64_serialized();
#elif defined(__i386__)
  uint32_t k = get_time_x86();
  uint32_t l = get_time_x86_serialized();
  uint32_t m = get_time_amd64();
  uint32_t n = get_time_amd64_serialized();
#endif

#if defined(__aarch64__)
  uint64_t k = get_time_aarch64_physical();
  uint64_t l = get_time_aarch64_physical_serialized();
  uint64_t m = get_time_aarch64_virtual();
  uint64_t n = get_time_aarch64_virtual_serialized();
  uint64_t o = get_time_aarch64_performance();
#endif

  printf("realtime                   : %lu\n", a);
  printf("monotonic                  : %lu\n", b);
  printf("monotonic raw              : %lu\n", c);
  printf("process cputime id         : %lu\n", d);
  printf("thread cputime id          : %lu\n", e);

  printf("realtime sec               : %lu\n", f);
  printf("monotonic sec              : %lu\n", g);
  printf("monotonic raw sec          : %lu\n", h);
  printf("process cputime id sec     : %lu\n", i);
  printf("thread cputime id sec      : %lu\n", j);

#if defined(__x86_64__)
  printf("x86                        : %lu\n", k);
  printf("x86 serialized             : %lu\n", l);
  printf("amd64                      : %lu\n", m);
  printf("amd64 serialized           : %lu\n", n);
#elif defined(__i386__)
  printf("x86                        : %u\n", k);
  printf("x86 serialized             : %u\n", l);
  printf("amd64                      : %u\n", m);
  printf("amd64 serialized           : %u\n", n);
#endif

#if defined(__aarch64__)
  printf("aarch64 physical           : %lu\n", k);
  printf("aarch64 physical serialized: %lu\n", l);
  printf("aarch64 virtual            : %lu\n", m);
  printf("aarch64 virtual serialized : %lu\n", n);
  printf("aarch64 performance        : %lu\n", o);
#endif

  return 0;
}
