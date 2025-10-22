#include <cassert>
#include <cstddef>
#include <cstdio>
#include <iostream>

void* memcpy(void* dest, const void* src, size_t n) {
  assert(dest != nullptr && src != nullptr);
  if (dest == src || n == 0) return dest;
  uintptr_t d_uint = (uintptr_t)dest;
  uintptr_t s_uint = (uintptr_t)src;
  size_t align = sizeof(unsigned long);

  // 拷贝非对齐部分
  while (n && (d_uint % align != s_uint % align)) {
    *(char*)d_uint = *(char*)s_uint;
    d_uint++;
    s_uint++;
    n--;
  }

  // 按字长拷贝
  unsigned long* d_word = (unsigned long*)d_uint;
  const unsigned long* s_word = (const unsigned long*)s_uint;
  while (n >= align) {
    *d_word++ = *s_word++;
    n -= align;
  }

  // 处理剩余部分
  char* d_byte = (char*)d_word;
  char* s_byte = (char*)s_word;
  while (n--) {
    *d_byte++ = *s_byte++;
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