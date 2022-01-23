# 寒假笔记DAY3~4

## LeetCode刷题笔记

### 83.删除排序链表中的重复元素

思路注释在代码旁

```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 如果是空或者下一个为空
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }
        // 定义next指针
        ListNode * next = head -> next;
        // 如果next的值与head的值相同，更新next的位置
        if(head -> val == next -> val) {
            while(next != nullptr && head -> val == next -> val) {
                next = next -> next;
            }
            // 这里是和删除排序链表中的重复元素II 唯一不同的地方，就是不是更新head的位置，而是更新其next的位置
            head -> next = deleteDuplicates(next);
        } else {
            head -> next = deleteDuplicates(next);
        }
        return head;
    }
};

```

### 382.链表随机节点

实在不会，看了题解也不懂

### 1185.一周中的第几天

年份分为闰年和非闰年，闰年情况：年份400n以及非100n的4n，设置闰年月份天数数组以及非闰年月份天数数组，以及字符串数组存储星期数作为返回结果，提示是1971年开始，1971年1月1日为星期五，所以从星期五开始计数

```
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
            int days = 0;
            int times = 1;

            int month_day_leap[11] = 
                {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
            int month_day_nleap[11] = 
                {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
            string whatday[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};

            if(year % 100 == 0)
            {
                if(year == 2000)// 闰年 
                {
                    
                    while(times < month)
                        { days += month_day_leap[times-1]; times++; }
                    days += day;   
                    
                }
                else//非闰年
                {
                     while(times < month)
                        { days += month_day_nleap[times-1]; times++; }
                    days += day;   
                }
            }
            else
            {
                if(year % 4 == 0)//LEAP YEAR
                {
                     while(times < month)
                        { days += month_day_leap[times-1]; times++; }
                    days += day;   
                }
                else
                {
                     while(times < month)
                        { days += month_day_nleap[times-1]; times++; }
                    days += day;   
                }
            }
            while(year>1971)
            {
                year--;
                if(year==2000)
                    days += 366;
                else if(year%100==0||year%4!=0)
                    days += 365;
                else if(year%4==0)
                    days += 366; 
            }
            int nums = days%7-1;
            if(nums == -1) nums = 6;
            return whatday[nums];
};
};
```

### [27. 移除元素](https://leetcode-cn.com/problems/remove-element/)

果然暴力解法还是好用（bushi），两层for循环，一个for循环遍历数组元素 ，第二个for循环更新数组， 发现需要移除的元素，就将数组集体向前移动一位，第二层for循环结束后因为下表i以后的数值都向前移动了一位，所以i也向前移动一位

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { 
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;

    }
};
```

### [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

双指针解决，设置前后指针i，j，元素j与i比较，当相等时j++，当不相等时，将j++赋值给++i，**这里要注意++i和i++的区别**

```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {\
    if(nums.size()==0) return 0;
       int i = 0;
       int j = 0;
       while(j<nums.size())
       {
           if(nums[j]==nums[i])
           {
               j++;
           }
           else
           {
               nums[++i] = nums[j++];
           }
       }
       return i+1;
    }
};
```

### [231. 2 的幂](https://leetcode-cn.com/problems/power-of-two/)

因为如果一个数是2的幂，一直对他取余，最后一定等于1，所以只需要`return n==1`;

同样的，0与1是特殊情况需要特殊处理

```
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if(n==1) return true;
        while(n%2==0){
            n/=2;
        }

        return n==1;
    }
};
```

应该是到目前为止做的最简单的题了

## python基础语法

### 数据类型

与js类似，python也是动态类型的

基本的：

| 类型   | 例子                     |
| ------ | ------------------------ |
| 整数   | `-100`                   |
| 浮点数 | `3.1416`                 |
| 字符串 | `'hello'`                |
| 列表   | `[1, 1.2, 'hello']`      |
| 字典   | `{'dogs': 5, 'pigs': 3}` |

其他的：

| 类型   | 例子             |
| ------ | ---------------- |
| 长整型 | `1000000000000L` |
| 布尔型 | `True, False`    |
| 元组   | `('ring', 1000)` |

### 列表

是一个有序的序列，用一对 `[]` 生成，中间的元素用 `,` 隔开，其中的元素不需要是同一类型，同时列表的长度也不固定

```
l = [1, 2.0, 'hello']
```

操作方法：len()，reverse()，.sort()

```
len(l)

a = [1, 2, 3, 4, 5, 6]
a.reverse()
a.sort()
```

两个列表相加就是相连接，乘以一个数就是多复制n份

```
l * 2
//输出为：[1, 2.0, 'hello', 1, 2.0, 'hello']
```

索引：取列表中某个下标的元素` l[1]`

切片：取某部分的元素，中间用：号隔开` a[2:3]`

可以使用del方法删除某个元素

```
a = [1002, 'a', 'b', 'c']
del a[1:]
```

### 元组

特点：不可变的，用`()`生成

与列表一样可以索引切片，但是不能更改

定义只有一个元素的元组：使用，

```
a = (10,)
```

不用逗号的话类型就不是元祖，是单个整型

常用方法：

count返回元素个数

```
a.count(10)
```

index：读取元素位置

```
a.index(12)
```

### 字典

两种方法创建： `{}` 或者 `dict()` 

类似于Java中的map，以键值对方式存在，使用`key: value`这样的结构来表示字典中的元素结构

插入方法：

```
a["one"] = "this is number 1"
```

字典中的键本身不一定是有序的，要求这些键值对的**键**必须是**不可变**的，而值可以是任意的Python对象

可以通过 `dict()` 转化来生成字典

```
inventory = dict(
    [('a', 1),
     ('b', 2), 
     ('c', 3), 
     ('d', 4)
    ])
 //输出为：{'a': 1, 'b': 2, 'c': 3, 'd': 4}
```

常用方法：

在使用jupyter notebook编译时发现，用索引可以找到一个键对应的值，但是当字典中没有这个键的时候，Python会报错，这时候可以使用字典的 `get` 方法来处理这种情况

```
print a.get("three")
//会输出none
```

`pop` 方法可以用来弹出字典中某个键对应的值，与列表一样，`del` 函数可以用来删除字典中特定的键值对，这两个是常用的删除方法

` d.keys() `返回一个由所有键组成的列表;` d.values()`返回一个由所有值组成的列表；` d.items()`返回一个由所有键值对元组组成的列表

### 循环语句

**while 循环**

格式：若condition为真则一直执行，直到condition不为真

```
while <condition>:
    <statesments>
```

实例：

```
i = 0
total = 0
while i < 1000000:
    total += i
    i += 1
```

**for 循环**

格式：会遍历完`<sequence>`中所有元素为止

```
for <variable> in <sequence>:
    <indented block of code>
```

实例：

```
total = 0
for i in range(100000):
    total += i
//range（x）表示0-x的范围
```

循环中的关键词：

 `continue` ：程序会返回到循环的最开始重新执行

```
a = [7, 6, 4, 7, 20, 2, 1]
for i in a:
    if i % 2 != 0:
        continue
#忽略奇数
```

 `break` ：程序会跳出循环，不管循环条件是不是满足

```
a = [7, 6, 4, 7, 20, 2, 1]
for i in a:
    if i =20:
    	break;
```

`while` 和 `for` 循环后面也可以跟着 `else` 语句，不过要和`break`一起连用

- 当循环正常结束时，循环条件不满足， `else` 被执行；
- 当循环被 `break` 结束时，循环条件仍然满足， `else` 不执行。

```
a = [7, 6, 4, 7, 19, 2, 1]
for x in a:
    if x <= 10:
        print x
        break
else:
    print 'All values greater than 10'
```

### 函数

使用 `def` 关键词来定义一个函数，`def` 后面是函数的名称，括号中是函数的参数

格式示例：

```
def add(x, y):
    a = x + y
    return a
```

使用函数时，参数数量要相符合，不然会报错

可以在函数定义的时候给参数设定默认值，示例：

```
def quad(x, a=1, b=0, c=0):
    return a*x**2 + b*x + c
```



可以使函数接受不定数目的参数，这里，`*+参数名称` 表示参数数目不定，可以看成一个元组，把第一个参数后面的参数当作元组中的元素，示例：

```
def add(x, *y):
    total = x
    for i in y:
        total += i
    return total
```

### 模块

在python中，所有 `.py` 结尾的文件认定为python代码文件，例如一个脚本` a.py`,这个脚本可以当作一个模块，可以使用`import`关键词加载并执行它（这里要求这个文件在当前工作目录），在导入时，**Python**会执行一遍模块中的所有内容。

`.py` 中所有的变量都被载入了当前环境中，不过要使用` .变量名`的方法来查看或者修改这些变量：

```
import e
print ex1.PI
ex1.PI = 3.141592653#也可以修改
```

可以使用 `__name__` 这个属性，使一个 `.py` 文件既当作脚本，又能当作模块用，使该程序块仅在该模块自身运行时执行

```
%%writefile ex2.py
#当作脚本执行

PI = 3.1416

def sum(list):
    total = 0
    for value in list:
        total = tot + value
    return tot

def add(x, y):
    a = x + y
    return a

def test():
    w = [0,1,2,3]
    assert(sum(w) == 6)
    print 'test passed.'
    
if __name__ == '__main__':
    test()
```

可以从模块中导入变量

```
from ex2 import add, PI
```

使用 `from` 后，可以直接使用 `add` ， `PI`；

使用 `*` 导入所有变量：

```
from ex2 import *
```

## 数学

非齐次线性方程组求解：

![IMG_0002](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/IMG_0002.PNG)

常见距离：

![IMG_0001](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/IMG_0001.PNG)

最小二乘法：

最小二乘法的主要思想是通过确定未知参数（通常是一个参数矩阵），来使得真实值和预测值的误差（也称残差）平方和最小，其计算公式为 ![[公式]](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/equation) ，其中 ![[公式]](https://www.zhihu.com/equation?tex=y_i) 是真实值， ![[公式]](https://www.zhihu.com/equation?tex=%5Chat+y_i) 是对应的预测值。最小二乘法求出来的最优解就是将均方误差作为损失函数求出来的最优解。

## 机器学习 KNN算法

为未知分类寻找其分类

KNN:分类/回归算法，通过最近的K个数据，推断新数据的分类，不同的问题k的选择不同

步骤：

1. 计算距离，使用已学的几种求常用距离的方法
2. 升序排列
3. 取前k个
4. 加权平均，根据距离大小来分配权重

（核心）k的选取要适中，太大使分类模糊，太小受个例影响波动大

实现的代码(已上传github仓库里)：

```
# -*- coding:utf-8 -*-
"""
作者: GrandeLai
日期: 2022年01月20日
"""
import random
import csv

#读取
with open('Prostate_Cancer.csv','r') as file:
    reader=csv.DictReader(file) #以字典的方式读取
datas=[row for row in reader] #把每一行抽出来放进datas里面

#分组
random.shuffle(datas) #每次测试都打乱顺序，是每次运行数据都不太一样
n=len[datas]//3
test_set=datas[0:n] #测试集
train_set=datas[n:] #训练集

#KNN
#算距离的函数,用欧式距离
def distance(d1,d2):
    res=0
    for key in("diagnosis_result","radius",	"texture","perimeter","area","smoothness","compactness","symmetry","fractal_dimension"):
        res+=(flout(d1[key])-flout(d2[key]))**2
    return res**0.5

#定义一个KNN函数
K=5
def KNN(data):
    #1.距离
    res=[
        {"result":train["diagnosis_result"],"distance":distance(data,train)}
    ]

    #2.升序排序
    res=sorted(res,key=lambda item:['distance'])

    #3.取前K个
    res2=res[0:K]

    #4.加权平均
    result={'B':0,'M':0} #赋予权重

    #算总距离
    sum=0
    for i in res2:
        sum+=r['distance']

    for i in res2:
        result[r['result']]+=1-r['distance']/sum #代表现在结果给B还是M加权

    if result['B']>result['M']:
        return 'B'
    else:
        return 'M' #给出结果

#测试
correct=0
for test in test_set: #把测试集里的每一项都拿出来测一测
    result=test['diagnosis_result'] #是result的真实结果
    result2=knn(test)

    if result==result2: #判断预测是否准确
        correct+=1
```

**两天的总结：**

感觉这两天下来就是数学不好学算法是真的，折磨，学python时感觉还可以，一到数学那里，学了好久还没到矩阵，数学的方面也没学懂多少，好多都不会，LeetCode也遇到了一到连题解都看不明白的，不过算法我也在学习KNN时感受到了他的有趣，希望等之后夯实了了数学基础以后再学吧，算法也挺有用的，特别是在最后KNN分析那个数据时更让我感觉如此。

