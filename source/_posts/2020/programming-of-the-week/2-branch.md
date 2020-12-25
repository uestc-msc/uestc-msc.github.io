---
title: MSC 每周两题：上周题解 & 分支结构
date: 2020-11-20 12:00:00
categories:
- [C++]
- [MSC 每周两题]
author: 小灰晖
tags: 小灰晖
---

首先是上次顺序结构的题解！

单纯只出顺序结构相关的题，是不会像分支、循环、函数、结构体等后面的专题一样把 C 玩出花来。所以也就出一些基础一点的题加一点数学题（如果你想体验亿点数学题的话，可以看看[P2433 【深基1-2】小学数学 N 合一](https://www.luogu.com.cn/problem/P2433)）。

<!-- More -->

## 系列目录

1. [MSC 每周两题：前言 & 顺序结构](/2020/11/13/2020-programming-of-the-week-1-preface-and-sequential/)
2. [MSC 每周两题：上周题解 & 分支结构](/2020/11/20/2020-programming-of-the-week-2-branch/)
3. [MSC 每周两题：上周题解 & 循环结构](/2020/11/27/2020-programming-of-the-week-3-loop/)
4. [MSC 每周两题：上周题解 & 数组](/2020/12/15/2020-programming-of-the-week-4-array/)
5. [MSC 每周两题：上周题解 & 字符串](/2020/12/25/2020-programming-of-the-week-5-string/)
6. MSC 每周两题：上周题解 & 函数和结构体
7. MSC 每周两题：上周题解 & 后记

## P5704 【深基2.例6】字母转换

先看 [P5704 【深基2.例6】字母转换](https://www.luogu.com.cn/problem/P5704)。

题目要求将小写字母转换为大写字母。

C 语言中，字符 `char` 是按照 [ASCII 码](https://baike.baidu.com/item/ASCII)存储的，其中 ASCII 表可以百度到，也可以使用你手上的 C 语言编译器自己做一张表（但是这需要循环结构的知识，这里就先挖一个坑；如果你已经学会了循环结构，你可以提前做一张表）。

从表中可以注意到，大小写字母的 ASCII 码是一一对应的，同一个字母的大小写相差 32。于是，我们对字符变量进行运算：`输出字符 = 输入字符 - 32` 即可完成此题。

如果恰巧忘了 32 这个常量值，我们也可以让计算机自行计算出 `'a' - 'A'` 的值。如下面的代码：

```c
#include<stdio.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    ch = ch - 'a' + 'A';
    printf("%c", ch);
}
```

也就是说，我们并不一定要死记 ASCII 码间的对应关系，而是让电脑自己去运算，这样代码的可读性也会更高。（如，将数字字符转为其数字值时，我更喜欢 `num = ch - '0';` 而不是 `num = ch - 48;`）

## P5708 【深基2.习2】三角形面积

另外一题是 [P5708 【深基2.习2】三角形面积](https://www.luogu.com.cn/problem/P5708)。~~这道题公式都你糊脸上了，直接抄上去就行了~~程序员的事，能叫抄公式吗？那叫代码复用，我们要讲码德。

```cpp
#include<stdio.h>
#include<math.h>

int main()
{
    // float a, b, c, p, area;
    double a, b, c, p, area;
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    area = sqrt(p * (p-a) * (p-b) * (p-c));
    printf("%.1f", area);
    return 0;
}
```

这道题如果使用 `float` 类型运算，最后一个测试点会 `Wrong Answer`，使用 `double` 才能全部通过。最后一个测试点的输入为 `888.88 888.88 888.88`，使用 `float` 的输出为 `342126.8`，而 `double` 的运算结果为 `342126.7`。

现实生活中，很多情况下一点误差是允许的，但对于 OJ 这类在线评测，要求结果和测试点的预期完全一样，因此在 OJ 提交时，我们一般都会使用更精确的 `double` 甚至 `long double` 类型进行运算，平时写代码的根据自己的需求（精确度、内存等）而定。

---------------

请提交成功的同学将自己的代码提交到 [GitHub 仓库](https://github.com/uestc-msc/2020-members)。

当然，如果你还不会使用 Git，你可以暂时不提交，之后我们会有关于 Git 的简单使用的[教程博客](https://blog.lyh543.cn/linux/introduction-to-wsl-ubuntu-and-git/)（暂时还没更新）和手把手教学沙龙，这周因为时间不合适，都咕咕咕了。待博客和沙龙都更新完了，各位可以再参考博客或沙龙，提交自己的代码。

## 本周题单：分支结构

这周的题单是[分支结构](https://www.luogu.com.cn/training/101)，16 道题必做的只有 [P5711 【深基3.例3】闰年判断](https://www.luogu.com.cn/problem/P5711) 和 [P5712 【深基3.例4】Apples](https://www.luogu.com.cn/problem/P5712)，都是在实际开发中经常遇到的情况（手写日期判断等情况，使用单数还是复数）。题解和下周题目会在下周五晚八点前公布~
