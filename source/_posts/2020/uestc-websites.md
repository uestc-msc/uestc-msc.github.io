---
title: 电子科技大学常用网站
date: 2020-09-04 20:52:59
author: 小灰晖
tags: 小灰晖
---

> 本文更新于 2020.11.21，文中信息可能已失效。
> 更多信息可见：https://blog.lyh543.cn/others/something-about-uestc/

## 常用网址

最常用的网站推荐直接记域名，直接敲域名比在官网反复跳转快多了。

* 教务系统：http://eams.uestc.edu.cn/eams
* 一卡通，可进行挂失：http://ecard.uestc.edu.cn
* 学生邮箱（[注意事项](#学生邮箱)）：http://mail.std.uestc.edu.cn
* 教务处：http://www.jwc.uestc.edu.cn
  * 教务系统联系方式一览表：http://www.jwc.uestc.edu.cn/web/News!view.action?id=64
  * 校历、全校课表、培养方案（电子版）、各类（查分、转专业）申请表、均可在教务处网站搜索到
* 清水河畔（校内论坛）：https://bbs.uestc.edu.cn/
  * 校车 396路 通勤车时刻表：https://bbs.uestc.edu.cn/forum.php?mod=viewthread&tid=1430861
* 返校代理（[注意事项](#返校代理)）：https://vpn.uestc.edu.cn/
* 图书馆预约研修室：http://reservelib.uestc.edu.cn/
* 在线教材（官方只提供了少部分教材，且几乎没有课程提供 PDF）：http://zxkc.uestc.edu.cn/

<!-- More -->

学校官网是 `www.uestc.edu.cn`，必须加 `www`！`uestc.edu.cn` 域名是没有 A 记录的。教务处网站也是如此。

## 学校地址

中/英文官网拉到最下面即是。

||中文|英文及邮编
-|-|-
清水河|成都市高新区（西区）西源大道2006号|No.2006, Xiyuan Ave, West Hi-Tech Zone, 611731
沙河|成都市建设北路二段四号|No.4, Section 2, North Jianshe Road, 610054
九里堤|成都市九里堤西路8号|610031

## 学生邮箱

1. 学生邮箱无需“激活账号”，可直接登录，默认密码是身份证号倒数第七位至倒数第二位。
2. 目前尚不清楚学生邮箱在大一进校以后多久可用，保守估计这个时间在一个月以内。
3. 学生邮箱可用于申请：
   * [一个包含 1T Onedrive 空间的账号](https://www.microsoft.com/zh-cn/education/products/office)
   * [JetBrains 全家桶](https://www.jetbrains.com/student/)
4. 由于泥电学生邮箱是外包的且没有购买 SSL 证书，在邮箱客户端使用 IMAP、POP3 等不能使用 SSL 证书进行验证。强制要求 SSL 的客户端（如 Outlook for Android）似乎无法登陆学生邮箱（可以使用 Gmail 代替）。
5. 由上条原因，以及推送可能不及时等问题，建议仅将学校邮箱用于申请上述学生优惠，不要作为主力邮箱。

## 返校代理

登录 https://vpn.uestc.edu.cn/ 后即可通过在浏览器中修改网址达到用学校 IP 访问任意网址的效果。

http://www-uestc-edu-cn-s.vpn.uestc.edu.cn:8118/ 将会代理到 https://www.uestc.edu.cn/  
可见，将原网址中的 `.` 改写为 `-` 即可成功代理。

以下为更多规则：

规则|例子|实际访问网站
-|-|-
原网址中的 `.` 需改写为 `-`|
原网址中的 `-` 需改写为 `--`|
访问指定端口，需在后面加上 `-<端口号>-p`|http://www-uestc-edu-cn-80-p.vpn.uestc.edu.cn:8118/|http://www.uestc.edu.cn:80/
以 `https` 协议访问，需在最后加上 `-s`|http://www-uestc-edu-cn-s.vpn.uestc.edu.cn:8118/|https://www.uestc.edu.cn/
以 `https` 协议访问指定端口，使用 `-<端口号>-p-s`|http://www-uestc-edu-cn-443-p-s.vpn.uestc.edu.cn:8118/|https://www.uestc.edu.cn:443/

## eduroam 的账号密码

> 来源：https://info.uestc.edu.cn/info/1044/1631.htm

eduroam 联盟用户连接 SSID：`eduroam`，802.1x 认证，为全球 eduroam 联盟成员提供上网服务，eduroam 联盟内全球漫游。

我校师生的用户名为：`工资号或学号@uestc.edu.cn`，如：工资号 123456 对应的账号为 `123456@uestc.edu.cn`，密码为统一身份认证密码。
