#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ������Ϣ�ַ�����
const char *help = "���������ڴ�\n"
"\n"
"��ʾ������������򽫵������ϵͳ�𽥺ľ������ڴ棬���տ��ܷ����ڴ�й©������ϵͳ���ȶ����������ˣ����ڰ�ȫ�Ĳ��Ի��������У���ȷ��������ʱ��ֹ�����رջ�����\n"
"\n"
"�÷���\n"
"    ramleaker [ /help | /ram <��С> | /count <����> | /sleep <ʱ��> | /e_exit | /about]\n"
"\n"
"ѡ�\n"
"\n"
"   �޲��� ��ӡ������Ϣ\n"
"   /help ��ӡ������Ϣ\n"
"   /ram <��С> �����ڴ����Ĵ�С����λΪMB����δָ����Ϊ1MB\n"
"   /count <����> ����ѭ�������ڴ�Ĵ�������δָ����Ϊ����ѭ��\n"
"   /sleep <ʱ��> ����ÿ�������ڴ����ͣ��ʱ�䣬��λΪ�룬��δָ����Ϊ1��\n"
"   /e_exit ���ڴ����ʧ��ʱ�˳�����\n"
"   /about ��ӡ������Ϣ\n"
"\n"
"\n"
"Ϊ����ȫ����Ӧ����ָ��һ�����������򽫴�ӡ������Ϣ��\n"
"Ҫ��ֹ�����ͷ��ڴ棬�밴 Ctrl + C ����\n"
"\n"
"ʾ����\n"
"    ramleaker\n"
"    ramleaker /ram 1024\n"
"    ramleaker /count 1000\n"
"    ramleaker /sleep 2 /e_exit\n"
"    ramleaker /ram 10 /count 1000 /sleep 2\n"
"\n\nabababababababababa,FBI WARNNNNNNNNNBYNADMIN-CMDDDDDDDDDDDDDamlCC-BA-NS-SA4.0klklhttps://github.com/admincmd-a/BiliBili-ContentSourceCode/tree/ramleaker [ddddddddddddhttp://admincmd.xyz/ ddddddd]-klklklurl:hklklklklklklklk,sc,China,Chinese MADE IN CHINA,ssssAA HUBEI.ING Ⱥ��Ŀ���������𣬿��ҿ��ң���Ѳ����ʽ������ʫ��";
;

const char *about = 
"ramleaker ��һ�����������ڴ�ĳ������ڲ���ϵͳ���ڴ�й©�Ĳ��Գ���\n"
"Copyright (C) 2021-2025 ����Ա - ������ʾ��(Admincmd)\n"
"Github: https://github.com/admincmd-a/BiliBili-ContentSourceCode/tree/ramleaker\n"
"=================================================================\n"
"��Ҫ�����ߣ�\n"
"----- ����Ա - ������ʾ��(Admincmd)\n"
"---------- Github: https://github.com/admincmd-a\n"
"---------- BiliBili: https://space.bilibili.com/518747636\n"
"=================================================================\n"
"����������\n"
"----- �û���ʹ��ramleaker��������һ�к�����û����ге����κ��漰ramleaker�ķ��ɾ������ͻ�뿪�����޹أ�ramleaker�뿪���߽����е��κ����Ρ�\n"
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
"\n\nabababababababababa,FBI WARNNNNNNNNNBYNADMIN-CMDDDDDDDDDDDDDamlklklhttps://github.com/admincmd-a/ramleaker/ [ddddddddddddhttp://admincmd.xyz/ ddddddd]-klklklurl:hklklklklklklklk,sc,China,Chinese MADE IN CHINA,ssssAA HUBEI.ING Ⱥ��Ŀ���������𣬿��ҿ��ң���Ѳ����ʽ������ʫ��";
*/

int ram = 1; // Ĭ�Ϸ���1MB�ڴ�
int count = 0; // Ĭ������ѭ�������ڴ�
int sleep_time = 1; // Ĭ��ÿ�������ڴ����ͣ1��
int e_exit = 0; // Ĭ�ϲ��˳�����


int main(int argc, char *argv[]) {
    if (argc == 1) {// �ȿ���ʱ��ʱɶ��ð��
        printf("%s\n", help);
        return 0;
    }
    // ���������в���
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "/help") == 0) {
            printf("%s\n", help);
            return 0;// ��2���ǲ��ǰ�������
        } else if (strcmp(argv[i], "/about") == 0) {
            printf("%s\n", about);
            return 0;
        } else if (strcmp(argv[i], "/ram") == 0) {// ����Ƿ���RAM����
            if (i + 1 < argc) {
                ram = atoi(argv[i + 1]); // �ɹ���ֵ
                i++;// ��2��������
            } else {
                fprintf(stderr, "ERROR: /ram û����Ч����\n�����롮/help����ȡ������Ϣ\n");//��������ӵ�Ч����֪�û��󷵻�
                return 1;
            }
        } else if (strcmp(argv[i], "/count") == 0) {
            if (i + 1 < argc) {
                count = atoi(argv[i + 1]);
                i++;
            } else {
                fprintf(stderr, "ERROR: /count û����Ч����\n�����롮/help����ȡ������Ϣ\n");
                return 1;
            }
        } else if (strcmp(argv[i], "/sleep") == 0) {
            if (i + 1 < argc) {
                sleep_time = atoi(argv[i + 1]);
                i++;
            } else {
                fprintf(stderr, "ERROR: /sleep û����Ч����\n�����롮/help����ȡ������Ϣ\n");
                return 1;
            }
        } else if (strcmp(argv[i], "/e_exit") == 0) {
            e_exit = 1;
        } else {
            fprintf(stderr, "��Ч�Ĳ��� \n�����롮/help����ȡ������Ϣ\n", argv[i]); // �������д���������ģ��͡���
            return 1;
        }
    }

    // ѭ�������ڴ棬ֱ���ﵽָ���Ĵ���
    int allocated_count = 0;
    while (count == 0 || allocated_count < count) {
        //char **ramName = realloc(ramName, sizeof(void*) * (allocated_count + 1)); // �ڴ�ָ��
        void *ptr = malloc(ram * 1024 * 1024);
        //ramName[allocated_count] = ptr;
        if (ptr == NULL) { // �������ֵΪ�գ��ͱ�����
            fprintf(stderr, "ERROR: �ڴ�����ʧ��\n");
            if (e_exit) {// ����Ƿ���Ҫ�˳�
                return 1;
            }
            // ���쳢�Է����ڴ�
        } else {
            printf("�ѳɹ����뵽%dMB�ڴ�: �ڴ�ָ�룺%p\n", ram, ptr);
            // ʹ�� memset ��������ڴ�����
            /* ������ﲻ���Ļ���������ڴ�ֻ�ύ�ˣ�û��ʵ��ʹ�ã�������ϵͳ���ڴ�ʹ���������޷�����ϵͳ��
             * Ҫ�����Ļ������ܴﵽ�ڴ�й©��Ч������ϵͳ���ȶ�������
             */
            memset(ptr, 0xFF, ram * 1024 * 1024);// ��������ڴ�װ��0xFF
            allocated_count++;
        }
        sleep(sleep_time);// �ӳٲ���ʱ��
    }

    printf("��������%d���ڴ棬�����˳�\n", allocated_count);
    return 0;
}