---
title: 【Bot Framework完全攻略】1-4.战争前的准备
date: 2017-04-23 03:00:00
author: 谷亚奇
categories:
  - Bot Framework
tags:
  - 谷亚奇
---

我们来聊聊写程序的部分。。。

<!-- More -->

官网为Bot Framework的开发者提供了两种SDK。不懂什么是SDK的，百度百科传送门：http://baike.baidu.com/link?url=bH9-2ES2i6OPUXNpunCTeGSyQcgatkabbUHuxMIGMZlQSRtIkOmLTXT3p5U_Dz5buT_52YyNtcLiYR71dKbtBa

Bot Framework的开发可以用.NET SDK或者Node.js SDK来进行。

Node.js是用javascript写服务端的东西，我并不是很了解。我们的教程打算使用.NET SDK来进行（都是微软自己家的东西）

我们选用的开发语言是C#。虽然说.NET SDK是支持C++的，而且大多数人都会使用C++，但是使用C++开发的难度绝对不比从0开始学C#在开发要简单。简单来说，C++/CLR 要求你对C++有更到位的理解，并且会使用一些不属于C++的诡异语法。同时你要对C++环境下的托管编程有理解。

如果你要使用一些其他的开发方式，请参考

官方文档：https://docs.botframework.com/en-us/

谷歌翻译：[https://translate.google.cn](https://translate.google.cn/)

如果你选择了Node.js或者C++/CLR 慢走不送。。。

既然你到了这里，那么我开门见山的列出你需要的东西：

- Microsoft账号（这东西我想大多数人都有，不过还是要说一下）
- Visual Studio 2015 （大于均可，小于不知道）https://www.visualstudio.com/zh-hans/downloads/
- Bot模板 （VS&C#专用）http://aka.ms/bf-bc-vstemplate
- 一个服务器，可以是Azure云，也可以是其他的你自己的服务器（需要支持ASP.NET），如果没有我后面也会给你提供其他解决方案。
- Bot Emulator（这个是官方提供的本地测试工具）https://emulator.botframework.com/

有了这些东西就差不多了吧。。。
