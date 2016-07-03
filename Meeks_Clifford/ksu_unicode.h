#ifndef KSU_UNICODE_H
#define KSU_UNICODE_H
#ifdef __cplusplus
extern "C"
{
#endif

extern unsigned int ksu_unicode_lower(const unsigned int cp);
extern unsigned int ksu_unicode_upper(const unsigned int cp);
extern unsigned int ksu_unicode_strip_accent(const unsigned int cp);
extern unsigned int ksu_hex_to_codepoint(const char *hex);

#ifdef __cplusplus
}
#endif

#endif
