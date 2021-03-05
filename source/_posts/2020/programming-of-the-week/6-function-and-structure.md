---
title: MSC 每周两题：去年题解 & 函数与结构体
date: 2021-3-4 11:33:02
categories:
- [C++]
- [MSC 每周两题]
author: 小灰晖
tags: 小灰晖
---

《时隔一年，小灰灰终于想起了俱乐部的 GitHub 账号》

<!-- More -->

## 系列目录

1. [MSC 每周两题：前言 & 顺序结构](/2020/11/13/2020-programming-of-the-week-1-preface-and-sequential/)
2. [MSC 每周两题：上周题解 & 分支结构](/2020/11/20/2020-programming-of-the-week-2-branch/)
3. [MSC 每周两题：上周题解 & 循环结构](/2020/11/27/2020-programming-of-the-week-3-loop/)
4. [MSC 每周两题：上周题解 & 数组](/2020/12/15/2020-programming-of-the-week-4-array/)
5. [MSC 每周两题：上周题解 & 字符串](/2020/12/25/2020-programming-of-the-week-5-string/)
6. [MSC 每周两题：去年题解 & 函数和结构体](/2021/03/04/2020-programming-of-the-week-6-function-and-structure/)
7. MSC 每周两题：上周题解 & 后记

## P1914 小书童——凯撒密码

众所周知，C 语言的字符串就是元素为 `char` 的数组，只是在输入输出时可以一次完成，不用像 `int` 数组一样需要 `for` 逐个读入。

这个题目要求把每个字符向后移动一位，超过 `z` 就重新从 `a` 开始计算。我们运用 `for` 逐个计算即可。~~这题好像没什么好说的~~

```c++
#include<stdio.h>

int main()
{
    int n;
    char str[50];
    scanf("%d%s", &n, str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] += n;
        if (str[i] > 'z')
            str[i] -= 26;
    }
    printf("%s", str);
}
```

然后有两个测试点挂了 hhhhhh

------------------

emmm 再读了一遍题目，似乎是没说 n 的范围，n 可能大于 26，导致结果超出范围了。

这里有两个解决办法：一是将里面的 `if` 改为 `while`，通过反复减就可以把结果控制在 a~z 范围内了；二是输入 n 后将 n 对 26 取模，这样就可以保证只用 if 减一次就可以在范围内。

------------------

第二遍提交又挂了（

看了一下题解，发现由于 `char` 的范围是 `-128~127`，直接加可能导致越界，（`'z' + 26 = 122 + 26 = 148`）。可以先转成 `int` 再加。

第三次总算是过了 hhh

```cpp
// C++ 版本
#include<stdio.h>

int main()
{
    int n;
    char str[50];
    scanf("%d%s", &n, str);
    n %= 26;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int temp = str[i] + n;
        if (temp > 'z')
            temp -= 26;
        str[i] = temp;
    }
    printf("%s", str);
}
```

最后有一个细节需要注意，C 语言求字符串长的 `strlen` 函数，每使用一次就会遍历一遍整个字符串，如果放在 for 里写成 `for (int i = 0; i < strlen(str); i++)` 会导致重复计算，效率变低。有三种解决方案：

1. 使用上面的方法，即使用 `str[i] != 0` 作为循环条件
2. 提前存储长度 `int len = strlen(str); for (int i = 0; i < len; i++)`
3. 不使用 char[] 类型，而是使用 C++ string 类

三种方法任选一种即可。

--------------------

以下是 Python3 版本：

```py
n = int(input())
n %= 26
string = input().strip()
newstring = ''

for c in string:
    temp = n + ord(c)
    if temp > ord('z'):
        temp -= 26
    newstring += chr(temp)

print(newstring)
```

## P1597 语句解析

语句解析这个题挺有意思，像是编译原理。当然，没必要用这么高深的知识。

我们只需要做三件事情：

1. 读取语句，解析等号左边和右边的变量（或数字）；
2. 将右边的变量（或数字）转换为值；
3. 将值赋给左边的变量。

如何将字符 `'a'` 解析为变量 `a` 呢？在 C / C++ 中，由于变量都会被编译为 `0x12345678` 这样的内存，所以没办法方便地从字符串解析为变量名。

### 方法一

最容易想到的，也是最麻烦的，就是用类似于下面的 `if` 判断：

```c++
int value; 
if (ch == 'a')
    value = a;
else if (ch == 'b')
    value = b;
else if (ch == 'c')
    value = c;
```

这种方式好处就是很直观，坏处就是变量一多，就会很麻烦了，还不能自定义变量，只能靠题目提前告诉我们变量有哪些。

### 方法二

注意到 `'a'` `'b'` `'c'` 是连续的 char，我们可以用一个数组 `int variable[3]` 模拟存储它们的值，需要存储/读取时，使用 `variable[input-'a']` 即可。

```c++
#include<stdio.h>

int main()
{
    int variable[3] = { 0 };
    char left_value, right_value;
    while (scanf("%c:=%c;", &left_value, &right_value) != EOF)
    {
        int value;
        if (right_value >= 'a')
            value = variable[right_value - 'a'];
        else
            value = right_value - '0';
        variable[left_value - 'a'] = value;
    }
    for (int i = 0; i < 3; i++)
        printf("%d ", variable[i]);
}
```

### 方法三

方法三就超出了 C 语言的范围了，而是使用了 C++ 的 map。map 可以将值映射到值，我们如果把字符 a b c 分别映射到各自的变量对应的值，就完美解决了此题的需求。

当然，方法二也是一种映射，其映射关系是 `variable[right_value - 'a']`。硬说的话，其实方法一也是映射，只是说它的映射关系是一堆复杂的 `if`（分段函数的事，怎么能说复杂呢）。

不过 C++ 的 map 如果再配合 string，就能映射字符串（而不只是单个字符）。C 语言有很多替代方法，但不如 map 来得快。

```cpp
#include<stdio.h>
#include<map>

int main()
{
    std::map<char, int>variable;
    char left_value, right_value;
    while (scanf("%c:=%c;", &left_value, &right_value) != EOF)
    {
        int value;
        if (right_value >= 'a')
            value = variable[right_value];
        else
            value = right_value - '0';
        variable[left_value] = value;
    }
    for (char i = 'a'; i <= 'c'; i++)
        printf("%d ", variable[i]);
}
```

### Python

Python 由于自带了 dict 类型，类似于 C++ map，所以这类问题很方便。就是解析语句时没有 C 语言 `scanf` 那么方便。

```py
statements = input().strip().strip(';').split(';')
variable = {'a': '0', 'b': '0', 'c': '0'}

for statement in statements:
    left_value, right_value = statement.split(':=')
    if right_value >= 'a':
        variable[left_value] = variable[right_value]
    else:
        variable[left_value] = right_value

print(variable['a'], variable['b'], variable['c'])
```

## 本周题单：函数和结构体

本周的题单，也是最后一个专题，是[函数与结构体](https://www.luogu.com.cn/training/105)。

下面的题目不多，但挺有意思。

函数里面，最复杂，包含知识点最多的，就是递归了。所以我们挑一个比较典型的递归来做：[P5727 【深基5.例3】冰雹猜想](https://www.luogu.com.cn/problem/P5727)

还有就是我们之前留的最后一个坑：判断一个日期是否合法。请同学们封装成一个函数（如果需要的话，可以创建更多的函数），并自行测试情况正确与否。

下周末将会针对这两个题开一次沙龙讲解，之后会放出题解~
