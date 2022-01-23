# Leetcode题解

## [3. 无重复字符的最长子串](https://gitee.com/link?target=https%3A%2F%2Fleetcode-cn.com%2Fproblems%2Flongest-substring-without-repeating-characters%2F)

创建一个数组用来记录上一次出现的index
start 作为左指针，记录上一次出现的元素的index的后一个index。
那么用i - start + 1 就是这次出现的元素到这个元素上次出现的index的距离

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[128] = {0};
        for (int i = 0; i < 128; ++i) {
            last[i] = -1;
        }
        int n = s.size();
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            int index = s[i];
            start = max(start, last[index] + 1);
            maxLength = max(maxLength, i - start + 1);
            last[index] = i;
        }
        return maxLength;
    }
};
```

## [13. 罗马数字转整数](https://gitee.com/link?target=https%3A%2F%2Fleetcode-cn.com%2Fproblems%2Froman-to-integer%2F)

直接把字符串遍历一遍，再分情况进行判断，并对`ans`进行自加。

如何处理 "IV" "IX" "XL" "XC" "CD" "CM"这几种情况有以下方法：

在判断s[i]是否为"I"的if里if(s[i] == 'I')，再嵌套一次ifif(s[i + 1] == 'V')，用来判断s[i]的下一位是否为"IV"，然后ans += 4，最后i++让被判断的字符多往后移1一个字符（也就是为了跳过"V"的判断），再用continue跳过后面的if。

```
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'I'){
                if(s[i + 1] == 'V'){
                    ans += 4;
                    i++;
                    continue; 
                }
                else if(s[i + 1] == 'X'){
                    ans += 9;
                    i++;
                    continue; 
                }
                else ans += 1;
            }
            if(s[i] == 'X'){
                if(s[i + 1] == 'L'){
                    ans += 40;
                    i++;
                    continue; 
                }
                else if(s[i + 1] == 'C'){
                    ans += 90;
                    i++;
                    continue; 
                }
                else ans += 10;
            }
            if(s[i] == 'C'){
                if(s[i + 1] == 'D'){
                    ans += 400;
                    i++;
                    continue; 
                }
                else if(s[i + 1] == 'M'){
                    ans += 900;
                    i++;
                    continue; 
                }
                else ans += 100;
            }
            if(s[i] == 'V') ans += 5;
            if(s[i] == 'L') ans += 50;
            if(s[i] == 'D') ans += 500;
            if(s[i] == 'M') ans += 1000;
        }
        return ans;
    }
};
```

## [1332. 删除回文子序列](https://leetcode-cn.com/problems/remove-palindromic-subsequences/)

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



# 数据库

## 数据库概述

为什么使用数据库？**持久化**

DB：数据库，本质上是文件

DBMS：数据库管理软件

SQL：一种语言，专门与数据库通信的

## MySQL

关系型数据库，把复杂的数据结构归结为简单的二元关系(即二维表格)，以行和列的方式存储数据，一系列的行和列组成表，表再组成库。

表和表之间的数据记录有关系，表名具有唯一性；

每一个表类似于Java中的类

表中的一个记录类似于java中的一个对象

表中的一个列对应java中 的一个属性

**表的关联关系**：一对一关联,一对多关联(客户表和订单表一个客户对应多个订单，分类表和商品表)，多对多(必须创建第三个表，第三个表称为联接表，如学生信息表，课程信息表，选课信息表就是联接表)



## 基本的SELECT语句

**SQL的分类**

DDL:数据定义语言，create，alter，drop删除，rename，truncate清空等操作，针对的是表

DML:数据操作语言，针对的是表内的数据，INSERT,DELETE,SELECT,UPDATE等操作

DCL:数据控制语言,COMMIT提交,ROLLBACK撤销,GRANT和REVOKE是权限的赋予与回收，SAVEPOINT保存点

**注释**

单行注释：#（MYSQL特有）  和-- （后面包含一个空格，所有数据库都有的）；多行注释：/*  */

**SELECT语句**

`SELECT 2,5 FROM DUAL;`
`SELECT 2,5;#DUAL是伪表，两者等价`

SELECT 字段1，字段2.... FROM 表名

*：表示表中的所有字段或列

可以通过在SELECT的字段后面加一个别名使结果集的字段名改为别名，如`SELECT employee_id emp_id FROM employees;`

使用DISTINCT关键字去重查询：`SELECT DISTINCT employee_id FROM employees;`

若表名与某个关键字冲突，使用着重号``；



DESCRIPE显示表的详细信息



过滤数据：使用WHERE关键字，如`SELECT DISTINCT employee_id FROM employees WHERE employee_id=200;`

## 运算符

整型加字符若字符可以转换为整型就以整型相加，若无法转换则看为0；

**比较运算符**

存粹的字符与字符比较如'a'='b'，不会转换为整型，直接比较ansi码；NULL参与的比较结果都为NULL

安全等于：<=>，解决不能和NULL比较的问题

<>和!=都表示不等于

判断是否为NULL可以使用IS NULL,IS NOT NULL,ISNULL()函数，`如WHERE ISNULL(commission_pct) `或使用WHER NOT比较：`WHERE NOT commission_pct <=> NULL ;`

LESAT()和GREATESET()函数：

如`SELECT LEAST(last_name,first_name) FROM employees;`比较每个字段的last_name和first_name的大小，安装ansi码比较

BETWEEN...AND...:查询...到...范围内的数据

IN()函数NOT IN()：参数列表是set，如 `IN(10,20,30)`

%：代表多个不确定的字符

_:代表一个不确定的字符

LIKE函数模糊查询：如查询包含字符a的，`LIKE '%a%'`

**逻辑和位运算符**

非：NOT或者! ；

与：AND或&&；

或：OR或者||

异或：XOR，`例WHERE salary >5000 XOR department_id=50;`必有前后任一个条件不满足

AND可以和OR一起使用但AND的优先级高于OR

位运算时每向左移动一位就相当于乘以2，右移一位相当于除以2

## 排序与分页

**排序**

使用ORDER BY对数据进行排序，升序：ASC，降序：DESC

```
SELECT last_name,commission_pct
FROM employees
WHERE commission_pct IS NOT NULL
ORDER BY commission_pct DESC;
```

WHERE在ORDER BY前面，列的别名只可以在ORDER BY中使用，WHERE不行

可以指定多級排序

```
ORDER BY commission_pct,salary DESC;
```

**分页**

使用LIMIT实现分页显示

```
#每页显示20条记录，显示第一页
SELECT last_name,employee_id,salary
FROM employees
LIMIT 0,20;
#LIMIT后面跟的第一个参数是位置偏移量，第二个是每页显示的个数
#显示第2页
SELECT last_name,employee_id,salary
FROM employees
LIMIT 20,20;
```

声明顺序：WHERE,ORDER BY,LIMIT

8.0新特性：LIMIT...OFFSET...，参数类型顺序与LIMIT相反

```
LIMIT 20 OFFSET 5;
```

## 多表查询

```
 SELECT employee_id,department_name
 FROM employees,departments
#会出现笛卡尔积的情况，就是每个员工都会和每个部门匹配一遍
```

需要有连接条件

```
 SELECT employee_id,department_name
 FROM employees,departments
 WHERE employees.department_id=departments.department_id
```

可以给表起别名，在SELECT和WHERE中使用

```
SELECT employee_id,department_name,dep.department_id
FROM employees emp,departments dep
WHERE emp.department_id=dep.department_id
```

有n个表实现多表连接就需要n-1个连接条件

以上条件为等号链接的称为等值连接，非等号的称为非等值连接

非等值连接：

```
SELECT last_name,salary,grade_level
FROM employees e,job_grades j
WHERE e.salary BETWEEN j.lowest_sal AND j.highest_sal;
```

自连接：

```
SELECT em.employee_id,em.last_name,mn.employee_id,mn.last_name
FROM employees em,employees mn
WHERE em.manager_id=mn.employee_id
//每个员工都有一个管理者，而每个管理者又有一个employee_id，每个管理者也有它的管理者
```

内连接：只把左表和右表匹配的行列出来

外连接：处内连接列出的行以外还列出来其他的不匹配的行,分为左外连接（返回左表不满足的），右外连接（返回右表不满足的），满外连接	

SQL99语法实现内连接：

```
SELECT employee_id,department_name,dep.department_id
FROM employees emp JOIN departments dep
ON emp.department_id=dep.department_id
```

多表内连接：

```
SELECT employee_id,department_name,dep.department_id
FROM employees emp JOIN departments dep
ON emp.department_id=dep.department_id
JOIN locations l
ON dep.location_id=l.location_id;
```

SQL99语法实现外连接：使用join on

左外连接：join前加left，outer可以省略

```
SELECT employee_id,department_name,dep.department_id
FROM employees emp LEFT OUTER -=JOIN departments dep
ON emp.department_id=dep.department_id
```

![image-20220118110011954](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/image-20220118110011954.png)

**UNION关键字**

返回两个查询的结果集的并集，去除重复记录。

UNION ALL：不去重

使用union实现满外连接：

```
SELECT employee_id,department_name,dep.department_id FROM employees emp LEFT OUTER JOIN departments dep ON emp.department_id=dep.department_id
UNION
SELECT employee_id,department_name,dep.department_id FROM employees emp RIGHT OUTER JOIN departments dep ON emp.department_id=dep.department_id
```

自然连接：NATURAL JOIN自动查询两张表中相同的字段相连接

```
SELECT employee_id,department_name,dep.department_id 
FROM employees emp NATURAL JOIN departments dep;
```

## 单行函数

Rand（）返回0~1上的随机值

Round（x）四舍五入x，Round（x，y）对x四舍五入保留y位小数

TRANCATE（x,y）截断x中第y位小数

CONCAT(S1,S2,S3...)将多个字符串连接

CONCAT_WS(S,S1,S2,S3...)用S来连接多个字符串

字符串索引从1开始

LEFT(),RIGHT()返回字符串最左边或最右边的几个字符

LPAD,RPAD(x,y,z)把x字符串用z字符补齐到y位

TRIM去除首尾空格

TRIM（s1 FROM s2）从s2中去除首尾的s1

CURDATE()：返回当前日期

CURTIME()：返回当前时间

**日期与时间戳的转换**

| 函数                     | 用法                                                         |
| ------------------------ | ------------------------------------------------------------ |
| UNIX_TIMESTAMP()         | 以UNIX时间戳的形式返回当前时间。SELECT UNIX_TIMESTAMP() ->1634348884 |
| UNIX_TIMESTAMP(date)     | 将时间date以UNIX时间戳的形式返回。                           |
| FROM_UNIXTIME(timestamp) | 将UNIX时间戳的时间转换为普通格式的时间                       |

**获取月份、星期、星期数、天数等函数**

| 函数                                     | 用法                                            |
| ---------------------------------------- | ----------------------------------------------- |
| YEAR(date) / MONTH(date) / DAY(date)     | 返回具体的日期值                                |
| HOUR(time) / MINUTE(time) / SECOND(time) | 返回具体的时间值                                |
| MONTHNAME(date)                          | 返回月份：January，...                          |
| DAYNAME(date)                            | 返回星期几：MONDAY，TUESDAY.....SUNDAY          |
| WEEKDAY(date)                            | 返回周几，注意，周1是0，周2是1，。。。周日是6   |
| QUARTER(date)                            | 返回日期对应的季度，范围为1～4                  |
| WEEK(date) ， WEEKOFYEAR(date)           | 返回一年中的第几周                              |
| DAYOFYEAR(date)                          | 返回日期是一年中的第几天                        |
| DAYOFMONTH(date)                         | 返回日期位于所在月份的第几天                    |
| DAYOFWEEK(date)                          | 返回周几，注意：周日是1，周一是2，。。。周六是7 |

**日期的操作函数**

| 函数                    | 用法                                       |
| ----------------------- | ------------------------------------------ |
| EXTRACT(type FROM date) | 返回指定日期中特定的部分，type指定返回的值 |

type可以是以下的：

![image-20220118144924240](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/image-20220118144924240.png)

![image-20220118144931517](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/image-20220118144931517.png)

**时间和秒钟转换的函数**

| 函数                 | 用法                                                         |
| -------------------- | ------------------------------------------------------------ |
| TIME_TO_SEC(time)    | 将 time 转化为秒并返回结果值。转化的公式为：`小时*3600+分钟*60+秒` |
| SEC_TO_TIME(seconds) | 将 seconds 描述转化为包含小时、分钟和秒的时间                |

**计算日期和时间的函数**

| 函数                                                         | 用法                                           |
| ------------------------------------------------------------ | ---------------------------------------------- |
| DATE_ADD(datetime, INTERVAL  expr type)，ADDDATE(date,INTERVAL expr type) | 返回与给定日期时间相差INTERVAL时间段的日期时间 |
| DATE_SUB(date,INTERVAL expr type)，SUBDATE(date,INTERVAL expr type) | 返回与date相差INTERVAL时间间隔的日期           |

type的取值为：

![image-20220118145318904](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/image-20220118145318904.png)

举例：

```
SELECT DATE_ADD(NOW(), INTERVAL 1 DAY)
```

| 函数                         | 用法                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| ADDTIME(time1,time2)         | 返回time1加上time2的时间。当time2为一个数字时，代表的是`秒`，可以为负数 |
| SUBTIME(time1,time2)         | 返回time1减去time2后的时间。当time2为一个数字时，代表的是`秒`，可以为负数 |
| DATEDIFF(date1,date2)        | 返回date1 - date2的日期间隔天数                              |
| TIMEDIFF(time1, time2)       | 返回time1 - time2的时间间隔                                  |
| FROM_DAYS(N)                 | 返回从0000年1月1日起，N天以后的日期                          |
| TO_DAYS(date)                | 返回日期date距离0000年1月1日的天数                           |
| LAST_DAY(date)               | 返回date所在月份的最后一天的日期                             |
| MAKEDATE(year,n)             | 针对给定年份与所在年份中的天数返回一个日期，第n天            |
| MAKETIME(hour,minute,second) | 将给定的小时、分钟和秒组合成时间并返回                       |
| PERIOD_ADD(time,n)           | 返回time加上n后的时间                                        |

**日期的格式化与解析**

格式化：日期转换为字符串

| 函数                              | 用法                                       |
| --------------------------------- | ------------------------------------------ |
| DATE_FORMAT(date,fmt)             | 按照字符串fmt格式化日期date值              |
| TIME_FORMAT(time,fmt)             | 按照字符串fmt格式化时间time值              |
| GET_FORMAT(date_type,format_type) | 返回日期字符串的显示格式                   |
| STR_TO_DATE(str, fmt)             | 按照字符串fmt对str进行解析，解析为一个日期 |

上述`非GET_FORMAT`函数中fmt参数常用的格式符：

| 格式符 | 说明                                                        | 格式符 | 说明                                                        |
| ------ | ----------------------------------------------------------- | ------ | ----------------------------------------------------------- |
| %Y     | 4位数字表示年份                                             | %y     | 表示两位数字表示年份                                        |
| %M     | 月名表示月份（January,....）                                | %m     | 两位数字表示月份（01,02,03。。。）                          |
| %b     | 缩写的月名（Jan.，Feb.，....）                              | %c     | 数字表示月份（1,2,3,...）                                   |
| %D     | 英文后缀表示月中的天数（1st,2nd,3rd,...）                   | %d     | 两位数字表示月中的天数(01,02...)                            |
| %e     | 数字形式表示月中的天数（1,2,3,4,5.....）                    |        |                                                             |
| %H     | 两位数字表示小数，24小时制（01,02..）                       | %h和%I | 两位数字表示小时，12小时制（01,02..）                       |
| %k     | 数字形式的小时，24小时制(1,2,3)                             | %l     | 数字形式表示小时，12小时制（1,2,3,4....）                   |
| %i     | 两位数字表示分钟（00,01,02）                                | %S和%s | 两位数字表示秒(00,01,02...)                                 |
| %W     | 一周中的星期名称（Sunday...）                               | %a     | 一周中的星期缩写（Sun.，Mon.,Tues.，..）                    |
| %w     | 以数字表示周中的天数(0=Sunday,1=Monday....)                 |        |                                                             |
| %j     | 以3位数字表示年中的天数(001,002...)                         | %U     | 以数字表示年中的第几周，（1,2,3。。）其中Sunday为周中第一天 |
| %u     | 以数字表示年中的第几周，（1,2,3。。）其中Monday为周中第一天 |        |                                                             |
| %T     | 24小时制                                                    | %r     | 12小时制                                                    |
| %p     | AM或PM                                                      | %%     | 表示%                                                       |

例如：

```
SELECT STR_TO_DATE('09/01/2009','%m/%d/%Y')
FROM DUAL;

SELECT STR_TO_DATE('20140422154706','%Y%m%d%H%i%s')
FROM DUAL;

SELECT STR_TO_DATE('2014-04-22 15:47:06','%Y-%m-%d %H:%i:%s')
FROM DUAL;
```

GET_FORMAT函数中date_type和format_type参数取值如下：

![image-20220118150803677](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/image-20220118150803677.png)

例如：

```
mysql> SELECT GET_FORMAT(DATE, 'USA');
SELECT DATE_FORMAT(NOW(),GET_FORMAT(DATE,'USA')),
FROM DUAL;
```

**流程控制函数**

| 函数                                                         | 用法                                            |
| ------------------------------------------------------------ | ----------------------------------------------- |
| IF(value,value1,value2)                                      | 如果value的值为TRUE，返回value1，否则返回value2 |
| IFNULL(value1, value2)                                       | 如果value1不为NULL，返回value1，否则返回value2  |
| CASE WHEN 条件1 THEN 结果1 WHEN 条件2 THEN 结果2 .... [ELSE resultn] END | 相当于Java的if...else if...else...              |
| CASE  expr WHEN 常量值1 THEN 值1 WHEN 常量值1 THEN 值1 .... [ELSE 值n] END | 相当于Java的switch...case...                    |

实例1：

```
SELECT last_name,salary,IF(salary>6000,'高工资','低工资')
FROM employees;  
```

实例2：

```
SELECT last_name,salary,IFNULL(commission_pct,0)
FROM employees;  
```

实例3：

```
SELECT last_name,salary,CASE WHEN salary<10000 THEN"rich"
			     WHEN salary>=10000 AND salary<20000 THEN "richer"
			     ELSE 'poorguy' END standard 
			     
FROM employees;  
//类似于java的if...else if...else if，最后的ELSE也可以去掉
```

实例4：

```
SELECT last_name,department_id,salary,CASE department_id WHEN 100 THEN "+"
							 WHEN 50 THEN "-"
							 WHEN 80 THEN "*"
							 WHEN 40 THEN "/"
							 ELSE "=" END standard 			     
FROM employees;
//类似于switch...case...
```



**加密与解密函数**

使用MD5(),SHA()对字符串进行加密，都是不可逆的

```
SELECT MD5('sha'),SHA('sha')
FROM DUAL;  
```

**其他函数**

BENCHMARK(n,expr):测试exor表达式执行n次所花费的时间

```
 SELECT BENCHMARK(10000000,MD5('sql'))
 FROM DUAL;
```

## 聚合函数

对一组数据作用，并返回一个值

常见聚合函数：

```
SELECT AVG(salary),SUM(salary)
FROM employees;
```

```
SELECT MAX(salary),MIN(salary)
FROM employees;
```

count：计算指定字段在查询结构中出现的次数

```
SELECT COUNT(salary)
FROM employees;
```

COUNT(*),COUNT(1)也可以计算次数

GROUP BY:分组

```
SELECT AVG(salary)
FROM employees
GROUP BY department_id;
```

select出现的字段必须声明在group by中，group by在from，where后，其他前

HAVING:用来过滤数据，如果过滤条件使用了聚合函数就要用having替换

HAVING放在GROUP BY后面

```
SELECT department_id,MAX(salary) m
FROM employees
GROUP BY department_id
HAVING m>10000;
```

## 子查询

```
SELECT last_name,salary
FROM employees
WHERE salary>(SELECT salary
		FROM employees
              WHERE last_name="Abel"
	      );
```

**单行子查询**：查询完只出来一条记录

HAVING中使用子查询：

```
SELECT department_id,MIN(salary)
FROM employees
WHERE department_id IS NOT NULL;
GROUP BY department_id
HAVING MIN(salary)>(
			SELECT MIN(salary)
			FROM employees
			WHERE department_id=50;
			)
```

**多行子查询**：

| 操作符 | 含义                                                         |
| ------ | ------------------------------------------------------------ |
| IN     | 等于列表中的**任意一个**                                     |
| ANY    | 需要和单行比较操作符一起使用，和子查询返回的**某一个**值比较 |
| ALL    | 需要和单行比较操作符一起使用，和子查询返回的**所有**值比较   |
| SOME   | 实际上是ANY的别名，作用相同，一般常使用ANY                   |

in的使用：

```
SELECT employee_id,last_name
FROM employees
WHERE salary IN(
		SELECT MIN(salary)
		FROM employees
		GROUP BY department_id
		)
```

ANY和ALL的使用：

```
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary < ANY(
		SELECT salary
		FROM employees
		WHERE job_id='IT_PROG'
		)
		
SELECT employee_id,last_name,job_id,salary
FROM employees
WHERE salary < ALL(
		SELECT salary
		FROM employees
		WHERE job_id='IT_PROG'
		)
```

**相关子查询**

```
SELECT last_name,salary,department_id
FROM employees e1
WHERE salary>(
		SELECT AVG(salary)
		FROM employees e2
		WHERE department_id=e1.department_id
		)
```

```
SELECT employee_id,salary
FROM employees e
ORDER BY(
		SELECT department_name
		FROM departments d
		WHERE e.department_id=d.department_id
		)ASC
```

**EXISTS和NO EXISTS关键字**

- **如果在子查询中不存在满足条件的行：**
  - 条件返回 FALSE
  - 继续在子查询中查找
- **如果在子查询中存在满足条件的行：**
  - 不在子查询中继续查找
  - 条件返回 TRUE

```
SELECT department_id, department_name
FROM departments d
WHERE NOT EXISTS (SELECT 'X'
                  FROM   employees
                  WHERE  department_id = d.department_id);
```



## 创建和管理表

### 创建数据库

```
1.
CREATE DATABASE 数据库名
2.
CREATE DATABASE 数据库名 CHARACTER SET 'utf8'//以哪种字符集来创建数据库
3.
CREATE DATABASE IF NOT EXISTS 数据库名
//不存在才创建，若存在也不报错
```

### 管理数据库

查看数据库:show databases，切换数据库：use +数据库名，查看当前数据库下保存的表：show tables，

查看当前使用的数据库：select database() from dual，查看指定数据库下保存的表：show tables from +数据库名

**修改数据库字符集**

```
ALTER DATABASE 数据库名 CHARACTER SET 'gbk'
```

*database不能改名*

**删除数据库**

```
DROP DATABASE IF EXISTS 数据库名
```

### 创建表

1. 

```
CREATE TABLE IF NOT EXISTS myemp1(
                                    id INT,
                                    emp_name VARCHAR(15),#使用varchar定义字符串，指明长度为15
                                    hire_date DATE
                                    );
```

2. 基于现有的表创建 

```
CREATE TABLE myemp2
AS
SELECT last_name,salary,employee_id
FROM employees
```

### **管理表**

**删除表**

```
DROP TABLE IF EXISTS myemp2
```

**修改表**

```
#增加字段
ALTER TABLE myemp1
ADD salary DOUBLE(10,2) #共10位小数点后面保留2位
AFTER emp_name #添加到empname后面

#修改一个字段
ALTER TABLE myemp1
MODIFY emp_name VARCHAR(25) #更改长度
DEFAULT 'aaa' #设置默认值

#重命名字段
ALTER TABLE myemp1
CHANGE salary mouth_salary DOUBLE(10,2) #改名的同时长度也可以修改

#删除一个字段
ALTER TABLE myemp1
DROP COLUMN id
```

**清空表**：表结构依然存在

```
TRANCATE TABLE myemp3
```

**重命名表**

```
RENAME TABLE myemp1
TO myemp11
```

**DCL中COMMIT和ROLLBACK**

commit：数据永久保存在数据库中，不可回滚

rollback：实现数据回滚，回滚到最近的一次commit**之后**

DDL的操作一旦执行就不能回滚，DML也是，但是可以在DML中事先执行` SET autocommit =FALSE`，在执行完一次DDL操作以后会默认执行一次COMMIT



## 数据处理的增删改

### 插入数据 

```
SELECT * 
FROM emp1;
#1.一条条的添加
INSERT INTO emp1
VALUES (1,'Tom','2002-5-6',5000);
	 #指明添加的字段
	 INSERT INTO emp1(id,salary,`name`,hire_date)
	 VALUES (2,6000,'Cat','2003-5-6');
	 #添加多条记录
	 INSERT INTO emp1(id,salary,`name`,hire_date)
	 VALUES (3,4000,'Tat','2004-5-6'),(4,8000,'Wat','2005-5-6');
#2.将查询结果插入
INSERT INTO emp1(id,salary,`name`,hire_date)

SELECT employee_id,salary,last_name,hire_date
FROM employees
WHERE department_id IN (50,60)
```

### 更新数据

```
UPDATE emp1
SET hire_date='2003-7-6'
WHERE `name`='Tat'
```

不加where条件可以实现批量修改

### 删除数据

```
DELETE FROM emp1
WHERE id>=103 AND id<=199
```



### 计算列

```
CREATE TABLE test1(
a INT,
b INT,
c INT GENERATED ALWAYS AS (a+b) VIRTUAL
)
```

c列的值设置为ab两列之和

## 数据类型

类型前加Unsighed表示无符号类型，表示正数

### 整数类型

BIGINT表示范围最大，一般使用INT

### 浮点类型

浮点数是不准确的，尽量不要使用=来判断两个浮点数是否相等

### 定点数类型

DECIMAL(m，n)：m是精度，n是标度

定点数在MySQL内部实际上是以字符串的形式存储的

### 日期与时间类型

TIME：时间，还可以用来表示时间间隔，DATE日期，TIMESTAMP：带时区

YEAR的范围1901-2155，插入00会转换为0000年，'00'会转换为2000年；

TIME中插入1210显示的是分钟秒

TIMESTAMP储存从1970-2038，可以用@符号分隔

### 文本字符串类型

CHAR：定长 VARCHAR：可变长度，根据实际存储的字符串长度决定其长度，都是存储较短的字符串

TEXT：储存长文本类型的字符串，不会删除尾部的空格

ENUM：枚举

```
CREATE TABLE test_enum(
season ENUM('春','夏','秋','冬')
);
```

每次只能从四个season中选一个添加，不在这里面的不行，一次性也不能添加多个

```
INSERT INTO test_enum
VALUES('秋'),('夏')
```

可以使用索引进行枚举元素的调用

```
INSERT INTO test_enum
VALUES(1),('3')
```

SET：可以选多个添加

```
CREATE TABLE test_set(
season SET('1','2','3','4')
);
```

```
INSERT INTO test_set (s) VALUES ('A'), ('A,B');

#插入重复的SET类型成员时，MySQL会自动删除重复的成员
INSERT INTO test_set (s) VALUES ('A,B,C,A');

#向SET类型的字段插入SET成员中不存在的值时，MySQL会抛出错误。
INSERT INTO test_set (s) VALUES ('A,B,C,D');

SELECT *
FROM test_set;
```

### 二进制字符串类型

主要存储一些二进制数据，比如可以存储图片、音频和视频等二进制数据

BINARY和VARBINARY：它们存储的是二进制字符串

BLOB：存储二进制的大对象，图片，视频等

```
CREATE TABLE test_blob1(
id INT,
img MEDIUMBLOB
);
```

### JSON类型

是一种轻量级的`数据交换格式`，**JSON 可以将 JavaScript 对象中表示的一组数据转换为字符串，然后就可以在网络或者程序之间轻松地传递这个字符串，并在需要的时候将它还原为各编程语言所支持的数据格式。**

```
CREATE TABLE test_json(
js json

);
```

## 约束

对表中字段的限制

### 非空约束

NOT NULL

不可组合约束，只能某个列单独限定为非空

创建格式：

```
CREATE TABLE test1(
id INT NOT NULL,
last_name VARCHAR(15) NOT NULL,
email VARCHAR(25),
salary DECIMAL(10,2)
)
```

alter table时约束：

```
ALTER TABLE test1
MODIFY email VARCHAR(25) NOT NULL;
```

删除约束：

```
ALTER TABLE test1
MODIFY email VARCHAR(25) NULL;
```

### 唯一性约束

限制某个字段或者某一列不能重复

```
CREATE TABLE test2(
id INT UNIQUE,#列级约束
last_name VARCHAR(15),
email VARCHAR(25),
salary DECIMAL(10,2),

#表级约束:要在最后列加上逗号再进行表级约束
CONSTRAINT uk_test2 UNIQUE(email)
)
```

alter table时添加约束：

```
ALTER TABLE test2
ADD UNIQUE(salary);
```

复合的唯一性约束：表级约束的UNIQUE（）括号内添加两个字段名，只有添加数据时两个字段名中有一个不一样就能添加成功

删除约束：

INDEX 后面的是索引名，与约束名相同，若没有指定约束名，则与字段名相同 

```
ALTER TABLE test2
DROP INDEX uk_test2
```

### PRIMARY KEY约束

类似于唯一+非空约束，一个表只能有一个主键约束，不能为空

创建约束：

```
CREATE TABLE test5(
id INT ,
last_name VARCHAR(15),
email VARCHAR(25),
salary DECIMAL(10,2),

#表级约束:要在最后列加上逗号再进行表级约束
PRIMARY KEY(email)
)
```

删除约束：因为主键约束的index名字固定为PRIMARY

```
ALTER TABLE test2
DROP PRIMARY
```

### 自增列：AUTO_INCREMENT

让某个字段的值自增，字段的类型只能为INT,在主键上用

### FOREIGN KEY约束

限定某个字段的引用完整性，比如employees（从表）中的department_id与departments（主表）的department_id相匹配，如果往employees中添加的department_id与departments的不匹配就报错

+ 先创建主表再从表，删除相反
+ 被关联的主表字段必须是主键

创建：

```
create table dept( #主表
	did int primary key,		#部门编号
    dname varchar(50)			#部门名称
);

create table emp(#从表
	eid int primary key,  #员工编号
    ename varchar(5),     #员工姓名
    deptid int,				#员工所在的部门
    #表级约束
    foreign key (deptid) references dept(did)   #在从表中指定外键约束
    #emp表的deptid和和dept表的did的数据类型一致，意义都是表示部门的编号
);
```

#### 约束等级

* `Cascade方式`：在父表上update/delete记录时，同步update/delete掉子表的匹配记录 

* `Set null方式`：在父表上update/delete记录时，将子表上匹配记录的列设为null，但是要注意子表的外键列不能为not null  

* `No action方式`：如果子表中有匹配的记录，则不允许对父表对应候选键进行update/delete操作  

* `Restrict方式`：同no action， 都是立即检查外键约束

* `Set default方式`（在可视化工具SQLyog中可能显示空白）：父表有变更时，子表将外键列设置成一个默认的值，但Innodb不能识别

如果没有指定等级，就相当于Restrict方式。

示例：

```
create table dept(
	did int primary key,		#部门编号
    dname varchar(50)			#部门名称
);

create table emp(
	eid int primary key,  #员工编号
    ename varchar(5),     #员工姓名
    deptid int,				#员工所在的部门
    foreign key (deptid) references dept(did)  on update cascade on delete set null
    #把修改操作设置为级联修改等级，把删除操作设置为set null等级
);

#update操作
update dept set did = 1004 where did = 1002;
#delete操作
delete from dept where did = 1001;
```

### check约束

检查某个字段的值是否符合xx要求，一般指的是值的范围

```
CREATE TABLE test5(
id INT ,
last_name VARCHAR(15),
email VARCHAR(25),
salary DECIMAL(10,2) (CHECK salary>2000)
)
```

### DEFAULT约束

给某个字段/某列指定默认值，一旦设置默认值，在插入数据时，如果此字段没有显式赋值，则赋值为默认值。

```
create table 表名称(
	字段名  数据类型  primary key,
    字段名  数据类型  unique key not null,  
    字段名  数据类型  unique key,
    字段名  数据类型  not null default 默认值, 
);
```

## 视图

视图一方面可以帮我们使用表的一部分而不是所有的表，另一方面也可以针对不同的用户制定不同的查询视图。

视图本身的删除不会影响到基表本身的数据的删除

**创建视图：**

```
CREATE VIEW 视图名称 
AS 查询语句
```

**单表视图：**

```
CREATE VIEW empvu80
AS 
SELECT  employee_id, last_name, salary
FROM    employees
WHERE   department_id = 80;
```

**多表联合视图：**

```
CREATE VIEW empview 
AS 
SELECT employee_id emp_id,last_name NAME,department_name
FROM employees e,departments d
WHERE e.department_id = d.department_id;
```

**查看视图**

```
SHOW TABLES;
```

查看视图的属性信息：

```
# 查看视图信息（显示数据表的存储引擎、版本、数据行数和数据大小等）
SHOW TABLE STATUS LIKE '视图名称'\G
```

**修改视图：**

```
ALTER VIEW 视图名称 
AS
查询语句
```

