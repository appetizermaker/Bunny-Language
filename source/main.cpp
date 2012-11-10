
#include <stdio.h>

#include "BunnyLanguage.h"


using namespace bunny_language;

int main()
{
	// TODO test
	FILE *fp;
	fp = fopen("test.txt", "wb");
	fclose(fp);

	BunnyLanguage bunny;
	bunny.run("resource/test.bny");

	return 0;
}
