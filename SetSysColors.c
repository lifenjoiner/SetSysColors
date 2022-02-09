/*
YX Hao @20160620
MIT license
*/
#include <windows.h>
#include <stdio.h>
#include <conio.h>

int main(int argc, char* argv[]) {
    int element_type[1] = {COLOR_WINDOW};
	typedef struct _SYS_RGB_INFO {
		COLORREF sys_rgb;
		char *desc;
	} SYS_RGB_INFO;
	int i, n;
	int r, g, b;

	//#define RGB(r,g,b) ((COLORREF)((BYTE)(r)|((BYTE)(g) << 8)|((BYTE)(b) << 16)))
    SYS_RGB_INFO sys_rgb_info[10] = {
		{0xFFFFFF, "Stored"}, // store current
        {0xCCEDC7, "¶¹É³ÂÌ"}, // rgb 199 237 204
        {0xCDEDE3, "Çà²ÝÂÌ"}, // rgb 227 237 205
        {0xCCFFCC, "Æ»¹ûÂÌ"}, // rgb 204 255 204
        {0xDEF9FA, "ÐÓÈÊ»Æ"}, // rgb 250 249 222
        {0xE2F2FF, "ÇïÒ¶ºÖ"}, // rgb 255 242 226
        {0xF1E2DC, "¸ð½í×Ï"}, // rgb 220 226 241
        {0xFEEBE9, "º£ÌìÀ¶"}, // rgb 233 235 254
		{0xE4EBEB, "»ÒÉ«"  }, // rgb 235 235 228
		{0xFFFFFF, "Customize"},
    };

    printf("One key to set window background\nlifenjoiner@163.com\n\n");
    
    // Get the current color of the window background.
    sys_rgb_info[0].sys_rgb = GetSysColor(element_type[0]);
    printf("Current RGB: (%d, %d, %d)\n",
        GetRValue(sys_rgb_info[0].sys_rgb),
        GetGValue(sys_rgb_info[0].sys_rgb),
        GetBValue(sys_rgb_info[0].sys_rgb));

	n = sizeof(sys_rgb_info)/sizeof(SYS_RGB_INFO) - 1;
	for (i = 0; i <= n; i++) {
		printf("%d: %s\n", i, sys_rgb_info[i].desc);
	}

    //
    // 0 ~ 9 available!
	printf("Enter Option: ");
	while (i = _getche() - '0', i >= 0) {
		if (i < n) {
			SetSysColors(1, element_type, &sys_rgb_info[i].sys_rgb);
			printf("\b");
		}
		else if (i >= n) {
			printf("\nEnter decimal RGB:\n");
			if (scanf("%d %d %d", &r, &g, &b) == 3) {
				sys_rgb_info[n].sys_rgb = RGB(r, g, b);
				printf("RGB: (%d, %d, %d)\n",
					GetRValue(sys_rgb_info[n].sys_rgb),
					GetGValue(sys_rgb_info[n].sys_rgb),
					GetBValue(sys_rgb_info[n].sys_rgb));
				SetSysColors(1, element_type, &sys_rgb_info[n].sys_rgb);
			}
			else {
				printf("Invalid RGB!\n");
			}
			printf("Enter Option: ");
		}
	}
}
