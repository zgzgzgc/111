#include "cstring.h"

namespace sdds {
	const char nullter = '\0';
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int size;
		for (size = 0; src[size] != nullter; size++) {
			des[size] = src[size];
		};

		des[size] = nullter;
	}
	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int size = 0;

		while(size < len && src[size] != nullter)
		{
			des[size] = src[size];
			size++;
		}
		if (size < len)
		{
			des[size] = nullter;
		}
	}
	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int len = 0;
		while (s1[len] == s2[len] && (s1[len] != nullter || s2[len] != nullter))
		{
			len++;
		}
		return (s1[len] - s2[len]);
	}
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		for (int size = 0; size < len && (s1[size] != nullter || s2[size] != nullter); size++)
		{
			if (s1[size] != s2[size])
			{
				return (s1[size] - s2[size]);
			}
		}
		return 0;
	}
	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int len = 0;
		while (s[len] != nullter) {
			len++;
		}
		return len;
	}
	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2) {
		const char* faddress = nullptr;

		for (int len1 = 0; str1[len1] != nullter; len1++) {
			for (int len2 = 0; str1[len1 + len2] == str2[len2]; len2++) 
			{
				if (str2[len2 + 1] == nullter) {
					faddress = &str1[len1];
					return faddress;
				}
			}
		}
		return faddress;
	}
	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int len1 = 0;
		while (des[len1] != nullter) {
			len1++;
		}
		int len2 = 0;
		while (src[len2] != nullter) {
			des[len1 + len2] = src[len2];
			len2++;
		}
		des[len1+len2] = nullter;
	}
};