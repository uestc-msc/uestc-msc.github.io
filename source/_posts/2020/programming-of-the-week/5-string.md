---
title: MSC 每周两题：上周题解 & 字符串
date: 2020-12-25 11:33:02
categories:
- [C++]
- [MSC 每周两题]
author: 小灰晖
tags: 小灰晖
---

数组部分的题解！

<!-- More -->

## 系列目录

1. [MSC 每周两题：前言 & 顺序结构](/2020/11/13/2020-programming-of-the-week-1-preface-and-sequential/)
2. [MSC 每周两题：上周题解 & 分支结构](/2020/11/20/2020-programming-of-the-week-2-branch/)
3. [MSC 每周两题：上周题解 & 循环结构](/2020/11/27/2020-programming-of-the-week-3-loop/)
4. [MSC 每周两题：上周题解 & 数组](/2020/12/15/2020-programming-of-the-week-4-array/)
5. [MSC 每周两题：上周题解 & 字符串](/2020/12/25/2020-programming-of-the-week-5-string/)
6. [MSC 每周两题：去年题解 & 函数和结构体](/2021/03/04/2020-programming-of-the-week-6-function-and-structure/)
7. MSC 每周两题：上周题解 & 后记

## P5728 【深基5.例5】旗鼓相当的对手

[P5728 【深基5.例5】旗鼓相当的对手](https://www.luogu.com.cn/problem/P5728) ~~一看就是老炉石玩家了~~

这题比较基础，可以练习一下数组的语法。就不多讲了。

具体的代码上，可以使用二维数组存所有的成绩，也可以使用三个一维数组分别存语文、数学和英语成绩（也可以再用第四个一位数组存总成绩）。

C++ 采用四个一维数组进行实现：

```cpp
#include<stdio.h>
#include<math.h>

int main()
{
    int chinese[1000], math[1000], english[1000], total[1000];
    int n, ans = 0;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &chinese[i], &math[i], &english[i]);
        total[i] = chinese[i] + math[i] + english[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(chinese[i] - chinese[j]) <= 5 
                && abs(math[i] - math[j]) <= 5 
                && abs(english[i] - english[j]) <= 5 
                && abs(total[i] - total[j]) <= 10)
                ans++;
        }
    }

    printf("%d", ans);
}
```

Python 使用二维数组进行实现：

```py
n = int(input())
scores = []

for i in range(n):
    score = list(map(int, input().split()))
    scores.append(score)

ans = 0
for i in range(n):
    for j in range(i+1, n):
        if abs(scores[i][0] - scores[j][0]) <= 5 \
        and abs(scores[i][1] - scores[j][1]) <= 5 \
        and abs(scores[i][2] - scores[j][2]) <= 5 \
        and abs(sum(scores[i]) - sum(scores[j])) <= 10:
            ans += 1

print(ans)
```

这次还新加入了 Go 语言，使用三个一维数组实现：

```go
package main

import (
	"fmt"
)

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}

func main()  {
	n, ans := 0, 0
	fmt.Scanln(&n)

	chinese, math, english := make([]int, n), make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&chinese[i], &math[i], &english[i])
	}

	for i := 0; i < n; i++ {
		for j := i+1; j < n; j++ {
			if abs(chinese[i] - chinese[j]) <= 5 &&
				abs(math[i] - math[j]) <= 5 &&
				abs(english[i] - english[j]) <= 5 &&
				abs(chinese[i] + math[i] + english[i] - chinese[j] - math[j] - english[j]) <= 10 {
				ans++
			}
		}
	}

	fmt.Println(ans)
}
```

## P1789 【Mc生存】插火把

[P1789 【Mc生存】插火把](https://www.luogu.com.cn/problem/P1789) ~~一看就是老 MC 玩家了~~

也是非常基础的一个题，按照题目说的，使用一个二维数组模拟地图。先假设每个格子都可能出现怪物 (`true`)，然后对每个火把和萤石，将其照亮的区域标记为 `false`，最后数一遍地图上还有多少个 `true` 即可。

处理萤石比较简单，因为萤石照亮的范围是：

$$\left\{\begin{matrix}
x-2 \leq x_0 \leq x+2 \\
y-2 \leq y_0 \leq y+2
\end{matrix}\right.$$

但是火把的范围比较麻烦，它是一个菱形。我们可以这样定义：设 $dx = x-x_0, dy = y-y_0$，则有

$$|dx|+|dy| \leq 2$$

最后还需要注意，可能出现火把（萤石）照到地图以外的地方，所以记得判定是否越界。

C 语言：

```cpp
#include<stdio.h>

int main()
{
    bool monster[100][100];
    int n, fire, stone;
    scanf("%d%d%d", &n, &fire, &stone);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            monster[i][j] = true;

    for (int i = 0; i < fire; i++) // 统计火把
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        x0--, y0--; // 我们定义的地图数组下标从 0 开始，题目从 1 开始，所以要把题目的输入减 1
        for (int dx = 0; dx <= 2; dx++)
        {
            for (int dy = 0; dy <= 2 - dx; dy++)
            {
                if (x0 - dx >= 0 && x0 - dx < n && y0 - dy >= 0 && y0 - dy < n) // 判定越界
                    monster[x0 - dx][y0 - dy] = false;
                if (x0 + dx >= 0 && x0 + dx < n && y0 - dy >= 0 && y0 - dy < n) // 判定越界
                    monster[x0 + dx][y0 - dy] = false;
                if (x0 - dx >= 0 && x0 - dx < n && y0 + dy >= 0 && y0 + dy < n) // 判定越界
                    monster[x0 - dx][y0 + dy] = false;
                if (x0 + dx >= 0 && x0 + dx < n && y0 + dy >= 0 && y0 + dy < n) // 判定越界
                    monster[x0 + dx][y0 + dy] = false;
            }
        }
    }

    for (int i = 0; i < stone; i++) // 统计萤石
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        x0--, y0--;
        for (int x = x0 - 2; x <= x0 + 2; x++)
        {
            if (x < 0 || x >= n) // 判定越界
                continue;
            for (int y = y0 - 2; y <= y0 + 2; y++)
            {
                if (y < 0 || y >= n)
                    continue;
                monster[x][y] = false;
            }
        }
    }

    int ans = 0; // 统计怪物总数
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            if (monster[x][y])
                ans++;

    printf("%d", ans);
}
```

注意到 21 行至 28 行都是结构重复的代码，只是处理的变量有点不同。因此我们可以把重复的一个小过程独立为**函数**（但这是下周的内容，所以不做要求）。同时我们还需要将 `monster[][]` 和 `n` 的定义放到 main 函数以外（相关知识：函数作用域）。

题外话，如果不想把 `monster` 和 `n` 的定义放到 `main` 外呢？可以把这两个作为函数的参数（但是二维数组一般不推荐作为函数参数），或者使用 `lambda` 表达式在 `main` 函数内定义我们上面提到的函数。这里涉及的知识又有不少了，甚至 `lambda` 表达式超出了 C 语言的范围，因此我们略过，有兴趣的同学可以自己了解。

运用函数的 C 语言版本：

```cpp
#include<stdio.h>
#include<math.h>

bool monster[100][100];
int n, fire, stone;

int lighten(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n) // 判定越界
        monster[x][y] = false;
}

int main()
{
    scanf("%d%d%d", &n, &fire, &stone);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            monster[i][j] = true;

    for (int i = 0; i < fire; i++) // 统计火把
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        x0--, y0--; // 我们定义的地图数组下标从 0 开始，题目从 1 开始，所以要把题目的输入减 1
        for (int dx = 0; dx <= 2; dx++)
        {
            for (int dy = 0; dy <= 2 - dx; dy++)
            {
                lighten(x0 + dx, y0 - dy);
                lighten(x0 - dx, y0 + dy);
                lighten(x0 + dx, y0 + dy);
                lighten(x0 - dx, y0 - dy);
            }
        }
    }

    for (int i = 0; i < stone; i++) // 统计萤石
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        x0--, y0--;
        for (int x = x0 - 2; x <= x0 + 2; x++)
        {
            for (int y = y0 - 2; y <= y0 + 2; y++)
            {
                lighten(x, y);
            }
        }
    }

    int ans = 0; // 统计怪物总数
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            if (monster[x][y])
                ans++;

    printf("%d", ans);
}
```

Python 版本直接给出利用函数的版本：

```py
def lighten(x: int, y: int):
    if 0 <= x < n and 0 <= y < n:
        monster[x][y] = False


n, fire, stone = map(int, input().split())
monster = [[True] * n for i in range(n)] # 运用列表生成式初始化二维数组

for i in range(fire): # 处理萤火
    x0, y0 = map(int, input().split())
    x0 -= 1
    y0 -= 1
    for dx in range(0, 3):
        for dy in range(0, 3 - dx):
            lighten(x0-dx, y0-dy)
            lighten(x0+dx, y0-dy)
            lighten(x0-dx, y0+dy)
            lighten(x0+dx, y0+dy)

for i in range(stone): # 处理萤火
    x0, y0 = map(int, input().split())
    x0 -= 1
    y0 -= 1
    for dx in range(-2, 3):
        for dy in range(-2, 3):
            lighten(x0+dx, y0+dy)

s = sum(map(sum, monster)) # 二维数组求和
print(s)
```

Go 版本：

```go
package main

import (
	"fmt"
)

var n int
var monster [100][100]bool

func lighten(x int, y int) {
	if x >= 0 && x < n && y >= 0 && y < n {
		monster[x][y] = false
	}
}

func main()  {
	fire, stone, ans := 0, 0,0
	fmt.Scanln(&n, &fire, &stone)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			monster[i][j] = true
		}
	}

	for i := 0; i < fire; i++ { // 处理火把
		var x, y int
		fmt.Scanln(&x, &y)
		x--
		y--
		for dx := 0; dx <= 2; dx++ {
			for dy := 0; dy <= 2 - dx; dy++ {
				lighten(x-dx, y-dy)
				lighten(x+dx, y-dy)
				lighten(x-dx, y+dy)
				lighten(x+dx, y+dy)
			}
		}
	}

	for i := 0; i < stone; i++ { // 处理萤石
		var x, y int
		fmt.Scanln(&x, &y)
		x--
		y--
		for dx := -2; dx <= 2; dx++ {
			for dy := -2; dy <= 2; dy++ {
				lighten(x+dx, y+dy)
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if monster[i][j] {
				ans++
			}
		}
	}
	fmt.Println(ans)
}
```

## P2615 神奇的幻方

[P2615 神奇的幻方](https://www.luogu.com.cn/problem/P2615)

题目讲的是构造幻方的一个套路。按照题意写就行啦。这里只给出 C++ 的版本：

```cpp
#include<stdio.h>

int main()
{
	int square[40][40];
	int n, i, j;		// i 表示行，j 表示列，下标从 1 开始

	scanf("%d", &n);
	i = 1, j = n / 2 + 1;


	for (int sum = 1; sum <= n * n; sum++)
	{
		square[i][j] = sum;
		if (sum % n == 0)
		{
			i++;
			if (i == n + 1)
				i = 1;
		}
		else
		{
			i--;
			j++;
		}

		if (i == 0)
			i = n;
		if (j == n + 1)
			j = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", square[i][j]);
		printf("\n");
	}
	return 0;
}
```

## P5716 【深基3.例9】月份天数

[P5716 【深基3.例9】月份天数](https://www.luogu.com.cn/problem/P5716)

使用[闰年判断](/2020/11/27/2020-programming-of-the-week-3-loop/#P5711-【深基3-例3】闰年判断)的代码，我们可以判断某年 2 月的天数。剩下的月份我们只需要打一份表，将十一个月的天数保存在一个数组中，根据不同输入，输出对应的数字即可。

C 语言版本：

```cpp
#include<stdio.h>

int main()
{
    const int mdays[] = { -1, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 十二个月每月的天数
    int year, month;
    scanf("%d%d", &year, &month);
    if (month != 2)
        printf("%d", mdays[month]);
    else if (year % 4 != 0)
        printf("28");
    else if (year % 100 != 0)
        printf("29");
    else if (year % 400 != 0)
        printf("28");
    else
        printf("29");
    return 0;
}
```

Python 版本：

```py
mdays = [-1, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
year, month = map(int, input().split())
if month != 2:
    print(mdays[month])
elif year % 4 != 0:
    print(28)
elif year % 100 != 0:
    print(29)
elif year % 400 != 0:
    print(28)
else:
    print(29)
```

Go 版本：

```go
package main

import "fmt"

func main() {
	var year, month int
	mdays := []int{-1, 31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	fmt.Scanln(&year, &month)
	if month != 2 {
		fmt.Println(mdays[month])
	} else if year%4 != 0 {
		fmt.Println(28)
	} else if year%100 != 0 {
		fmt.Println(29)
	} else if year%400 != 0 {
		fmt.Println(28)
	} else {
		fmt.Println(29)
	}
}
```

## 本周题单：字符串

这周的题单是[字符串](https://www.luogu.com.cn/training/104)。这周的题单 15 题中，必做的为 [P1914 小书童——凯撒密码](https://www.luogu.com.cn/problem/P1914) 和 [P1597 语句解析](https://www.luogu.com.cn/problem/P1597)。
