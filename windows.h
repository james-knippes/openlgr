#ifndef __OPENSWE1R_WINDOWS_H__
#define __OPENSWE1R_WINDOWS_H__

#include <stdint.h>

#include "emulation.h"

typedef uint32_t API(DWORD);
typedef uint16_t API(WORD);
typedef void API(VOID);

typedef uint32_t API(UINT); // FIXME: Assumption
typedef int16_t API(SHORT); // FIXME: Assumption
typedef uint8_t API(CHAR);
typedef uint8_t API(BYTE);

typedef struct {
  uint32_t Data1;
  uint16_t Data2;
  uint16_t Data3;
  uint8_t Data4[8];
} API(GUID);
typedef API(GUID) API(CLSID);
typedef API(GUID) API(IID);

typedef struct {
  uint32_t bmType;
  uint32_t bmWidth;
  uint32_t bmHeight;
  uint32_t bmWidthBytes;
  uint16_t bmPlanes;
  uint16_t bmBitsPixel;
  Address bmBits;
} API(BITMAP);

typedef API(DWORD) API(COLORREF);

typedef uint32_t API(SIZE_T);

typedef struct {
  API(DWORD) dwLowDateTime;
  API(DWORD) dwHighDateTime;
} API(FILETIME);

#define API__MAX_PATH 260

typedef char API(TCHAR);
typedef struct {
  API(DWORD)    dwFileAttributes;
  API(FILETIME) ftCreationTime;
  API(FILETIME) ftLastAccessTime;
  API(FILETIME) ftLastWriteTime;
  API(DWORD)    nFileSizeHigh;
  API(DWORD)    nFileSizeLow;
  API(DWORD)    dwReserved0;
  API(DWORD)    dwReserved1;
  API(TCHAR)    cFileName[API(MAX_PATH)];
  API(TCHAR)    cAlternateFileName[14];
} API(WIN32_FIND_DATA);

typedef struct {
  int x;
} API(STR);
typedef Address API(LPTSTR);

typedef struct {
  API(DWORD) dwOSVersionInfoSize;
  API(DWORD) dwMajorVersion;
  API(DWORD) dwMinorVersion;
  API(DWORD) dwBuildNumber;
  API(DWORD) dwPlatformId;
  API(CHAR) szCSDVersion[128]; // TCHAR
  //API(WORD)  wServicePackMajor;
  //API(WORD)  wServicePackMinor;
  //API(WORD)  wSuiteMask;
  //API(BYTE)  wProductType;
  //API(BYTE)  wReserved;
} API(OSVERSIONINFOEX);

enum {
  API(VK_SHIFT) = 0x10,
  API(VK_CONTROL) = 0x11,
  API(VK_MENU) = 0x12,

  API(VK_CAPITAL) = 0x14,

  API(VK_LSHIFT) = 0xA0,
  API(VK_RSHIFT) = 0xA1,
  API(VK_LCONTROL) = 0xA2,
  API(VK_RCONTROL) = 0xA3,
  API(VK_LMENU) = 0xA4,
  API(VK_RMENU) = 0xA5
};

#endif
