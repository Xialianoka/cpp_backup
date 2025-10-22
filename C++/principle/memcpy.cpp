#include <cassert>
#include <cstddef>
#include <cstdio>

void* memcpy(void* dest, const void* src, size_t n) {
  assert(dest != nullptr && src != nullptr);
  if (dest == src || n == 0) return dest;
  char* d = static_cast<char*>(dest);
  const char* s = static_cast<const char*>(src);

  if (d > s && d < s + n) {
    d += n;
    s += n;
    while (n--) {
      *d-- = *s--;
    }
  } else {
    while (n--) {
      *d++ = *s++;
    }
  }
  return dest;
}

int main() {
  char str1[10] = "Hello, ";
  char str2[10] = "World!";
  memcpy(str1 + 7, str2, 7);
  printf("%s\n", str1);
  return 0;
}