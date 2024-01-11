/**
 * Description: Stimulation of Linux 'cd' command
 * 
 * Author: flew_kites
 * University: Xidian University
 * Date: 2024/1/11
 * Source: xdoj-T84
 * 
 * ---Usages---
 * In the first input, you should input the initial directory.
 * Then you can execute cd command.
 * Type 'pwd' to print current directory and terminate the program.
 * 
 * Command pwd: print current directory
 * - pwd: print current directory
 * 
 * Command cd: change directory
 * - cd dir1/dir2: go to relative path
 * - cd /path/to/dir: go to absolute path
 * - cd /: go to root directory
 * - cd ..: go to parent directory
 * ---/Usages---
 * 
 * ---Example---
 * (FULL_MODE = 0)
 * Input1: /d2/d3/d7
 * Input2: cd ..
 * Input3: cd /
 * Input4: cd /d1/d6
 * Input5: cd d4/d5
 * Input6: pwd
 * 
 * Output: /d1/d6/d4/d5
 * (Program terminated due to FULL_MODE = 0)
 * ---/Example---
 * 
 * ---Full Mode---
 * If you want to use this program in full mode, you can define FULL_MODE as 1.
 * In full mode, the program will work more like a Linux shell.
 * For example:
 * - You can see the username and hostname in the prompt, default is 'kites@Linux'
 * - You can type 'pwd' to print current directory and continue to input.
 * ---/Full Mode---
*/

#define FULL_MODE 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void pwd(bool has_newline);
void cd(char *path);

char dir[100][100];
int dir_num = 0;

int main(){
    char user[100] = "";
    char initDir[100] = "/";
    char* command_pwd = "pwd";
    char* command_cd = "cd";

    scanf("%s", initDir);
    cd(initDir);
    getchar();

    while(1){
        if(FULL_MODE){
            printf("kites@Linux:");
            pwd(false);
            printf("$ ");
        }

        scanf("%[^\n]", user);
        getchar();
        
        if(strncmp(user, command_pwd, 3) == 0){
            pwd(true);
            if(!FULL_MODE) break;
        }else if(strncmp(user, command_cd, 2) == 0){
            cd(user + 3);
        }else{
            printf("Invalid command!\n");
        }
    }

    return 0;
}

void pwd(bool has_newline){
    if(dir_num == 0){
        printf("/");
    }else{
        for(int i = 0; i < dir_num; i++){
            printf("/%s", dir[i]);
        }
    }

    if(has_newline){
        printf("\n");
    }
}

void cd(char *path){
    if(strncmp(path, "..", 2) == 0){
        if(dir_num != 0){
            dir_num--;
        }
        return;
    }
    
    if(strncmp(path, "/", 1) == 0){
        dir_num = 0;
        path++;
    }

    char* token = strtok(path, "/");
    while(token != NULL){
        strcpy(dir[dir_num++], token);
        token = strtok(NULL, "/");
    }
}