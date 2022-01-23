# 寒假笔记Day6

## Leetcode每日三题

### [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

读取字符串needle的长度，然后从0位置开始逐段切下haystaack和needle进行比较，如相等，则返回此时的位置。

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        string s;
        int len1=haystack.size();
        int len2=needle.size();
        if (len2==0){
            return 0;
        }
        for(int pos=0;pos<=len1-len2;pos++){
            s=haystack.substr(pos,len2);
            if(s==needle)
            {
                return pos;
            }
        }
        return -1;
    }
};
```

### [1486. 数组异或操作](https://leetcode-cn.com/problems/xor-operation-in-an-array/)

按照题目描述，我们可以直接不需要数组，直接一个循环
话不多说，代码更实在，i==0时，因为没有其他的数据和它做位异或，因此k=start+2i;
i不等于0时，k^=start+2i

```
class Solution {
public:
    int xorOperation(int n, int start) {
        int k;
        for(int i=0;i<n;i++)
        {
            if(i==0){
                k=start+2*i;
            }
            else{
                k^=start+2*i;
            }
        }
        return k;
    }
};
```

### [1332. 删除回文子序列](https://leetcode-cn.com/problems/remove-palindromic-subsequences/)

三种情况：

1. s为空，那么就是0次
2. s本身就是回文序列，那么直接删除就好，也就是一次。
3. s本身不是回文序列，那么需要两次。为什么呢，因为第一次删除其中所有的a（因为n个a一定是一个回文序列！！！注意回文序列），第二次删除其中剩下所有的b就好了，所以就两次。

```
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())
            return 0;     
        
        for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if(s[i] != s[j])
                return 2;       
        }
        
        return 1;  
    }
};
```



## Linux

**Linux**是一种[自由和开放源码](https://zh.wikipedia.org/wiki/自由及开放源代码软件)的[类UNIX](https://zh.wikipedia.org/wiki/类Unix系统)[操作系统](https://zh.wikipedia.org/wiki/作業系統)。该操作系统的[内核](https://zh.wikipedia.org/wiki/内核)由[林纳斯·托瓦兹](https://zh.wikipedia.org/wiki/林纳斯·托瓦兹)在1991年10月5日首次发布，在加上用户空间的[应用程序](https://zh.wikipedia.org/wiki/應用程式)之后，成为Linux操作系统。Linux也是[自由软件](https://zh.wikipedia.org/wiki/自由软件)和[开放源代码软件](https://zh.wikipedia.org/wiki/开放源代码软件)发展中最著名的例子。只要遵循[GNU 通用公共许可证](https://zh.wikipedia.org/wiki/GNU通用公共许可证)（GPL），**任何个人和机构都可以自由地使用Linux的所有底层[源代码](https://zh.wikipedia.org/wiki/源代码)**，也可以自由地修改和再发布。大多数Linux系统还包括像提供[GUI](https://zh.wikipedia.org/wiki/GUI)的[X Window](https://zh.wikipedia.org/wiki/X_Window)之类的程序。除了一部分专家之外，大多数人都是直接使用[Linux 发行版](https://zh.wikipedia.org/wiki/Linux發行版)，而不是自己选择每一样组件或自行设置。

​                                                                                                                                                               ------来自维基百科

因为之前学python时接触了一点linux，所以安装过，安装步骤就省去了

### 安装

安裝完成后效果![20220122180042](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/20220122180042.png)

### 帮助命令

--help和man是查看命令帮助的两种方式，主要是查看命令所对应的选项信息

**--help**：显示有该命令的简要说明以及一些参数的使用以及说明

效果图:

![help](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/help.png)

**man**：显示系统手册页中的内容

效果图: 

![man](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/man.png)

**info**：

在info后面输入命令的名称就可以查看该命令的info帮助文档了：info info

选项-d：添加包含info格式帮助文档的目录；

-f：指定要读取的info格式的帮助文档；

-n：指定首先访问的info帮助文件的节点；

-o：输出被选择的节点内容到指定文件。

### 查看目录命令

ls：查看当前目录信息

tree：以树状方式显示目录信息

pwd：查看当前目录路径

![clear](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/clear.png)

### 创建、删除、复制、移动文件及目录命令

| 命令                | 说明                       |
| :------------------ | :------------------------- |
| touch 文件名        | 创建指定文件               |
| mkdir 目录名        | 创建目录(文件夹)           |
| rm 文件名或者目录名 | 删除指定文件或者目录       |
| rmdir 目录名        | 删除空目录                 |
| cp                  | 拷贝文件、拷贝目录         |
| mv                  | 移动文件、移动目录、重命名 |

**mv命令移动文件效果图**：

![mvwj](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/mvwj.png)

### 使用tar命令完成文件的压缩和解压缩

Linux默认支持的压缩格式:`.gz`，`.bz2`，`.zip`

**说明:**

- .gz和.bz2的压缩包需要使用tar命令来压缩和解压缩
- .zip的压缩包需要使用zip命令来压缩，使用unzip命令来解压缩

**tar常用命令：**

-c：创建打包文件

-f：指定文件名称, 必须放到所有选项后面

-z：压缩或解压缩(.gz)

-j：压缩或解压缩(.bz2)

-C（**大写**）：解压缩到指定目录

**解压缩.bz2的效果图:**

![tar-5](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/tar-5.png)

### vim编辑器

vim 是一款功能强大的文本编辑器，也是早年 Vi 编辑器的加强版，它的最大特色就是使用命令进行编辑，完全脱离了鼠标的操作。

三种工作模式：

- 命令模式
- 编辑模式
- 末行模式

**<u>vim 打开文件进入的是命令模式，编辑模式和末行模式之间不能直接进行切换，都需要通过命令模式来完成。</u>**

`vim abc.txt`：打开abc.txt文件

`vim +# abc.txt`：打开abc.txt文件，光标定位在abc.txt文件的第#行



常用命令：

yy：复制光标所在行

p：粘贴

dd：删除/剪切当前行

:/搜索的内容：搜索指定内容

gg：回到第一行



### 用户权限管理

使用chmod命令完成文件权限的修改

两种修改权限的方法：

字母法：

![chmod-1](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/chmod-1.png)

数字法：也就是把rwx权限用数字代替

![chmod-3](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/chmod-3.png)

### 获取管理员权限的相关命令

sudo -s：切换到root用户，获取管理员权限

#如果大量操作都需要使用管理员权限 sudo –s, 但是操作需谨慎

whoami：查看当前用户权限

exit：退出登录用户

who：查看所有的登录用户

### 用户的命令

- 创建用户命令格式: **sudo useradd -m 用户名**, 默认会创建一个同名的用户组。
- 查看用户信息使用 **id** 命令或者 **/etc/passwd文件**
- 查看用户组信息使用 **/etc/group文件**
- 给用户设置密码使用 **sudo passwd 用户名**
- 切换用户使用 **su - 用户名**
- 设置附加组使用 **sudo usermod -G** 组名 用户名
- 删除用户使用 **sudo userdel -r 用户名**，默认会删除同名的用户组。 

### 正则表达式

**匹配单个字符：**

- . 表示匹配任意1个字符（除了\n）
- [ ] 表示匹配[ ]中列举的1个字符
- \d 表示匹配一个数字，即0-9 
- \D 表示匹配一个非数字，即不是数字 
- \s 表示匹配一个空白字符，即 空格，tab键 
- \S | 匹配一个非空白字符 
- \w | 匹配一个非特殊字符，即a-z、A-Z、0-9、_、汉字 
- \W | 匹配一个特殊字符，即非字母、非数字、非汉字 

**匹配多个字符：**

- *表示匹配前一个字符出现0次或者无限次，即可有可无
- +表示匹配前一个字符出现1次或者无限次，即至少有1次
- ?表示匹配前一个字符出现1次或者0次，即要么有1次，要么没有
- {m}表示匹配前一个字符出现m次
- {m,n}表示匹配前一个字符出现从m到n次

**匹配开头结尾：**

- ^ 表示匹配字符串开头
- $ 表示匹配字符串结尾

### 文本查找

- grep 命令是完成文本搜索操作的
- 文本搜索的命令格式: grep 选项 文本搜索内容

结合正则表达式使用：

| 正则表达式 | 说明                   |
| :--------- | :--------------------- |
| ^          | 以指定字符串开头       |
| $          | 以指定字符串结尾       |
| .          | 匹配一个非换行符的字符 |

## shell

### bash

是Linux发行版的标准shell。bash兼容sh，并且依据一些使用者需求进行了加强。bash保持了对 sh shell 的兼容性，是各种 Linux 发行版默认配置的 shell。bash的优点：

**命令记忆**：

只要我们在指令列中按上下键，就可以找到前/后一个输入的指令。

**命令与文件补全功能**：

tab接在一串指令的第一个字的后面，则为命令补全；tab接在一串指令的第二个字以后时，则为文件补全

**命令别名设定**：

假如我们需要知道这个目录下的所有文件（包括隐藏文件）及所有的文件属性，那么我们就必须下达`ls -al`这样的指令串。



### 脚本的常用执行方式

sh+脚本的相对路径，绝对路径：

```
[root@master datas]$ sh helloworld.sh 
[root@master datas]$ sh /home/atguigu/datas/helloworld.sh 
```

bash+脚本的相对路径，绝对路径

```
[root@master datas]$ bash helloworld.sh
[root@master datas]$ bash /home/atguigu/datas/helloworld.sh 
```



### 注释方式

单行注释使用 `#`

多行注释使用 `:<<自定义标识符 ...注释内容... 已定义的自定义标识符`

```
# 常用 :<<EOF multi line comment EOF 作为多行注释的方式
EOF : End Of File

:<<EOF
one 
two
three
...
EOF
```

### 变量类型

- **普通变量**、**局部变量**和系统的**环境变量**
- `Shell` 规定变量赋值号 `=` 两边不能有空格

局部变量在 `Shell` 脚本的函数中定义，只在当前 `Shell` 实例中有效，其他 `Shell` 实例不能访问该局部变量

**shell变量的赋值**：

```
#!/bin/bash
#变量的赋值
n=1
v1=${n}
v2='${n}'
v3="${n}"
 
echo "${v1}"
echo "${v2}"
echo "${v3}"
```

**shell变量的修改、删除：**

```
#!/bin/bash
#变量值的修改
a=1
echo "a: ${a}"
a=2
echo "a: ${a}"
 
#只读变量是不可以修改的，在变量前加readonly，就是只读变量
c=1
echo "c: ${c}"
readonly c
c=2
echo "c: ${c}"
 
#只要在变量前面加一个 unset，如： unset a   就可以删除变量。
unset a
echo "a: ${a}"
```

**环境变量**：用户自定义变量只在当前的shell中生效。而环境变量会在当前shell和这个shell的所有子shell当中有效。如果把环境变量写入相应的配置文件，那么这个环境变量就会在所有的shell中生效，所有的程序都能访问环境变量，有些程序运行依赖于环境变量

### 运算符

**基本语法**

（1）“`$((运算式))`”或“`$[运算式]`”

（2）**expr** + , - , *, /, % 加，减，乘，除，取余

*注意：expr运算符间要有空格*

```
[root@master datas]$ expr `expr 2 + 3` \* 4 #这个小·是tab上面那个键，不是单引号
20
```

### 条件判断

格式：

```
[ condition ]（`注意condition前后要有空格`）
```

与java语言不同的是，比较并不是><=,而是命令

-lt：小于

-le：小于等于

-eq： 等于

-gt ：大于

-ge ：大于等于

-ne ：不等于

```
[root@master datas]$ [ 23 -ge 22 ]
[root@master datas]$ echo $?
```

