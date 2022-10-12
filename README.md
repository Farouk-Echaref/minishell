# test cases
```bash
ls > > f1
```
```bash
# remove current folder
cd
```
```bash
e'c'"h"o $HOME---"here we go" '$PATH'
```
```bash
touch f1 && chmod 0 f1
< f1 cat
```
```bash
echo $$$
echo $.
echo $"d"
echo $'d'
```
```bash
unset $PATH
ls
echo test
```
```bash
unset $HOME
cd
```
#### herdoc
```bash
<< end cat
> 'klsklf--$HOME---'
> asdlfkjadklsfj----$PATH----
```
```bash
<< end | ls
```
```bash
<< 'end' cat
> 'klsklf--$HOME---'
> asdlfkjadklsfj----$PATH----
```
```bash
<< "end" cat
> 'klsklf--$HOME---'
> asdlfkjadklsfj----$PATH----
```
```bash
<< "en"d cat
> 'klsklf--$HOME---'
> asdlfkjadklsfj----$PATH----
```
```bash
<< *$tt cat
> *$tt
```
```bash
<< $tt cat
> $tt
```
```bash
<< end cat
>
ctrl + d
```
```bash
export tt="<<"
$tt end cat
```
#### exit status
```bash
./minishell
dksfjdsf
exit
echo $?
```
```bash
./minishell
dksfjdsf
exit 3
echo $?
```
```bash
cat
ctrl+\
```
#### export
```bash
export key="value"
./minishell
echo $key
```
```bash
export a a a aaa
export aaa
```
```bash
export a="value"
export a+="lksjdfklj"
```
```bash
export tt="m s"
export $tt="text"
```
```bash
export v="something" | ls
echo $v
```
```bash
export v="something" && echo $v
```
#### pipe
```bash
export | grep m
```
```bash
cat | cat | ls
```
#### wildcards
```bash
export tt="e - m* - * - s"
echo *$tt*
```
```bash
mkdir test && cd test && touch f1
< * cat
```
```bash
< * cat
< M*file cat
```
