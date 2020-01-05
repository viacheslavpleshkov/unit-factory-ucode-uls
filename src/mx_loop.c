#include "uls.h"
//объясню позже
void mx_loop(char *direct, char **inp_files, char *opt) {
    // // struct stat buf;
    // // struct passwd *pwd;
    // // struct group *grp;
    // acl_t aclm;
    // const char data[] = "main.c"; 

    // // lstat(data, &buf);
    // // printf("ltest1\n");
    // // printf("st_dev: %d\n", buf.st_dev);
    // // printf("st_ino: %llu\n", buf.st_ino);
    // // printf("st_mode: %hu\n", buf.st_mode);
    // // printf("st_nlink: %u\n", buf.st_nlink);
    // // printf("st_uid: %d\n", buf.st_uid);
    // // printf("st_gid: %u\n", buf.st_gid);
    // // printf("st_rdev: %d\n", buf.st_rdev);
    // // printf("st_size: %lld\n", buf.st_size);
    // // printf("st_blksize: %d\n", buf.st_blksize);
    // // printf("st_blocks: %lld\n", buf.st_blocks);
    // // printf("st_atime: %ld\n", buf.st_atime);
    // // printf("st_mtime: %ld\n", buf.st_mtime);
    // // printf("st_ctime: %ld\n", buf.st_ctime);

    // // pwd = getpwuid(buf.st_uid);
    // // grp = getgrgid(buf.st_gid);
    // aclm = acl_get_file(data, ACL_TYPE_ACCESS);
    
    // // if (!grp)
    // // 	printf("Group: %u\n", buf.st_gid);
    // // else
    // // 	printf("Group: %u\n", grp->gr_gid);
    // // ssize_t lep_p = 10;
    // // printf("User: %s\n", pwd -> pw_name);
    // // char *str = acl_to_text(aclm, NULL);
    // // printf("%s\n", str);
    // printf("%d", aclm);
    if (mx_get_char_index(opt, 'R') >= 0)
        mx_loop(direct, inp_files, opt);

    
}
