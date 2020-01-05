#include "uls.h"

void mx_print_lstat(t_file *file) {
    if (file != NULL) {
        mx_printstr("\nFile name: ");
        mx_printstr(file->name);
        mx_printstr("\nFile print name: ");
        mx_printstr(file->print_name);
        mx_printstr("\nAcl info: ");
        mx_printstr(file->acl_inf);
        mx_printstr("\nColor: ");
        mx_printstr(file->color);
        mx_printstr("\nType: ");
        mx_printchar(file->type);
        mx_printstr("\nSt_mode: ");
        mx_printint(file->mode);
        mx_printstr("\nSize: ");
        mx_printint(file->size);
        mx_printstr("\nNlink: ");
        mx_printint(file->nlink);
        mx_printstr("\nUid: ");
        mx_printstr(file->uid_name);
        mx_printstr("\nGid: ");
        mx_printstr(file->gid_name);
        mx_printstr("\nBlksize: ");
        mx_printint(file->blksize);
        mx_printstr("\nBlocks: ");
        mx_printint(file->blocks);
        mx_printstr("\nAtime: ");
        mx_printint(file->atime);
        mx_printstr("\nMtime: ");
        mx_printint(file->mtime);
        mx_printstr("\nCtime: ");
        mx_printint(file->ctime);
    }
}
