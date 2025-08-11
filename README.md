# ls_analog
buld comand 
sudo chmod +x make.bash (if first time)
./make_bash

//Reminder stat.h defines
    dev_t       st_dev;         /* ID of the device containing the file.
    dev_t       st_rdev;        /* Device ID.
    uid_t       st_uid;         /* User ID of file.
    gid_t       st_gid;         /* Group ID of file.
    time_t      st_mtime;       /* Time of last data modification.
    time_t      st_atime;       /* Time when file data was last accessed.
    time_t      st_ctime;       /* Time of last file status change.
    mode_t      st_mode;        /* File types and permissions.
    nlink_t     st_nlink;       /* Number of hard links to the file.
    blksize_t   st_blocksize;   /* Size of a block used by st_nblocks.
    int32_t     st_nblocks;     /* Number of blocks st_blocksize blocks.
    blksize_t   st_blksize;     /* Preferred I/O block size for object.