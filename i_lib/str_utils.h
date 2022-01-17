#pragma once

#include <stdint.h>
#include <stdargs.h>

void util_zero(void *buf, size_t size);
int util_strlen(void *buf);
void util_memcpy(void *buf0, void *buf1, int len);
void util_strreverse(unsigned char *str);
void util_strcpy(void *buf0, void *buf1);
void util_strcat(void *buf0, void *buf1);
int util_strmatch(unsigned char *buf0, unsigned char *buf1);
int util_strexists(unsigned char *haystack, unsigned char *needle);
int util_chrexists(unsigned char *haystack, unsigned char needle);
unsigned char *util_itoa(int num, unsigned char *str, int base);// use base 10 for int, 16 for hex...
int util_strprintf_ex(char *str, char *format, uint32_t format_len, va_list args);
int util_strprintf(char *str, char *format, ...);
uint8_t util_bytematch(uint8_t *bytes0, uint8_t *bytes1, uint16_t len);
void util_parse_u8(uint8_t *out, unsigned char *buffer, int *pos);
void util_parse_u16(uint16_t *out, unsigned char *buffer, int *pos);
void util_parse_u32(uint32_t *out, unsigned char *buffer, int *pos);
void util_parse_ip(uint8_t *out, unsigned char *buffer, int *pos);
//in_addr_t util_convert_ip(uint8_t *addrs, uint8_t addrs_len);
