#include <stdio.h>

  int main()
  {
	FILE *pf;
	char buffer[4096];
	
	pf = popen("gradle -version", "r");
	fread(buffer, sizeof(buffer), 1, pf);
	
	printf("%s\n", buffer);

	pclose(pf);
	return 0;

  }
