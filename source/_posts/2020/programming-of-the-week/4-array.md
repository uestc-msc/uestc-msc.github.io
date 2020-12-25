---
title: MSC 每周两题：上周题解 & 数组
date: 2020-12-15 21:00:00
categories:
- [C++]
- [MSC 每周两题]
author: 小灰晖
tags: 小灰晖
---

说周五发这篇博客，然后就咕了一个多星期 hhhh 俱乐部的鸽子本性。

不过，本期题解的线下沙龙的录屏已经投到了 B 站（就是麦克风效果有点不行）：

<!-- More -->

<iframe src="//player.bilibili.com/player.html?aid=245617490&bvid=BV1Cv411b7tA&cid=263251749&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

## 系列目录

1. [MSC 每周两题：前言 & 顺序结构](/2020/11/13/2020-programming-of-the-week-1-preface-and-sequential/)
2. [MSC 每周两题：上周题解 & 分支结构](/2020/11/20/2020-programming-of-the-week-2-branch/)
3. [MSC 每周两题：上周题解 & 循环结构](/2020/11/27/2020-programming-of-the-week-3-loop/)
4. [MSC 每周两题：上周题解 & 数组](/2020/12/15/2020-programming-of-the-week-4-array/)
5. [MSC 每周两题：上周题解 & 字符串](/2020/12/25/2020-programming-of-the-week-5-string/)
6. MSC 每周两题：上周题解 & 函数和结构体
7. MSC 每周两题：上周题解 & 后记

## P5719 【深基4.例3】分类平均

[P5719 【深基4.例3】分类平均](https://www.luogu.com.cn/problem/P5719)

### 方法一

最简单的做法就是把 $1$ 到 $n$ 的数全部遍历一遍，然后使用一个 `if` 对数分类，统计数的总和以及总数，最后求一个平均数即可。

```cpp
#include<stdio.h>

int main()
{
    int n, k;
    double a_sum = 0, b_sum = 0, a_n = 0, b_n = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            a_sum += i;
            a_n++;
        }
        else
        {
            b_sum += i;
            b_n++;
        }
    }
    printf("%.1f %.1f", a_sum / a_n, b_sum / b_n);
    return 0;
}
```

应同学要求，这次加上了 Python 3 的代码。

使用 Python，可以使用 `filter` 函数将数组直接分为能被 $k$ 整除，以及不能被 $k$ 整除的部分，而不用写 `for` 语句。

```python
n, k = map(int, input().split())
numbers = range(1,  n+1)
numbers_a = list(filter(lambda x: x % k == 0, numbers))
numbers_b = list(filter(lambda x: x % k != 0, numbers))
average_a = sum(numbers_a)/len(numbers_a)
average_b = sum(numbers_b)/len(numbers_b)
print("%.1f %.1f" % (average_a, average_b))
```

### 方法二

除了循环以外，能不能直接根据 n 和 k 直接计算得出结果呢？这道题有很强的数学性质，于是可以尝试往这方面想想。

设两个集合分别为 $S_A$ 和 $S_B$。显然有：

$$\sum_{x \in S_A} x + \sum_{y \in S_B} y = \frac{1}{2}n(n+1)$$

$$|S_A| + |S_B| = n$$

注意到 $S_A$ 是“前 $n$ 个数中能被 $k$ 整除的数组成的集合”，所以不难推出集合 $S_A$ 中共有 $\lfloor\frac{n}{k}\rfloor$ 个元素。（不会推导的同学也可以举 $n=5, k=2$ 这样的例子验证）

而 $S_A$ 中的元素又构成了首项、公差均为 $k$ 的等差数列，其个数也可以求出（如上）。

用总的个数与元素和分别减去 $S_A$ 的个数和元素和，就可以得到 $S_B$ 的个数以及元素和。最后分别求 $S_A$ 和 $S_B$ 的平均数即可。

下面是 C 和 Python 3 的实现。

```cpp
#include<stdio.h>

int main()
{
    int n, k;
    double a_sum = 0, b_sum = 0, a_n = 0, b_n = 0, sum = 0;
    scanf("%d%d", &n, &k);
    sum = (1 + n) * n / 2;
    a_n = n / k;
    a_sum = (k + k * a_n) * a_n / 2;
    b_n = n - a_n;
    b_sum = sum - a_sum;
    printf("%.1f %.1f", a_sum / a_n, b_sum / b_n);
    return 0;
}
```

```py
n, k = map(int, input().split())
sum = (1 + n) * n / 2
a_n = n // k
a_sum = (k + k * a_n) * a_n / 2
b_n = n - a_n
b_sum = sum - a_sum
print("%.1f %.1f" % (a_sum / a_n, b_sum / b_n))
```

## P5723 【深基4.例13】质数口袋

[P5723 【深基4.例13】质数口袋](https://www.luogu.com.cn/problem/P5723)

### 方法一

题目本质是在求从 2 开始的所有质数，直至满足其和大于 $L$。所以本题的三个方法均围绕如何求质数进行。

最朴素的方法就是根据质数的定义：

> 质数（Prime number），又称素数，指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数（也可定义为只有1与该数本身两个正因数的数）。

根据定义，对于大于1的自然数 $i$，如果验证 $2\sim i-1$ 均不能整除 $i$，那么 $i$ 一定是质数。

但是，一定要判定 $2\sim i-1$ 吗？

一种优化，是只判定 $2\sim \sqrt{i}$ 之间的整数。因为一个合数 $i$ 必然会有一个因数小于 $\sqrt{i}$（想想，这是为什么？）。

下面的 C 和 Python 代码就采用了这种优化。

```cpp
#include<stdio.h>
#include<math.h>

int main()
{
    int L;
    scanf_s("%d", &L);
    int sum = 0, n = 0;
    for (int i = 2; sum + i <= L; i++)
    {
        bool is_prime = true;
        int sqrt_i = sqrt(i); // 注意不要把 sqrt(i) 的计算过程写到 for 的判定条件中
        // 在不考虑编译器优化的情况下，这种写法会导致每次判定 j <= sqrt(i) 时都会重新计算 sqrt(i)
        for (int j = 2; j <= sqrt_i; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            sum += i;
            n++;
            printf("%d\n", i);
        }
    }
    printf("%d", n);
}
```

```py
from math import sqrt

L=int(input())
sum, n = 0, 0
for i in range(2, L):
    if sum+i > L:
        break
    is_prime = True
    for j in range(2, int(sqrt(i))+1):
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        sum += i
        n += 1
        print(i)
print(n)
```

对这种方法更进一步的优化，是只判定 $2\sim \sqrt{i}$ 之间的质数。因为一个合数 $i$ 必然会有一个**质因数**小于 $\sqrt{i}$。

不过，这样就要求将前面计算出的质数存到数组中，需要额外的数组空间。

### 方法二

方法二源于埃拉托斯特尼筛法。其算法思想是，假设所有数都是质数，第一步先从 4 开始把 2 的倍数筛掉（因为都是和数），下一步筛掉 3 的倍数，然后筛掉 5 的倍数……

由于算法很著名，网上有不少现成的、形象易懂的埃氏筛算法的讲解博客，因此这里不进行更多展开。感兴趣的同学可以自行搜索并进行学习。

下面是 C 和 Python 3 的实现。

```cpp
#include<stdio.h>
#include<math.h>

const int max_size = 1e6 + 5;

int main()
{
    // 为方便，这里使用 is_not_prime 并设初值为 0，代替算法中的 is_prime 初值为 1
    bool is_not_prime[max_size] = { 0 };
    int L;
    scanf_s("%d", &L);
    int sum = 0, n = 0;
    for (int i = 2; sum + i <= L; i++)
    {
        if (is_not_prime[i])
            continue;
        for (int j = i * i; i * j <= L; j += i)
            is_not_prime[j] = 1;
        sum += i;
        n++;
        printf("%d\n", i);
    }
    printf("%d", n);
}
```

```py
MAX_SIZE = 100005
is_not_prime = [False] * MAX_SIZE
L=int(input())
sum, n = 0, 0
for i in range(2, L):
    if sum+i > L:
        break
    if is_not_prime[i]:
        continue
    for j in range(i*i, L+1, i):
        is_not_prime[j] = True
    sum += i
    n += 1
    print(i)
print(n)
```

除此之外，埃氏筛法还有线性筛、奇数筛等优化，学有余力的同学可以自行搜索了解。

### 方法三

还有一种方法，这种方法是为了单纯为了把程序运行速度提高到极致才产生的方法：使用方法一或方法二的算法生成足够用的质数表，然后将质数表复制到代码里直接使用！

这种技巧被称为“打表”。

> 打表，是一个信息学专用术语，意指对一些题目，通过打表技巧获得一个有序表或常量表，来执行程序某一部分，优化时间复杂度。这种算法也可用于在对某种题目没有最优解法时，用来得到分数的一种策略。

以下是我们得到了质数表的前提下的 C 和 Python 3 代码。

```cpp
#include<stdio.h>
#include<math.h>

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 10000};
// 最后一个 10000 是防止遍历数组的时候越界

int main()
{
    int L;
    scanf_s("%d", &L);
    int sum = 0, n = 0;
    for (int i = 0; sum + prime[i] <= L; i++)
    {
        sum += prime[i];
        n++;
        printf("%d\n", prime[i]);
    }
    printf("%d", n);
}
```

```py
prime = [ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 10000]

L=int(input())
sum, n = 0, 0
for i in prime:
    if sum+i > L:
        break
    sum += i
    n += 1
    print(i)
print(n)
```

## 将代码上传到 GitHub

上上周我们开了沙龙讲解如何配置 WSL 和 Git。这里有博客记录：[WSL(Ubuntu)、Git 配置及简单使用](https://blog.lyh543.cn/linux/introduction-to-wsl-ubuntu-and-git/)。

我们希望同学能将自己在洛谷提交的代码也提交到 Git 仓库：[uestc-msc/2020-members](https://github.com/uestc-msc/2020-members)。提交时，请 fork 原仓库到自己账号下，在自己账号下的仓库完成提交，然后向俱乐部仓库 Pull Request。

尚不会使用 Git 的同学，可以参考上面的博客，也可以在 QQ 群里提问。

## 本周题单：数组

这周的题单是[数组](https://www.luogu.com.cn/training/103)。这周的题单 20 题中，必做的为 [P5728 【深基5.例5】旗鼓相当的对手](https://www.luogu.com.cn/problem/P5728) 和 [P1789 【Mc生存】插火把](https://www.luogu.com.cn/problem/P1789)，还有 [P2615 神奇的幻方](https://www.luogu.com.cn/problem/P2615)。

除了上面的题以外，我们还需要填一个坑，就是基于之前分支结构中的 [P5711 【深基3.例3】闰年判断](https://www.luogu.com.cn/problem/P5711) 的 [P5716 【深基3.例9】月份天数](https://www.luogu.com.cn/problem/P5716)。各位可以基于之前的代码加以完善，然后完成此题。

本次题目的题解将于下周五 (2020-12-25) 给出，敬请期待~