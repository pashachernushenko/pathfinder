#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0)
        return -2;

    static char *buff;
    int buf_pos = 0, line_pos = 0;
    //clean lineptr
    for (int i = 0; (*lineptr)[i] != '\0'; i++)
        (*lineptr)[i] = '\0';
    //read from buff
    while (buff == NULL || buff[buf_pos] != delim) {
        //fill buffer
        if (buff == NULL || *buff == '\0') {
            buff = mx_strnew(buf_size);
            if(!read(fd, buff, buf_size))
                return line_pos;
        }
        //copy char
        if (buff[buf_pos] != delim)
            (*lineptr)[line_pos++] = buff[buf_pos++];
        else
            break;

        //free buffer if ended
        if (buff[buf_pos] == '\0') {
            buf_pos = 0;
            mx_strdel(&buff);
        }
    }
    //advance buffer
    char *temp = mx_strdup(&buff[buf_pos+1]);
    mx_strcpy(buff, temp);
    mx_strdel(&temp);
return line_pos;
}

// #include <stdio.h>

// int main (void) {
//     int fd = open("test.txt", O_RDONLY);
//     char *lineptr = mx_strnew(200);
//     int cnt = 0;
    
//     cnt = mx_read_line(&lineptr, 7, '\n', fd);
//     printf("Output 1:\nres = %d\n%s\n", cnt, lineptr);
//     cnt = mx_read_line(&lineptr, 35, 'a', fd);
//     printf("Output 2:\nres = %d\n%s\n", cnt, lineptr);
//     cnt = mx_read_line(&lineptr, 1, '.', fd);
//     printf("Output 3:\nres = %d\n%s\n", cnt, lineptr);
//     cnt = mx_read_line(&lineptr, 10, 'c', fd);
//     printf("Output 4:\nres = %d\n%s\n", cnt, lineptr);
//     cnt = mx_read_line(&lineptr, 20, 't', fd);
//     printf("Output 5:\nres = %d\n%s\n", cnt, lineptr);
//     cnt = mx_read_line(&lineptr, 20, 't', fd);
//     printf("Output 5:\nres = %d\n%s\n", cnt, lineptr);
//     return 0;
// }
