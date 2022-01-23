# 寒假笔记Day5

## Leetcode每日三题

### [263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

首先，n是非正数，即<=0，则一定不是丑数， 然后再对2，3，5开始除， 如果最后的结果为1，则是丑数， 否则不是

```
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        return n == 1;
    }
};
```

### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)

两种特殊情况要对付：数组为空和字符串为空，双重for一重遍历数组，一重遍历字符串，通过一个遍历找到所有字符串的最短长度，定义一个count等于数组的长度，说明这个字符是公共字符。记录到s里面，之后返回s

```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string s;
        
        if (len == 0)
        {
            return s;
        }
        if (len == 1)
        {
            return strs[0];
        }
        int min = INT_MAX;
        for (int k = 0; k < len; k++)
        {
            int strSize = strs[k].size();
            if (min > strSize)
            {
                min = strSize;
            }
        }
        for(int i=0;i<min;++i)
        {
            int count=0;
            char temp=strs[0][i];
            for(int j=0;j<len;j++)
            {
                if(strs[j][i]==temp)
                count++;            
            }
            if(count==strs.size())
            {
                s+=strs[0][i];
            }
            else
            break;
        }
        return s;
    }
};

```

### [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)

先定义nm储存st的长度，if判断如果子串是大于主串的话，那么就直接返回false，再用for遍历t的如果找到一个就把s的指针加一，继续往后遍历，当len的长度到达n的时候，就说明for循环中找到了所有s中元素。返回true

```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n>m)
            return false;
        int len=0;
        for(int i=0;i<m;i++)
        {
            if(s[len]==t[i])
                len++;
        }
        if(len==n)
            return true;
        return false;
    }
};
```



## Vue框架基础知识

### 简介

Vue 是一套用于构建用户界面的**渐进式框架**。与其它大型框架不同的是，Vue 被设计为可以自底向上逐层应用。Vue 的核心库只关注视图层。

使用`<script>` 标签引入Vue

```
$ npm install vue
 <script src="./node_modules/vue/dist/vue.js"></script>
```

#### 声明式渲染

- 创建vue实例，关联页面的模板，将自己的数据（data）渲染到关联的模板，响应式的
- 指令来简化对dom的一些操作。
- 声明方法来做更复杂的操作。methods里面可以封装方法。

```
    <div id="app">
        <input type="text" v-model="num">
        <button v-on:click="num++">点赞</button>
        <button v-on:click="cancle">取消</button>
        <h1> {{name}} ,非常帅，有{{num}}个人为他点赞{{hello()}}</h1>
    </div>

    <script src="./node_modules/vue/dist/vue.js"></script>

    <script>
        //1、vue声明式渲染
        let vm = new Vue({
            el: "#app",//绑定元素
            data: {  //封装数据
                name: "张三",
                num: 1
            },
            methods:{  //封装方法
                cancle(){
                    this.num -- ;
                },
                hello(){
                    return "1"
                }
            }
        });
    </script>
```

####  文本插值

数据绑定最常见的形式就是使用“Mustache”语法 (双大括号) 的文本插值：

    <span>Message: {{ msg }}</span>

Mustache 标签将会被替代为对应数据对象上 msg property 的值。无论何时，绑定的数据对象上 msg property 发生了改变，插值处的内容都会更新。

### 指令

指令 (Directives) 是带有 v- 前缀的特殊 attribute。指令 attribute 的值预期是单个 JavaScript 表达式 。指令的职责是，当表达式的值改变时，将其产生的连带影响，响应式地作用于 DOM。

#### v-text：显示文本原始内容，不对html元素进行解析

#### v-html：显示html解析后的内容

        <div id="app">
            <span v-html="msg"></span>	<!-- Hello(h1的大小) -->
            <br/>
            <span v-text="msg"></span> 	<!-- <h1>Hello</h1> -->
    
        </div>
    
        <script src="../node_modules/vue/dist/vue.js"></script>
    
        <script>
            new Vue({
                el:"#app",
                data:{
                    msg:"<h1>Hello</h1>",
                },
            })
        </script>


#### v-bind

单向绑定

vue对象中的值变化会影响绑定标签，反之不会影响

缩写

<a v-bind:href="url">可以缩写为<a :href="url">

属性绑定

给html标签的属性绑定

给class，style的值进行绑定： {class名：属性名(boolean)}/{style属性名：属性值} 

     <!-- 给html标签的属性绑定 -->
        <div id="app"> 
    
            <a v-bind:href="link">gogogo</a>
    
            <!-- 只有isActive、hasError为ture时，才有active和text-danger class-->
            <!-- style的color属性值为vue对象中color1的值 -->
            <span v-bind:class="{active:isActive,'text-danger':hasError}" 
                        :style="{color: color1,fontSize: size}">你好</span>
            <a v-bind:href="link">abc</a>
    
        </div>
    
        <script src="../node_modules/vue/dist/vue.js"></script>
    
        <script>
            let vm = new Vue({
                el:"#app",
                data:{
                    link: "http://www.baidu.com",
                    isActive:true,
                    hasError:true,
                    color1:'red',
                    size:'36px'
                }
            })
        </script>

#### v-model

双向绑定，绑定的属性值会反过来影响vue对象中的值

	<!-- 表单项，自定义组件 -->
	<div id="app">
	
	    精通的语言：
	        <input type="checkbox" v-model="language" value="Java"> java<br/>
	        <input type="checkbox" v-model="language" value="PHP"> PHP<br/>
	        <input type="checkbox" v-model="language" value="Python"> Python<br/>
	    选中了 {{language.join(",")}}
	</div>
	
	<script src="../node_modules/vue/dist/vue.js"></script>
	
	<script>
	    <!-- 当上面复选框被选中时，language的值就会变化-->
	    let vm = new Vue({
	        el:"#app",
	        data:{
	            language: []
	        }
	    })
	</script>

#### v-on

监听事件

语法规则`v-on:[eventName]`

```
<button v-on:click="num++">点赞</button>
```

**事件修饰符**

修饰符是由点开头的指令后缀来表示的；

修饰符可以串联

    .stop 阻止单击事件继续传播
    .prevent 标签本身效果不会执行
    .capture 内部元素触发的事件先在此处理，然后才交由内部元素进行处理
    .self event.target 是当前元素自身时触发处理函数
    .once 点击事件将只会触发一次


<!-- 仅会触发一次点击事件 -->

<div style="border: 1px solid red;padding: 20px;" v-on:click.once="hello">
    大div
    <!-- 仅会触发小div的click事件，不会传播至大div的click事件 -->
    <div style="border: 1px solid blue;padding: 20px;" @click.stop="hello">
        小div <br />
        <!-- 同时触发大小div的click事件，但不会触发超链接 -->
        <a href="http://www.baidu.com" @click.prevent="hello">去百度</a>
    </div>
</div>

**按键修饰符**

使用格式：`v-on:keyup.按键名`

当点击这些按键时才会触发事件

- `.enter`
- `.tab`
- `.delete` (捕获“删除”和“退格”键)
- `.esc`
- `.space`
- `.up`
- `.down`
- `.left`
- `.right`

```
<!-- 按up num+2，按down num-2，同时点击和按ctrl num=10 -->
<input type="text" v-model="num" v-on:keyup.up="num+=2" @keyup.down="num-=2" @click.ctrl="num=10"><br />
```

#### v-for

遍历数组：`v-for="item in items`

若要获取数组下标：`v-for="(item,index) in items`

遍历对象：

```
v-for="value in object"
v-for="(value,key) in object"
v-for="(value,key,index) in object" 
```

注意：遍历的时候都加上:key来区分不同数据，提高vue渲染效率

```
v-for="(user,index) in users" :key="user.name"
```

#### v-if 和 v-sho

`v-if`：条件判断。当得到结果为true时，所在的元素才会被渲染。

`v-show`：当得到结果为true时，所在的元素才会被显示，false时元素依然存在，只是添加了不显示的样式

```
<div id="app">
    <button v-on:click="show = !show">点我呀</button>
     <!-- 当show为true时才会显示标签 -->
    <!-- 1、使用v-if显示 -->
    <h1 v-if="show">if=看到我....</h1>
    <!-- 2、使用v-show显示 -->
    <h1 v-show="show">show=看到我</h1>
</div>
<script src="../node_modules/vue/dist/vue.js"></script>    
<script>
    let app = new Vue({
        el: "#app",
        data: {
            show: true
        }
    })
</script>
```

#### v-else和v-else-if

话不多说，直接上代码


    <div id="app">
            <button v-on:click="random=Math.random()">点我呀</button>
            <span>{{random}}</span>
            <h1 v-if="random>=0.75">
                看到我啦？！ &gt;= 0.75
            </h1>
            <h1 v-else-if="random>=0.5">
                看到我啦？！ &gt;= 0.5
            </h1>
            <h1 v-else-if="random>=0.2">
                看到我啦？！ &gt;= 0.2
            </h1>
            <h1 v-else>
                看到我啦？！ &lt; 0.2
            </h1>
        </div>
    
        <script src="../node_modules/vue/dist/vue.js"></script>
            
        <script>         
            let app = new Vue({
                el: "#app",
                data: { random: 1 }
            })     
        </script>
### 计算属性和侦听器

#### 计算属性

某些结果是基于之前数据实时计算出来的，我们可以利用计算属性来完成

```
<div id="app">

    <ul>
        <li>西游记； 价格：{{xyjPrice}}，数量：<input type="number" v-model="xyjNum"> </li>
        <li>水浒传； 价格：{{shzPrice}}，数量：<input type="number" v-model="shzNum"> </li>
        <!-- 计算得到的属性值 -->
        <li>总价：{{totalPrice}}</li>
        <li>总数量:{{totalNum}}</li>
        <!-- 显示侦听器的信息 -->
        {{msg}}
    </ul>
</div>
<script src="../node_modules/vue/dist/vue.js"></script>
<script>
    new Vue({
        el: "#app",
        data: {
            xyjPrice: 99.98,
            shzPrice: 98.00,
            xyjNum: 1,
            shzNum: 1,
            msg: ""
        },
        //计算属性，总价和总数量会根据实时数据进行计算得出
        computed: {
            totalPrice(){
                return this.xyjPrice*this.xyjNum + this.shzPrice*this.shzNum
            },
            totalNum(){
                return this.xyjNum*1+this.shzNum*1;
            }
        },
    })
</script>
```

####  侦听器

Vue 通过 `watch` 选项提供了一个更通用的方法，来响应数据的变化。

      new Vue({
                el: "#app",
                data: {
                    xyjPrice: 99.98,
                    shzPrice: 98.00,
                    xyjNum: 1,
                    shzNum: 1,
                    msg: ""
                },
             	
          		......
             	//侦听shzNum值的变化
                watch:  {
                    shzNum(newVal,oldVal){
                        if(newVal>=4){
                            this.msg="水浒传库存超出限制";
                            this.shzNum=4
                        }else{
                            this.msg=""
                        }
                    }
                },
            })

#### 过滤器

用于一些常见的文本格式化。过滤器可以用在两个地方：**双花括号插值和 `v-bind` 表达式**。过滤器应该被添加在 JavaScript 表达式的尾部，由“管道”符号指示：

```
<!-- 在双花括号中 -->
{{ message | capitalize }}

<!-- 在 `v-bind` 中 -->
<div v-bind:id="rawId | formatId"></div>
```

### 组件化

通过定义组件就可以通过组件名组件标签进行组件模板复用

```
Vue.component("组件名称",{
template:'
<div>
<button @click="handleback"></button>
组件的html代码
</div>
',//模板
methods:{
//组件的js逻辑
handleback(){
},
handlehome(){
}
}
})
```

局部组件

```
Vue.component("组件名称",{
template:'
<div>
<button @click="handleback"></button>
组件的html代码
<name></name>
</div>
',//模板
components:{
"name":{
template:'
局部组件
'
}
}
})
```

### 生命周期钩子函数

```
beforeCreate()//创建前

created() //创建完成

beforeMount() // 挂载前

mounted() //挂载后

beforeUpdate() //更新前
updated() //更新后
```

每个 Vue 实例在被创建时都要经过一系列的初始化过程——例如，需要设置数据监听、编译模板、将实例挂载到 DOM 并在数据变化时更新 DOM 等。同时在这个过程中也会运行一些叫做**生命周期钩子**的函数，这给了用户在不同阶段添加自己的代码的机会。

引用csdn上的一张图帮助理解：

![060b45da6b0f95f82b579681c399967b](https://gitee.com/grandelai/imagestore/raw/master/imagetostore/060b45da6b0f95f82b579681c399967b.png)

常用的函数：

1. mounted: 发送ajax请求、启动定时器、绑定自定义事件、订阅消息等【初始化操作】。
2. beforeDestroy: 清除定时器、解绑自定义事件、取消订阅消息等【收尾工作】。

### ES6+ 特性

#### let

- let声明的变量不存在预解析
- let声明的变量在同一个作用域内不允许重复

```
//js预解析概念
//在js中，代码并不是逐句解析的，js在执行代码前会将var和function开头的语句块提前进行处理
//关键字调用
console.log(a);
var a=1;
//等效于
var a;//声明变量
console.log(a);//undefined
a=1;

//而let关键字则会报错，它不存在预解析
console.log(a);//error:Cannot access 'a' before initialization
let a = 1;
```

let引入新概念：块级作用域

```
//js中有全局作用域和函数作用域两个概念，ES6引入块级作用域
//块级作用域限定在括号里，括号里的变量不会被外部访问
//for循环()中用let声明的变量只能在循环体内使用
for(let i=0;i<5;i++){
	console.log(i);//0，1，2，3，4
} 
console.log(i); //无法访问内部变量i,error: i is not defined

```

#### const

1. 声明常量必须初始化，一定要有初始值

2. （潜规则）常量名大写

3. 常量值不能修改

```
//注意：对于数组和对象的元素修改，不算作对常量的修改
const A = ['ERRUI0', 'ERRUI1', 'ERRUI2', 'ERRUI3'];
A.push('ERRUI4'); //不报错，
console.log(A); //常量地址没有发生变化,["ERRUI0", "ERRUI1", "ERRUI2", "ERRUI3", "ERRUI4"]
```

#### 变量解构赋值

```
/* 数组解构 */
const arr = [100, 200, 300]
const [foo, bar, baz] = arr
console.log(foo, bar, baz)

const [, , baz] = arr
console.log(baz)

const [foo, ...rest] = arr
console.log(rest)

const [foo, bar, baz, more] = arr
console.log(more) // undefined

const [foo, bar, baz = 123, more = 'default'] = arr
console.log(baz, more)

/* 对象解构 */
const obj = { name: 'zce', age: 18 }
const { name } = obj
console.log(name)

const age = 28
const { age: objAge } = obj
// const { age: objAge = 18 } = obj
```

#### 箭头函数

箭头函数this根据外层（函数或者全局）上下文来决定，指向为外层this的指向。

```
const obj = {
  name: '123',
  a () {
    console.log(this)
  },
  b: () => {
    console.log(this)
  },
  c () {
    setTimeout(() => {
      console.log(this)
      setTimeout(() => {
        console.log(this)
      }, 1000);
    }, 1000);
  },
  d: () => {
    setTimeout(() => {
      console.log(this)
    }, 1000);
  }
}

obj.a() // obj
obj.b() // window
obj.c() // obj obj
obj.d() // window
```



## 编写一个 Todolist Demo

创建的todolist项目src的文件夹下：

assets：存放动态资源

components：存放一般组件

router：配置路由

store：配置状态管理

views：放路由组件



组件：是维护单一功能，可复用的个体，界面的当个功能抽离出为组件，方便维护，复用性增强

定义组件：

```
<script>
// 编写js内容
import{defineComponent}from 'vue'
export default defineComponent({
  name:'Home', //组件名称
  //接收父组件的数据
  props:{
 
  },
  //定义子组件
  components:{

  },
  setup(props,ctx){
    return{

    }
  }
})
</script>
```

定义数据

ref定义单个数据

ref是一个方法，里面是数据的初始值。   


```
如果利用ref函数将某个对象中的属性变成响应式数据，修改响应式数据是不会影响到原始数据。
>ref的本质是深层拷贝，与原始数据没有引用关系
```js
 setup () {
    const obj = { name: 'alice', age: 12 }
    const num = 7

    const newObj = ref(obj.name)
    const newNum = ref(num)

    function change () {
      newObj.value = 'Tom'
      newNum.value=99
      console.log(obj, newObj)
      console.log(num, newNum)

    }
    change()
    return { newObj, change }
  }
```

reactive 定义对象类型数据

```
setup(props,ctx){
    let data =reactive({
        arr:['a','b'],
        num:10,
        obj ={
            age:20
        }
    })
    return {data}
}
// 页面中使用 
// js中使用
```

toRef

使用toRef将某个对象中的属性变成响应式数据，修改响应式数据是会影响到原始数据的。 但是需要注意，如果修改通过toRef创建的响应式数据，并不会触发UI界面的更新。 所以，toRef的本质是引用，与原始数据有关联

```
setup () {
    const obj = { name: 'alice', age: 12 }
    const newObj = toRef(obj, 'name')
    function change () {
      newObj.value = 'Tom'
      console.log(obj, newObj)
    }
    return { newObj, change }
  }
```

```
<button @click="change">change</button>
```

toRefs() 将某个对象中的属性变成响应式数据

toRefs接收一个对象作为参数，它会遍历对象身上的所有属性，然后挨个调用toRef执行

```
setup(props,ctx){
    let data =reactive({
        arr:['a','b'],
        num:10,
        obj ={
            age:20
        }
    })
    function change () {
      data.num = '11'
    }
    return {...toRefs(data),change}
}

页面中使用
```

ref和toRef的区别

1. ref本质是拷贝，修改响应式数据不会影响原始数据；toRef的本质是引用关系，修改响应式数据会影响原始数据
2. ref数据发生改变，界面会自动更新；toRef当数据发生改变是，界面不会自动更新
3. toRef传参与ref不同；toRef接收两个参数，第一个参数是哪个对象，第二个参数是对象的哪个属性
4. 所以如果想让响应式数据和以前的数据关联起来，并且想在更新响应式数据的时候不更新UI，那么就使用toRef

优化 toRef和reactive一起使用

```
setup () {
    const obj = reactive({ name: 'alice', age: 12 })
    const newObj = toRef(obj, 'name')
    function change () {
      newObj.value = 'Tom'
      console.log(obj, newObj)
    }
    return { newObj, change }
  }
```

定义方法

```
```html
<button @click="test(10)">test</button>
```

状态管理的index.js

```
import { createStore } from 'vuex'
export default createStore({
  state: {
    name: 'jack',
    list: [
      {
        title: '吃饭',
        complete: false
      },
      {
        title: '睡觉',
        complete: false
      }
    ]
  },
  mutations: {
    setName (state, params) {
      state.name = name
    },
    addTodo (state, payload) {
      state.list.push(payload)
    },
    delTodo (state, payload) {
      // 删除splice(下标,个数)
      state.list.splice(payload, 1)
    },
    // 清除已完成 payload过滤后的数组
    clear (state, payload) {
      state.list = payload
    }
  },
  actions: {
    asyncSetName (store, params) {
      setTimeout(() => {
        // commit 提交mutations
        store.commit('setName', params)
      }, 3000)
    }
  },
  // 模块化 以后讲解
  modules: {
  }
})
```

计算属性computed的使用

```
import { ref, computed } from 'vue'
export default {
  name: 'Home',
  components: {},
  setup () {
    const num1 = ref(10)
    const num2 = ref(2)
    const addNum = computed(() => {
      // 必须返回一个值
      return num1.value + num2.value
    })
    return { addNum, num1, num2}
  }
}
```

```
 <div>
    num1:+num2:=
  </div>
```

通过计算属性获取vuex中的state

```
import { ref, computed } from 'vue'
import { useStore } from 'vuex'

export default {
  name: 'Home',
  components: {},
  setup () {
    const store = useStore()
    // 通过计算属性拿到store.state
    const list = computed(() => { 
        return store.state.list 
    })
    return { list }
  }
}
```

剩下的部分没敲完。。。。。



## 今日任务总结：

今天主要学习了js框架vue的知识，知道了vue框架的基本使用，甚至有点想从后端跑路来前端，但是最后的todolistdemo没有做完，可能是前面刷题和vue框架基本学习占用了较多时间吧