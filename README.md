<p align="center">
    <a href="https://unitfactory.net/en/" target="_blank">
        <img src="https://github.com/viacheslavpleshkov/unit-factory-ucode/blob/master/.git_images/unit_logo.png?raw=true" height="100px">
    </a>
    <a href="https://apply.ucode.world/" target="_blank">
        <img src="https://github.com/viacheslavpleshkov/unit-factory-ucode/blob/master/.git_images/ucode_logo.png?raw=true" height="100px">
    </a>
    <h1 align="center">unit-factory-ucode-uls</h1>
    <br>
</p>
<p align="center">⛏ My own implementation of the famous Unix command: ls</p>

## Used technologies

C, Makefile, File system, Memory, Terminal, Bash, Unix, CBL framework

<hr>

## Building the program

1. Download/Clone the source code
2. `cd` into the root directory
3. Run `make`

## Running the program

It's pretty simple, instead of calling `ls`, call `./uls` from the root directory of the source code after building it.

## Supported flags
```
usage: uls [-ACGRSTaclmrstu1] [file ...]
```
- Long listing display: -l
- Display recursively: -R
- Display all files: -a
- Reverse sort: -r
- Sort by modification date: -t
- Display one entry per line: -1
- Column display: -C
- Sort by creation date: -U
- Sort by last access date: -a
- Sort by last status change date: -c
- Show every entry except for current and previous directories: -A
- Sort by file size: -S
- Colorized output: -G 

## Author
1. <a href="https://github.com/viacheslavpleshkov" target="_blank">Viacheslav Pleshkov</a>
1. <a href="https://github.com/leodobrovolsky" target="_blank">Leonid Dobrovolskyi</a>


## License

Collision is an open-sourced software licensed under the [MIT license](LICENSE.md).
