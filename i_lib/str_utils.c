#include <stdint.h>
#include "../i_lib/i_lib.h"
#include "../i_lib/str_utils.h"

void util_zero(void *buf, size_t size)
{
    size_t x;
    for(x = 0; x < size; x++)
    {
        ((unsigned char *)buf)[x] = 0;
    }
}

int util_strlen(void *buf)
{
    int x = 0;
    while(((unsigned char *)buf)[x] != 0)
    {
        x++;
    }
    return x;
}

void util_memcpy(void *buf0, void *buf1, int len)
{
    char *pszDest = (char *)buf0;
    const char *pszSource = (const char *)buf1;
    if((pszDest != NULL) && (pszSource != NULL))
    {
        while(len) //till cnt
        {
            //Copy byte by byte
            *(pszDest++) = *(pszSource++);
            --len;
        }
    }
}

void util_strreverse(unsigned char *str)
{
    int start = 0;
    int end = util_strlen(str)-1;
    while (start < end)
    {
        char tmpc = str[end];
        str[end] = str[start];
        str[start] = tmpc;
        start++;
        end--;
    }
}

void util_strcpy(void *buf0, void *buf1)
{
    int buf1_len = util_strlen(buf1);
    util_zero(buf0, util_strlen(buf0));
    util_memcpy(buf0, buf1, buf1_len);
}

void util_strcat(void *buf0, void *buf1)
{
    int buf0_len = util_strlen(buf0);
    int buf1_len = util_strlen(buf1);
    util_memcpy(buf0+buf0_len, buf1, buf1_len);
}

int util_strmatch(unsigned char *buf0, unsigned char *buf1)
{
    int buf0_len = util_strlen(buf0);
    int buf1_len = util_strlen(buf1);
    int curr_pos = 0;//our current position in main string
    int found_count = 0;// how many characters found so far

    if(buf0_len != buf1_len)
    {
        return 0;// 0 means no match
    }

    for(curr_pos = 0; curr_pos < buf0_len; curr_pos++)
    {
        if(buf0[curr_pos] == buf1[curr_pos])
        {
            found_count++;
        }
        else
        {
            break;
        }
    }

    if(found_count == buf0_len)
    {
        return 1;
    }

    return 0;
}

int util_strexists(unsigned char *haystack, unsigned char *needle)
{
    int haystack_len = util_strlen(haystack);
    int needle_len = util_strlen(needle);
    int curr_pos = 0;
    int found_count = 0;

    if(needle_len > haystack_len)
    {
        return 0;// 0 means no match
    }

    for(curr_pos = 0; curr_pos < haystack_len; curr_pos++)
    {
        if(haystack[curr_pos] == needle[curr_pos])
        {
            found_count++;
            if(found_count >= needle_len)
            {
                return curr_pos+1;// anything above 0 ~ +1 because if found at 0 it would mean failure
            }
        }
        else
        {
            found_count = 0;
        }
    }

    return 0;// 0 means no match
}

int util_chrexists(unsigned char *haystack, unsigned char needle)
{
    int haystack_len = util_strlen(haystack);
    int curr_pos = 0;
    for(curr_pos = 0; curr_pos < haystack_len; curr_pos++)
    {
        if(haystack[curr_pos] == needle)
        {
            return curr_pos+1;
        }
    }
    return 0;
}

unsigned char *util_itoa(int num, unsigned char *str, int base)
{
    int i = 0;
    uint8_t isNegative = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative == 1)
        str[i++] = '-';
    str[i] = '\0';
    util_strreverse(str);
    return str;
}

int util_strprintf_ex(char *str, char *format, uint32_t format_len, va_list args)
{
    uint32_t str_len = 0;
    uint32_t x = 0;

    //search format string for format specifiers (%s,%d,%i)
    for(x = 0; x < format_len; x++)
    {
        if(format[x] != '%')// normal character. Print to string
        {
            str[str_len] = format[x];
            str_len++;
            continue;
        }
        else// found format specifier... check of which type
        {
            x++;
            if(format[x] == 's') // print out character array from va_list
            {
                char *arg_str = (char *)va_arg(args, char *);
                int arg_str_len = util_strlen(arg_str);
                int j;
                for(j = 0; j < arg_str_len; j++)
                {
                    str[str_len] = arg_str[j];
                    str_len++;
                }
                continue;
            }
            else if(format[x] == 'd' || format[x] == 'i')// print out whole number integer from va_list
            {
                int arg_int = (int)va_arg(args, int);
                unsigned char arg_int_str[16];
                util_itoa(arg_int, arg_int_str, 10);
                int arg_int_str_len = util_strlen(arg_int_str);
                int j;
                for(j = 0; j < arg_int_str_len; j++)
                {
                    str[str_len] = arg_int_str[j];
                    str_len++;
                }
                continue;
            }
            else if(format[x] == '%')// we want to print out a '%'
            {
                str[str_len] = '%';
                str_len++;
                continue;
            }
            else // no type of format specified so print out '%E'
            {
                str[str_len] = '%';
                str_len++;
                str[str_len] = 'E';
                str_len++;
                continue;
            }
        }
    }
    return str_len;
}

int util_strprintf(char *str, char *format, ...)
{
    register int x;
    int str_len = 0;
    int format_len = util_strlen(format);
    util_zero(str, util_strlen(str));

    va_list args;
    va_start(args, format);
	
	str_len = util_strprintf_ex(str, format, format_len, args);

    va_end(args);

    return str_len;
}

uint8_t util_bytematch(uint8_t *bytes0, uint8_t *bytes1, uint16_t len)
{
    int j;
    for(j = 0; j < len; j++)
    {
        if(bytes0[j] != bytes1[j])
        {
            return 0;
        }
    }
    return 1;
}

void util_parse_u8(uint8_t *out, unsigned char *buffer, int *pos)
{
    int ppos = 0;
    if(pos != NULL)
    {
        ppos = *pos;
    }
    *out = *(uint8_t *)buffer+ppos;
    if(pos != NULL)
    {
        *pos += sizeof(uint8_t);
    }
}

void util_parse_u16(uint16_t *out, unsigned char *buffer, int *pos)
{
    int ppos = 0;
    if(pos != NULL)
    {
        ppos = *pos;
    }
    *out = *(uint16_t *)buffer+ppos;
    if(pos != NULL)
    {
        *pos += sizeof(uint16_t);
    }
}

void util_parse_u32(uint32_t *out, unsigned char *buffer, int *pos)
{
    int ppos = 0;
    if(pos != NULL)
    {
        ppos = *pos;
    }
    *out = *(uint32_t *)buffer+ppos;
    if(pos != NULL)
    {
        *pos += sizeof(uint32_t);
    }
}

void util_parse_ip(uint8_t *out, unsigned char *buffer, int *pos)
{
    int ppos = 0;
    if(pos != NULL)
    {
        ppos = *pos;
    }
    int j;
    for(j = 0; j < 4; j++)
    {
        util_parse_u8(&(out[j]), buffer, &ppos);
    }
    if(pos != NULL)
    {
        *pos = ppos;
    }
}

/*
in_addr_t util_convert_ip(uint8_t *addrs, uint8_t addrs_len)
{
    unsigned char host[16], tmp_class[4];
    int j;

    if(addrs_len != 4) return 0;

    util_zero(host, 16);
    util_zero(tmp_class, 4);

    for(j = 0; j < 4; j++)
    {
        util_itoa(addrs[j], tmp_class, 10);
        util_strcpy(host+util_strlen(host), tmp_class);
        if(j < 3) {
            util_strcpy(host+util_strlen(host), ".");
        }
        util_zero(tmp_class, 4);
    }

    return inet_addr((const char *)host);
}
*/
