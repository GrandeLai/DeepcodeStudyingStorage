

# 寒假笔记DAY1

## LeetCode刷题笔记

### **1.两数之和**

题解：

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
           for(j=i+1;j<nums.size();j++)
           {
               if(nums[i]+nums[j]==target){
                   return {i,j};
                   
               }
           }
        }
        return{i,j};
    };
};
```

暴力遍历，双层for循环，依次遍历，使用if判断是否和target相等，相等就return

### 20.有效括号

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char a : s){
            switch(a){
                case ')':{
                    if(st.empty()||st.top()!='('){
                        return false;
                    }
                    st.pop();
                    break;
                }
                case ']':{
                    if(st.empty()||st.top()!='['){
                        return false;
                    }
                    st.pop();
                    break;
                }
                case '}':{
                    if(st.empty()||st.top()!='{'){
                        return false;
                    }
                    st.pop();
                    break;
                }
                default:{
                    st.push(a);
                    break;
                }
            }
        }
        return st.empty();
    }
};
```

使用栈，因为switch可以使用字符，先把所有的左半边括号字符丢入栈st中，又for遍历字符串中的每个右半边括号字符并丢入switch中判断是否与栈顶的字符相匹配，若匹配有效将原来的那半边pop，若无效直接返回false；

### **709.转换成小写字母**

```
class Solution {
public:
    string toLowerCase(string s) {
        for(auto &c:s){
            if(c>='A' && c<='Z') {
                c+=32;
            }
        }
        return s;
    }
};
```

这里使用奇技淫巧，因为我们知道字母A的asicii码为65，a为97，且每个大写字母和小写字母都差32

所有遍历字符串中每一个字母，使其加32

**重点：因为需要改变s的值所以for(auto &c:str)必须是引用而且不能加const**



## Markdown基本使用

markdown是一种格式，以`.md`为后缀，例如本笔记就是使用Markdown编辑器Typora写的，

使用优点：

1. 专注于文字内容；

2. 纯文本，易读易写，可以方便地纳入版本控制；

3. 语法简单，没有什么学习成本，能轻松在码字的同时做出美观大方的排版

### 标题

通过在文字前加#来设置标题等级，**几个#对应几级标题**，**注意#后面需要加上空格**

Typora内可通过Ctrl+n的快捷键设置n级标题

```
# 一级标题
### 三级标题
```



### 行内文字显示效果设置

在需要加粗的一段文字前后加**

在需要变为斜体的一段文字前后加*（因为上一行的星号会使本行变为斜体所以选择换行）

在需要变为斜粗体的一段文字前后加***

Typora内可通过Ctrl+B设置加粗，Ctrl+I设置斜体

```
选择需要的文字**加粗**
选择需要的文字改为*斜体*
```



### 引用块

在需要应用的文字首加上>和**空格**

> 比如这一段

还可以通过增加>数量实现引用嵌套

> 引用
>
> > 引用嵌套



### 行内超链接

格式：`[添加链接的文字内容](链接地址)`

例如：`[我的GitHub主页](https://github.com/GrandeLai)`

[我的GitHub主页](https://github.com/GrandeLai)



### 引用图片

在行内超链接的格式前加一个 `!`，就是引用图片的方法。

例如：`![image](https://avatars.githubusercontent.com/u/88603052?s=400&u=7ec1e771ea0566971c34f50376ae75965c2b21a0&v=4)`

图片插入示例：

![image](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/88603052)



### 列表

Typora在添加了第一条后回车会自动添加第二条

#### 有序列表

格式：` 数字+.+空格+内容`，

1. 格式1
2. 格式2
3. 格式3

#### 无序列表

格式：` +或*或-+空格+内容`

如：

+ 无序列表

+ 无序列表

**如何结束无序列表：连按两下回车**



### 代码块

#### 行内代码

格式：` 反引号+空格+内容+反引号`

示例：` cout<<""<<endl;`

Typora快捷键：Ctrl+Shift+`

#### 插入代码块

格式：三个反引号+使用的语言如Java+代码块+三个反引号

示例： 

``` java
public class HelloJava {
    public static void main(String[] args) {
        System.out.println("学习真不错");
    }
}
```

Typora快捷键:Ctrl+Shift+K

### 水平分割线

使用一个单独行里的三个或以上 `*`、`-` 来生成一条水平分割线

示例：

****

---

### 表格

格式：

```
| 编号  | 食品名稱 | 生產日期 | 
| ----- | :--------  | ---------: | 
| 0     | 可樂       | 12.12         | 
| 1     | 雪碧       | 12.11         | 
```

示例：

| 编号 | 食品名稱 | 生產日期 |
| ---- | :------- | -------: |
| 0    | 可樂     |    12.12 |
| 1    | 雪碧     |    12.11 |

### 添加emoji(似乎用处不大)

格式：` :camel: :blush: :smile:`

示例：

:camel: :blush: :smile:

## 图床配置测试：

![ntzx](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/ntzx.jpg)

## Git使用

为什么需要Git：当我需要对某个文件进行多次改动时，能自动帮我记录每次文件的改动，且不需要文件传输就能让他人参与改动，且当我需要查找某次改动时，他会清楚地呈现出来

### 创建git仓库

1. 在Git Bash中依次输入一下命令

```
$ mkdir learngit //创建learngit文件夹
$ cd learngit	//进入文件夹
$ pwd	//查看文件夹路径
```

2. 把这个仓库变成Git可以管理的仓库：

```
$ git init
Initialized empty Git repository in C:/Users/GrandeLai/learngit/.git/
```

### 将txt文件添加到版本库中

**使用Visual Studio Code创建一个txt，不要使用记事本**，保存在learngit目录下

1. 使用命令git add添加

   ```
   $ git add readme.txt
   ```

2. 使用get commit告訴git提交给库

   ```
   $ git commit -m "wrote a readme file"
   // -m后面的是改动说明，便于日后查看，可以写任何东西
   ```

回车后会显示一些文字，这些文字描述了你添加文件的内容

### 显示更改记录

用`git status`命令可以查看当前仓库的状态

用`git log`命令查看历史记录，用`git reset`命令可以返回到某次更改时

HEAD表示当前版本，后面加上^表示上一版本，再加一个表示上上版本，示例：

```
$ git reset --hard HEAD^
HEAD is now at c31ba7f wrote a readme file
```

通過在hard后面加上版本号可以指定去到某個分支，示例：

```
$ git reset --hard 39542
HEAD is now at 3954230 append GPL
```

### 分支管理

git默认会创建master分支,使用` git branch`查看当前分支

```` 
$ git branch
* master
````

**创建分支**

``` 1 
$ git branch dev
```

**删除分支**

``` 1
$ git branch -d dev
```

**切换分支**

使用checkout或switch

``` 1
$ git checkout master
$ git switch master
```

**合并分支**

``` 1
$ git merge dev
```

### 远程仓库

**创建远程仓库**

使用` $ git remote add +远程仓库名称+远程仓库地址`来创建

**将分支推送到远程仓库**

```
git push 目标仓库 分支名
```

**从远程库克隆**

```
git clone 远程仓库地址
```

**抓取项目**

fetch，只获取远程项目分支，需手动合并

```
$ git fetch test
```

**拉取项目**

pull，可以自动合并

```
$ git pull test
```

**使用实例：**

根据笔记要求，在本地新建一个LearningDairy推送到github仓库中

![image1](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/屏幕截图 2022-01-17 150015.png)

## HTML和CSS基础语法

### HTML基础

HTML 指的是超文本标记语言

**HTML 标题**

标题级数从<h1> - <h6>递减

代码实例：

```
<h1>一级标题</h1>
<h2>二级标题</h2>
<h3>三级标题</h3>
```

**HTML段落**

通过标签 <p> 来定义段落

```
<p>段落1</p>
<p>段落2</p>
```

**HTML链接**

通过标签 <a> 来插入超链接

格式：

```
<a href="www.github.com">github</a>
//后面的github表示放置超链接的字段
```

**HTML图像**

通过标签 <img> 来插入图片

src指定图片在哪个地方，width，height指定宽高

```
<img  src="https://gitee.com/grandelai/imagestore/raw/master/imagetostore/ntzx.jpg" width="25" height="39"  />
```

**无序列表**

与md的类似，使用粗体圆点进行标记，使用 <ul> 标签，每个列表项始于 <li> 标签

```
<ul>
<li>无序标题1</li>
<li>无序标题2</li>
</ul> 
```

**有序列表**

使用数字进行标记，使用 <ol> 标签

```
<ol>
<li>有序标题1</li>
<li>有序标题2</li>
</ol> 
```

**HTML 表单**

是一个包含表单元素的区域，使用表单标签 <form> 来设置表单

+ 输入<input>

文本域：

当需要用户输入数字英文是，通过<input type="text">来获取

```
<form>
    First name: <input type="text" ><br>
    Last name: <input type="text" >
    </form> 
```

密码：

通过<input type="password"> 获取，输入的密码，**为什么使用这个也不是文本框？因为输入的内容会转换为圆点**

```
<form>
Password: <input type="password">
</form> 
```

单选和复选：

<input type="radio">定义单选，<input type="checkbox"> 定义复选;

```
<form>
    <input type="radio">Boy<br>
    <input type="radio" >Girl
    </form>

<form>
    <input type="checkbox">A bike<br>
    <input type="checkbox">A car
    </form>
```

**HTML 表格**

由 <table> 标签定义表格，生成的表格在一对`<table></table>`中

表格边框使用`<table border="1"></table>` 的方式来定义，其中数字表示边框的宽度，单位为像素

由 <tr> 标签定义每行，由 <td> 标签定义每行的单元格

```
<table border="1">
    <tr>
        <td>row 1, cell 1</td>
        <td>row 1, cell 2</td>
    </tr>
    <tr>
        <td>row 2, cell 1</td>
        <td>row 2, cell 2</td>
    </tr>
</table>
```

**HTML 框架**

使用<iframe>定义框架，使得在一个浏览器窗口中显示多个页面，height 和 width 属性来定义标签宽高

```
<iframe src="www.zhihu.com" width="200" height="200"></iframe> 
```

### **CSS基础**

由两个主要的部分构成：选择器，以及一条或多条声明

```
<head>
	<style>
		选择器{
			属性名：属性值;
			属性名：属性值;
		}
	</style>
</head>
```

新建一个标签

```

```

**三种样式**

内部样式：在页面头部通过style标签定义

行内样式：使用HTML标签的style属性定义

外部样式：使用单独的 `.CSS` 文件定义，然后在页面中使用 `link标签` 或 `@import指令` 引入

**选择器**

就是需要修饰的对象或标签

id选择器：使用自定义名称，以 `#` 作为前缀，然后通过HTML标签的id属性进行名称匹配，一对一关系

```
<head>
	<style>
		#h{
            color:red;
        }
	</style>
</head>

<body>
	
	<h1 id="h">哈哈</h1>
</body>
```

class选择器：可以在多个元素中使用，所有拥有 CSS 类的 HTML 元素都设为红色

```

<head>
	<style>
		.CSS{
			color:red;
		}
		
	</style>
</head>
<body>
	<h1 class="CSS">CSS</h1>
	
</body>
</html>
```

标签选择器：

新建标签：

```
<div style="border: 1px solid red;">div标签1</div>
```

格式：

```
标签{
	属性名：属性值;
}
```

组合选择器：

```
选择器1，选择器2，选择器n{
	属性名：属性值;
}
```

**块状元素**

最大特点是可以独占一行，div是html中典型的块状元素，可以为它设置宽度，高度，边缘

```
<head>
	<style>
		div{
        	margin: 20px;
        	padding: 10px;
        	width: 100px;
        	height: 100px;
        	background-color: yellow;
        }
	</style>
</head>
<body>
	<div>块状元素</div>
	
</body>
</html>
```

**内联元素**

内联元素和其他元素是在同一行显示的，不能设置宽度、高度

```
<head>
	<style>
		span{
	margin: 50px;
	padding: 120px;
	background-color: orange;
}
	</style>
</head>
<body>
	<span>内联元素</span>
	
</body>
</html>
```

## DAY1总结

今天的学习是将LeetCode刷题放在了后面，而CSS因为时间不够所以也没有全部完成，但是今天Leetcode的题目比较简单，只有第二题需要看题解写出，但是另外两题都是使用了特殊解法，没有考虑更好的方法，以及今天git的学习也没有学得很扎实，稍微入门(也不算)了一下前端的html和css，感觉还是挺有趣的，希望明天提高学习效率把。