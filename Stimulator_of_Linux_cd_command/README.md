## Simulator of Linux cd Command

This is a simulator for the Linux `cd` and `pwd` command, developed by flew_kites from Xidian University.

### Usages

First, you should input the initial directory. 

Then, you can execute the `cd` or `pwd` command.

#### Command `pwd`: print current directory

- `pwd`: print current directory

#### Command `cd`: change directory

- `cd dir1/dir2`: go to relative path
- `cd /path/to/dir`: go to absolute path
- `cd /`: go to root directory
- `cd ..`: go to parent directory

### Full Mode

If you want to use this program in full mode, you can define `FULL_MODE` as `1`*(default)*.

In full mode, the program will work like a Linux shell:

- You can see the username and hostname in the prompt, default is `kites@Linux`
- You can type `pwd` to print current directory and continue to input.



If `FULL_MODE` is defined as `0`,  the username and hostname will not be printed, and `pwd` terminate the program after print the word directory.

### Example

*(FULL_MODE = 1)*

```
/home/me
kites@Linux:/home/me$ cd domain
kites@Linux:/home/me/domain$ cd website/configs 
kites@Linux:/home/me/domain/website/configs$ pwd
/home/me/domain/website/configs
kites@Linux:/home/me/domain/website/configs$ cd ..
kites@Linux:/home/me/domain/website$ cd /etc/nginx/sites-enabled
kites@Linux:/etc/nginx/sites-enabled$ pwd
/etc/nginx/sites-enabled
kites@Linux:/etc/nginx/sites-enabled$
```

