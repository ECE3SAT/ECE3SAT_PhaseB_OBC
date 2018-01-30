#ifndef USER_CODE_main
#define USER_CODE_main

enum RoleMC{
	OBC=1,
	ADCS=2,
	TCS=3,
    EDT=4
};

void startup_roledetect();
void classobc_init();
void classedt_init();
void classtcs_init();
void classadcs_init();


#endif
