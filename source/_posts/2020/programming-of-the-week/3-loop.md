---
title: MSC 每周两题：上周题解 & 循环结构
date: 2020-11-27 12:00:00
categories:
- [C++]
- [MSC 每周两题]
author: 小灰晖
tags: 小灰晖
---

分支结构的题解！

<!-- More -->

## 系列目录

1. [MSC 每周两题：前言 & 顺序结构](/2020/11/13/2020-programming-of-the-week-1-preface-and-sequential/)
2. [MSC 每周两题：上周题解 & 分支结构](/2020/11/20/2020-programming-of-the-week-2-branch/)
3. [MSC 每周两题：上周题解 & 循环结构](/2020/11/27/2020-programming-of-the-week-3-loop/)
4. [MSC 每周两题：上周题解 & 数组](/2020/12/15/2020-programming-of-the-week-4-array/)
5. [MSC 每周两题：上周题解 & 字符串](/2020/12/25/2020-programming-of-the-week-5-string/)
6. [MSC 每周两题：去年题解 & 函数和结构体](/2021/03/04/2020-programming-of-the-week-6-function-and-structure/)
7. MSC 每周两题：上周题解 & 后记

## P5712 【深基3.例4】Apples

[P5712 【深基3.例4】Apples](https://www.luogu.com.cn/problem/P5712)。最容易想到的方法就是用 `if` 分为两种情况：加 `s` 和不加 `s` 的，然后分别输出。

```cpp
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 1)
        printf("Today, I ate %d apple.", n);
    else
        printf("Today, I ate %d apples.", n);
}
```

如果你学过字符串和三目运算符，这道题还有另一个简洁的写法：

```cpp
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("Today, I ate %d apple%s.", n, n <= 1 ? "" : "s");
}
```

如果没有学过的话，你可以三目运算符认为是 `if` 的简化版：这个表达式的值会根据 `?` 前面的条件（即 `n <= 1`）进行选择：

* 如果 `n <= 1`，表达式的值为 `:` 前的值（即 `""`）
* 如果 `n > 2`，表达式的值为 `:` 后的值（即 `"s"`）

程序经过判断后计算出了表达式的值，然后就可以在输出 `apple` 后输出一个 `s`，或什么都不输出。

------------------

## P5711 【深基3.例3】闰年判断

[P5711 【深基3.例3】闰年判断](https://www.luogu.com.cn/problem/P5711)，只需要注意什么情况是闰年就可以了。不过，要判断的情况有点多，写起来有点混乱啊……

一种思路，就是把所有**互斥**（互斥：以下情况最多只会发生一个，不会同时发生两个或更多）的情况独立地写出来：

1. 若年份不是 4 的倍数，则不是闰年；
2. 若年份是 4 的倍数，同时不是 100 的倍数，则是闰年；
3. 若年份是 100 的倍数，同时不是 400 的倍数，则不是闰年；
4. 若年份是 400 的倍数，则是闰年。

然后一一单独判断这些情况即可。

```cpp
#include<stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year % 4 != 0)
        printf("0");
    else if (year % 4 == 0 && year % 100 != 0)
        printf("1");
    else if (year % 100 == 0 && year % 400 != 0)
        printf("0");
    else if (year % 400 == 0)
        printf("1");
    return 0;
}
```

顺便一提，上面的这种 `if ... else if ... else if ... else if ...`，我们在分析代码含义的时候可以认为他是链式结构（即，如果你想在后面再加其他情况的判断，在后面追加 `else if ...` 即可，像是在一条链子后面加上了一个相同的环形成了更长的链子，而不需要嵌套）。

但是，由于 C 语言 if 后只会执行一个语句（或语句块），编译器会以嵌套的形式理解这段代码：

```cpp
    if (year % 4 != 0)
        printf("0");
    else
    {
        if (year % 4 == 0 && year % 100 != 0)
            printf("1");
        else
        {
            if (year % 100 == 0 && year % 400 != 0)
                printf("0");
            else
            {
                if (year % 400 == 0)
                    printf("1");
            }
        }
    }
```

编译器会认为，每个 `else` 语句后面又跟了一个完整的 `if else`。很明显，这种嵌套的方式非常不美观。因此，编写自己的代码或是理解别人的代码时，我们按照链式理解就可以了。

---------------------

另一种思路就是把所有年份从大类分到小类，然后依次判断：

1. 先把所有年份分为“能被 4 整除”和“不能被 4 整除”，后面一种情况可以判断为非闰年
2. 把“能被 4 整除”的再分为“能被 100 整除”和“不能被 100 整除”，后面一种情况可以判断为闰年
3. 再把“能被 100 整除”的再分为“能被 400 整除”和“不能被 400 整除”，两种情况均可判断

这里就会写出嵌套的 `if else`：

```cpp
#include<stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year % 4 != 0)
        printf("0");
    else
    { //能被 4 整除
        if (year % 100 != 0)
            printf("1");
        else
        { // 能被 100 整除
            if (year % 400 != 0)
                printf("0");
            else // 能被 400 整除
            {
                printf("1");
            }
        }
    }
    return 0;
}
```

我们尝试将其改写为为链式的 `if else`：

```cpp
#include<stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year % 4 != 0)
        printf("0");
    else if (year % 100 != 0)
        printf("1");
    else if (year % 400 != 0)
        printf("0");
    else // 能被 400 整除
        printf("1");
    return 0;
}
```

简洁多了，甚至比第一段代码还简洁。不过个人认为，第一种把所有互斥情况列出来的方法，不容易出错；第二种从大类分到小类的方法，需要仔细琢磨。

学会了闰年判断，能否判断一个年月有多少天呢？这个坑放到数组专题来填（这是第几次挖坑了）。

## 本周题单：循环结构

这周的题单是[循环结构](https://www.luogu.com.cn/training/102)。这周的题单 13 题中，必做的为[P5719 【深基4.例3】分类平均](https://www.luogu.com.cn/problem/P5719)和[P5723 【深基4.例13】质数口袋](https://www.luogu.com.cn/problem/P5723)。

除此之外，还有就是前面挖的坑：打印 ASCII 表。这里你只需要保证可见字符（字母数字、标点符号等）输出正常，某些不可见的字符的格式不做要求。

本周的“质数口袋”题目解法繁多，所以可能会有线下沙龙讲解。但是线上博客依旧是下周五晚八点之前更新，不见不散~
