/* 
 * File:   main.c
 * Author: huibin
 *
 * Created on February 12, 2014, 7:26 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    
    FILE *pf;
	char buffer[4096];
		
	pf = popen("gradle build -p /home/huibin/android/project/SnailIM", "r");
	while (fread(buffer, sizeof(buffer), 1, pf))
        {
            printf("%s\n", buffer);
        }
        
        printf("%s\n", "BUILD SUCCESSFUL");
        
	memset(buffer,'\0', sizeof(buffer));
	
	pf = popen("adb uninstall com.snail.im", "r");
        while (fread(buffer, sizeof(buffer), 1, pf))
        {
            printf("%s\n", buffer);
        }
        
        printf("%s\n", "APK UNINSTALL SUCCESSFUL");
        
        pf = popen("adb install /home/huibin/android/project/SnailIM/IM/build/apk/IM-playstore-release.apk", "r");
        while (fread(buffer, sizeof(buffer), 1, pf))
        {
            printf("%s\n", buffer);
        }
        
        printf("%s\n", "APK INSTALL SUCCESSFUL");
        printf("%s\n", "---complete---");

    return (EXIT_SUCCESS);
}

