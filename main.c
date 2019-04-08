#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]){
    LOGIN *userlist[100];
    int is_login = 0;
    int menu_id = 0;
    char menu[] = "";

    if(argc != 2){
	printf("Usage : manager <datafile>\n");
	return 0;
    }

    int count = load_file(userlist, argv[1]);

    printf("> Welcome!!\n");
    while(1){
	printf("> ");
	scanf(" %s", menu);

	if(strcmp(menu, "login") == 0){
	    int is_login = login(userlist, count);
	    ask_menu(is_login);
	}
	else if(strcmp(menu, "join") == 0){
	    join(userlist, count);
	    count++;
	    save_file(userlist, count, argv[1]);
	}
	else if(strcmp(menu, "list") == 0){
	    load_file(userlist, argv[1]);
	    list_members(userlist, count);
	}
	else if(strcmp(menu, "exit") == 0){
	    return -1;
	    break;
	}
	else{
	    printf("No such command!\n");
	}
    }
    save_file(userlist, count, argv[1]);
    return 0;
}
