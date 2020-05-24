---
title: "Set Up Vpn"
date: 2020-05-24T17:12:07+08:00
draft: false
---

搭梯子比较频繁，记录下步骤方便重现

## 服务器

- 别选择没法换ip的就好，比如现在的搬瓦工。系统推荐 debian 10。

- 到手后`apt update` `apt upgrade` `reboot`

## 搭建代理

搭建shadowsocks，在服务端步骤如下

1. 安装shadowsocks-libev

```
# apt install shadowsocks-libev
```

2. 配置

```
# nano /etc/default/shadowsocks-libev
```
将`USER=nobody`和`GROUP=nogroup`替换成`USER=root`和`GROUP=root`

```
# nano /etc/shadowsocks-libev/config.json
```
替换"server"后的"127.0.0.1"为"0.0.0.0"，替换"password"为自己的密码，"server_port"后替换为443或其它常用端口

在客户端中，ip填写服务器的公网ip，密码、端口、加密方式同服务器配置，客户端和服务器的local_port没有关系随便填或保持默认。

3. 运行

```
# systemctl restart shadowsocks-libev
```


