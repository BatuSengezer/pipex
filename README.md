# pipex

A program that mimics "|" (pipe) operator in shell. It reads from a file (file1), executes the command (cmd1) and writes that output as an input to the next command (cmd2). Then writes output of the next command to the outfile(file2).

Program behaves exactly the same as "< file1 cmd1 | cmd2 > file2".
### You can run it as :
```zsh
# terminal
make && ./pipex file1 cmd1 cmd2 file2
```

The bonus part handles multiple pipes as in shell command "< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2". \ 
Also it handles "<<" and">>" when the first argument is here_doc as in shell command "cmd << LIMITER | cmd1 >> file".
### You can run bonus part as :
```zsh
# terminal
make bonus &&  ./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
OR
make bonus && ./pipex_bonus here_doc LIMITER cmd cmd1 file
```
