#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 帮助信息字符串，
const char *help = "持续申请内存\n"
"\n"
"警示：运行这个程序将导致你的系统逐渐耗尽可用内存，最终可能发生内存泄漏，导致系统不稳定或崩溃。因此，请在安全的测试环境中运行，并确保可以随时中止程序或关闭环境。\n"
"\n"
"用法：\n"
"    ramleaker [ /help | /ram <大小> | /count <次数> | /sleep <时间> | /e_exit | /about]\n"
"\n"
"选项：\n"
"\n"
"   无参数 打印帮助信息\n"
"   /help 打印帮助信息\n"
"   /ram <大小> 设置内存分配的大小，单位为MB，若未指定，为1MB\n"
"   /count <次数> 设置循环申请内存的次数，若未指定，为无限循环\n"
"   /sleep <时间> 设置每次申请内存后暂停的时间，单位为秒，若未指定，为1秒\n"
"   /e_exit 在内存分配失败时退出程序\n"
"   /about 打印关于信息\n"
"\n"
"\n"
"为保安全，您应至少指定一个参数，否则将打印帮助信息。\n"
"要终止程序并释放内存，请按 Ctrl + C 键。\n"
"\n"
"示例：\n"
"    ramleaker\n"
"    ramleaker /ram 1024\n"
"    ramleaker /count 1000\n"
"    ramleaker /sleep 2 /e_exit\n"
"    ramleaker /ram 10 /count 1000 /sleep 2\n"
"\n\nabababababababababa,FBI WARNNNNNNNNNBYNADMIN-CMDDDDDDDDDDDDDamlCC-BA-NS-SA4.0klklhttps://github.com/admincmd-a/BiliBili-ContentSourceCode/tree/ramleaker [ddddddddddddhttp://admincmd.xyz/ ddddddd]-klklklurl:hklklklklklklklk,sc,China,Chinese MADE IN CHINA,ssssAA HUBEI.ING 群体目光向往看起，看我看我，我巡捕格式，我是诗歌";
;

const char *about = 
"ramleaker 是一个持续申请内存的程序，用于测试系统的内存泄漏的测试程序。\n"
"Copyright (C) 2021-2025 管理员 - 命令提示符(Admincmd)\n"
"Github: https://github.com/admincmd-a/BiliBili-ContentSourceCode/tree/ramleaker\n"
"=================================================================\n"
"主要开发者：\n"
"----- 管理员 - 命令提示符(Admincmd)\n"
"---------- Github: https://github.com/admincmd-a\n"
"---------- BiliBili: https://space.bilibili.com/518747636\n"
"=================================================================\n"
"免责声明：\n"
"----- 用户因使用ramleaker而产生的一切后果由用户自行承担，任何涉及ramleaker的法律纠纷与冲突与开发者无关，ramleaker与开发者将不承担任何责任。\n"
"\n"
;
/*
"Continuous memory requests lead to memory leaks\n"
"\n"
"WARNING: Running this program will cause your system to gradually run out of available memory, which may eventually lead to system instability or crash. Therefore, please run it in a secure test environment and make sure that you can abort the program or shut down the environment at any time. \n"
"\n"
"Usage: \n"
"   ramleaker [/help | /ram <size> | /count <times> | /sleep <time> | /e_exit]\n"
"\n"
"Options: \n"
"\n"
"   No arguments Print help information \n \n"
"   /help            Print help information \n \n"
"   /ram <size>      Set the size of memory allocation in MB, if not specified, 1MB\n \n"
"   /count <count>   Set the number of times to cycle through memory requests, if not specified, it is an infinite cycle\n \n"
"   /sleep <time>    Set the time to pause after each memory request in seconds, if not specified, 1 second\n \n"
"   /e_exit          Exit the program when memory allocation fails\n \n"
"\n"
"Example: \n"
"   ramleaker\n"
"   ramleaker /ram 1024\n"
"   ramleaker /count 1000\n"
"   ramleaker /sleep 2\n"
"   ramleaker /ram 10 /count 1000 /sleep 2\n"
"\n\nabababababababababa,FBI WARNNNNNNNNNBYNADMIN-CMDDDDDDDDDDDDDamlklklhttps://github.com/admincmd-a/ramleaker/ [ddddddddddddhttp://admincmd.xyz/ ddddddd]-klklklurl:hklklklklklklklk,sc,China,Chinese MADE IN CHINA,ssssAA HUBEI.ING 群体目光向往看起，看我看我，我巡捕格式，我是诗歌";
*/

int ram = 1; // 默认分配1MB内存
int count = 0; // 默认无限循环申请内存
int sleep_time = 1; // 默认每次申请内存后暂停1秒
int e_exit = 0; // 默认不退出程序


int main(int argc, char *argv[]) {
    if (argc == 1) {// 先康康时不时啥都冒得
        printf("%s\n", help);
        return 0;
    }
    // 解析命令行参数
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "/help") == 0) {
            printf("%s\n", help);
            return 0;// 第2串是不是帮助参数
        } else if (strcmp(argv[i], "/about") == 0) {
            printf("%s\n", about);
            return 0;
        } else if (strcmp(argv[i], "/ram") == 0) {// 检查是否是RAM参数
            if (i + 1 < argc) {
                ram = atoi(argv[i + 1]); // 成功则赋值
                i++;// 第2串检查完毕
            } else {
                fprintf(stderr, "ERROR: /ram 没有有效参数\n请输入‘/help’获取帮助信息\n");//如果参数冇得效，告知用户后返回
                return 1;
            }
        } else if (strcmp(argv[i], "/count") == 0) {
            if (i + 1 < argc) {
                count = atoi(argv[i + 1]);
                i++;
            } else {
                fprintf(stderr, "ERROR: /count 没有有效参数\n请输入‘/help’获取帮助信息\n");
                return 1;
            }
        } else if (strcmp(argv[i], "/sleep") == 0) {
            if (i + 1 < argc) {
                sleep_time = atoi(argv[i + 1]);
                i++;
            } else {
                fprintf(stderr, "ERROR: /sleep 没有有效参数\n请输入‘/help’获取帮助信息\n");
                return 1;
            }
        } else if (strcmp(argv[i], "/e_exit") == 0) {
            e_exit = 1;
        } else {
            fprintf(stderr, "无效的参数 \n请输入‘/help’获取帮助信息\n", argv[i]); // 如果参数写的乱起八糟的，就……
            return 1;
        }
    }

    // 循环分配内存，直到达到指定的次数
    int allocated_count = 0;
    while (count == 0 || allocated_count < count) {
        //char **ramName = realloc(ramName, sizeof(void*) * (allocated_count + 1)); // 内存指针
        void *ptr = malloc(ram * 1024 * 1024);
        //ramName[allocated_count] = ptr;
        if (ptr == NULL) { // 如果返回值为空，就报个错
            fprintf(stderr, "ERROR: 内存申请失败\n");
            if (e_exit) {// 检查是否需要退出
                return 1;
            }
            // 据徐尝试分配内存
        } else {
            printf("已成功申请到%dMB内存: 内存指针：%p\n", ram, ptr);
            // 使用 memset 将申请的内存块填充
            /* 如果这里不填充的话，申请的内存只提交了，没有实际使用，不计入系统的内存使用量，就无法整崩系统了
             * 要是填充的话，就能达到内存泄漏的效果，让系统不稳定、崩溃
             */
            memset(ptr, 0xFF, ram * 1024 * 1024);// 把申请的内存装满0xFF
            allocated_count++;
        }
        sleep(sleep_time);// 延迟参数时间
    }

    printf("已申请完%d次内存，程序退出\n", allocated_count);
    return 0;
}