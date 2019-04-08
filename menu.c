#include "menu.h"
#include <string.h>

void ask_menu(int is_login){
    char menu[] = "";
    if(is_login == 1){
	while(1){
	    printf("# ");
	    scanf(" %s", menu);
	    if(strcmp(menu, "logout") == 0){
#ifdef DEBUG_MODE
		printf("Bye!!");
#endif
		break;
	    }
	    else printf("%s\n", menu);
	}
    }
}

