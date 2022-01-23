# 寒假笔记DAY2

## LeetCode刷题笔记

### 349.两个数组的交集

```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        set<int> set;  
        int len=nums1.size();
        for(int i=0;i<len;i++)
        {
            if(set.count(nums1[i])==0)
            {
                set.insert(nums1[i]);
            }
        }
        for(auto i:nums2)
        {
            if(set.count(i)==1)
            {
                set.erase(i);
                vec.push_back(i);
            }
        }
        return vec;
    }
};
```

因为set不允许容器中有重复的元素，所以使用c++的stl中的set去重求交集；遍历集合一，将集合一中的不同元素存入set容器中，此时注意每个元素只存入一次；然后遍历集合二，如果set中存在相同元素，则此数为两集合交集，将该数加入结果集，并从set中删除该数，防止重复添加

### 88.合并两个有序数组

```
import java.util.Arrays;

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=0;i!=n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        Arrays.sort(nums1);
    }
}
```

这里因为最近学了Java，java数组可以排序所以灵机一动就试试直接合并后排序，较为简单，让我惊讶的是执行用时和内存消耗都挺理想的，第一次用java刷leetcode，还行

### 234.回文链表



链表在C++中操作起来较复杂，所以我想把每个结点的数据域保存到一个vector中(不限长度就是好)，然后头尾向中间遍历，一旦不符合回文条件直接break，虽然编译通过，但遗憾的是执行用时和内存消耗只有50%多，20%多的击败率，



## JavaScript学习

### 基本语法

数字字面量：可以是整数也可以是小数，3,3.14等

字符串字面量：单引号或双引号，"Deepcode",'Deepcode'

表达式字面量：5*6,6+7

数字字面量：` [5,6,9,6],["abc","dfg","hij"]`

对象字面量：

```
{age:18，name:"张三"}
```

变量：使用var来定义变量,` var a=5`

语句：JavaScript 语句是由 web 浏览器执行的指令，用分号分隔；

```
var x=4;
y = x * 10;
```

关键字：如var，for，if等

注释：使用` //`

字符集：使用Unicode字符集，**JavaScript对大小写敏感**

### 输出

使用  **document.write()** 方法将内容写到 HTML 文档中

### **数据类型**

与java一样也分为基本数据类型和引用数据类型

但是与java不同的是他的类型是动态改变的，如：

```
var x=5;
x="abc";
```

基本数据类型有数值，字符串，布尔等以及Undefined 和 Null

**Undefined 和 Null:**变量只声明没有赋值，会返回undefined;可以给变量赋值null来清空变量

可以使用new关键词来声明变量的类型：` var name=new String;`

引用数据类型有：数组，对象，函数

### **数据类型转换**

**转换为字符串**：

.toString()：如` bool.toString()`,不可转null

String():null也能转，如` String(null)`

如java，+号如果左右任意一个为字符串类型，另一个为其他类型，就可以转换为字符串

**转为数值类型**：

Number()：如果要转换的字符串中有一个不是数值的字符，返回NaN

parseInt()，parseFloat()：转换为整型或浮点型

**转换为布尔型：** Boolean():如果变量为“(空字符串) null undefined NaN”这些就会为false，其他为true

### 函数

定义函数的格式：

```
function functionname()
{
  // 执行代码
}
```

函数可以选择是否有返回值，参数也可以选择多个，但是调用时要一一对应

```
function myFunction(a, b) {
    return a * b;                                
}
```

与java一样，函数内部定义的变量为局部变量，函数执行完会消失

### 对象

js中，万物皆为对象

对象可以为一个变量，对象每个值以 name:value 对呈现

如：

```
var person = {name:"Tom", age：18,};
```

一个name:value 对称为对象的一个属性

访问对象属性：` person.age`

创建对象方法：

```
①：var person = {
   name: "XiaoMing",
   age: 29,
   job: "Software Engineer",
   sayName: function () {
       //方法体
   }
②：var person = new Object();
   person.name = "XiaoMing";
   person.age = 18;
   person.job = "software Engineer";

   person.sayName = function () {
      //方法体
   }
```

使用对象方法：

```
person.sayName();
```

### 作用域

局部作用域：局部变量在函数内定义，作用域就为局部作用域，在函数开始执行时创建，函数执行完后局部变量会自动销毁。只能在局部						访问。

全局作用域：在函数外定义的变量，有 全局作用域，在网页中的任意函数中都可以用

如果变量在函数内没有用var声明，则它也有全局作用域

### BOM

全称：浏览器对浏览器对象模型

window对象，表示浏览器窗口，所有 JavaScript 全局对象、函数以及变量均自动成为 window 对象的成员



## 总结：

今天JavaScript学习任务完成情况不佳，因为自身数据库学习占有了太多时间所以导致后面的bom和dom内容只学了一点，但是JavaScript的基础内容了解了一下，感觉和java差别不大，明天就要开始算法内容了，感觉前端挺有趣的，希望一周学习结束后能继续补齐这些遗漏的内容吧，积极分配好每天各项内容的时间