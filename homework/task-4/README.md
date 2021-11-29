## Собрать и запустить

`nasm -f elf64 langs.asm -o langs.o && ld langs.o -o langs && ./langs -f in out out_sort`