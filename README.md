# uestc-msc.github.io

## TODO

- 谷歌认证
- hexo-admin-ehc
- 评论系统
- 修改网页的配色，使其更加“微软”

---
1. [TODO](#todo)
2. [写作语法](#写作语法)
   1. [next中比较炫酷的用法](#next中比较炫酷的用法)
   2. [文章分类](#文章分类)
      1. [多级分类](#多级分类)
      2. [多分类](#多分类)
3. [troubleshoot](#troubleshoot)
   1. [首页图片地址错误](#首页图片地址错误)
4. [配置记录](#配置记录)
   1. [hexo插件](#hexo插件)
   2. [更多](#更多)
      1. [文章管理](#文章管理)
         1. [更改静态文件中asset文件夹地址](#更改静态文件中asset文件夹地址)
         2. [将文章md文件按年, 月分类](#将文章md文件按年-月分类)
         3. [集成Travis服务](#集成travis服务)
      2. [站点内容](#站点内容)
         1. [自定义博客背景图片](#自定义博客背景图片)
         2. [生成about和categories页面](#生成about和categories页面)
         3. [简约而不硬核的友链页面](#简约而不硬核的友链页面)
         4. [彩色字体图标](#彩色字体图标)
         5. [实现每篇文章显示作者](#实现每篇文章显示作者)
         6. [更改文章底部tag的](#更改文章底部tag的)
         7. [指定图片大小](#指定图片大小)
---

💡 因为hexo是安装在当前文件夹, 因此不会在路径里, 无法通过 `hexo` 命令直接调用,
hexo位于 `node_modules/hexo/bin/hexo` (相对于根目录)

## 写作语法

### next中比较炫酷的用法

🔗 [note](https://theme-next.org/docs/tag-plugins/note)

🔗 [tab](https://theme-next.org/docs/tag-plugins/tabs)

🔗 [首页摘要图片](https://segmentfault.com/q/1010000004840061/a-1020000004895286)

### 文章分类

hexo支持多分类和多级分类, 但要注意别用错了

#### 多级分类

如下写法会将文章放至**a/b**分类

```
categories:
  - a
  - b
```

```
categories: [a, b]
```

#### 多分类

如下写法将文章放到**a**和**b**分类

```
categories:
  - [a]
  - [b]
```

而像下面这样的写法会将文章放到**a**和**b/c**分类

```
categories:
- [a]
- [b, c]
```

## troubleshoot

### 首页图片地址错误

由于[hexo的懒惰](https://hexo.io/zh-cn/docs/asset-folders.html), 用md语法插入的
图片在首页无法显示, 用它提供的标签插件倒是可以兼顾, 但不够优雅. 目前没去解决, 不
过可以尝试关注 `asset_img` 附近代码来自己实现.

## 配置记录

📖 [hexo官方文档](https://hexo.io/zh-cn/docs/)

📖 [NexT官方文档](https://theme-next.org/docs/getting-started/)

### hexo插件

* 一键git部署插件 [hexo-deployer-git](https://github.com/hexojs/hexo-deployer-git)
* emoji渲染插件 [hexo-filter-github-emojis](https://www.npmjs.com/package/hexo-filter-github-emojis)
* 文章阅读时间估计, 字数统计插件 [hexo-symbols-count-time](https://github.com/theme-next/hexo-symbols-count-time)
* 站内搜索功能数据库 [hexo-generator-searchdb](https://github.com/theme-next/hexo-generator-searchdb)
* 站内搜索功能 [hexo-generator-search](https://github.com/wzpan/hexo-generator-search)
* RSS订阅功能插件 [hexo-generator-feed](https://github.com/hexojs/hexo-generator-feed)
* sitemap生成插件 [hexo-generator-sitemap](https://github.com/hexojs/hexo-generator-sitemap)
* CJK回车产生空格问题修复插件 [hexo-filter-fix-cjk-spacing](https://github.com/lotabout/hexo-filter-fix-cjk-spacing)

### 更多

#### 文章管理

##### 更改静态文件中asset文件夹地址

这样插入图片不再一定要用hexo提供的语法, 就用markdown语法就可以

🔗 [更改方
式](https://leojhonsong.github.io/About-My-Custom-Settings-of-My-Next-Theme-Blog-and-Problem-Killing/#Improved-the-arrangement-of-images-in-asset-folder)

💡 和链接里不一样的是因为这里的文章链接是`:year/:month/:title.md`所以语句稍有不同, 是:

```javascript
    return join(post.path.replace(/\.html?$/, ''), (post.path.replace(/\.html?$/, '')).substr((post.path.replace(/\.html?$/, '')).lastIndexOf(RegExp("\\d\\d\\d\\d/\\d\\d/\\d\\d")) + 11), this.slug);
```

##### 将文章md文件按年, 月分类

这样能便于管理文章, 更改 `new_post_name` 的值就可以了

🔗 [参考](https://www.githang.com/2018/12/22/hexo-new-post-path/)

##### 集成Travis服务

上传写作文件自动生成并部署. 后续考虑采用merge要更新文章的文件到Root分支, 由
travis自动部署的方式进一步减少需要下载到本地的文件数量

🔗 [参考一](https://blessing.studio/deploy-hexo-blog-automatically-with-travis-ci/)
🔗 [参考二](https://www.jianshu.com/p/630d75e4697e)

❗️ 在 travis-ci.com 管理, 而不是 travis-ci.org

#### 站点内容

##### 自定义博客背景图片

因为没找到合适的图片暂时没改. 老网站的背景图是 `themes/uestc-msc/source/images/microsoft-building-logo2-1920.jpg`

🔗 [参考操作](https://github.com/theme-next/hexo-theme-next/issues/973)

##### 生成about和categories页面

🔗 [参考](https://theme-next.org/docs/theme-settings/custom-pages)

##### 简约而不硬核的友链页面

next主题的样式会覆盖文章markdown文件中的样式, 需要在
`source/_data/styles.styl` 中设置需要的样
式 (因为友链的元素是在post-body里)

🔗 [参考方案](https://blog.asucreyau.xyz/2018/12/29/hexo-next-customize-link-page)

##### 彩色字体图标

font awesome似乎只提供单色字体图标, 也不够丰富, 而
[Iconfont](https://www.iconfont.cn/?spm=a313x.7781069.1998910419.d4d0a486a)就很
牛皮了, 有丰富的图标, 有多色图标, 也能很容易的集成到网页.

此处采用[symbol引用](https://www.iconfont.cn/help/detail?spm=a313x.7781069.1998910419.d8cf4382a&helptype=code)

❗️ 在这几个改动了的.swig文件头尾加了如果有对应自定义.swig文件就不渲染的条件语句, 
不然会有重复渲染的bug, 已提PR

1. 首先图省事直接把项目生成的symbol代码添加到整个站点的head, 即

`themes/uestc-msc/layout/_partials/head/head.swig` (目前在line54) (改后放到 `source/_data/head.swig` ):

``` swig
   {%- if theme.iconfont.source %}
   <script src = "https:{{ theme.iconfont.source }}"></script>
   {%- endif%}
   ```

2. 更改**sidebar**中的社交链接使用iconfont

`themes/uestc-msc/layout/_partials/sidebar/site-overview.swig` line 101 (改好后放到 `source/_data/sidebar.swig` ):

   ❗️只注释掉原本的font awesome语句, 万一以后还用呢 🤷 ‍

``` swig
        {#%- set sidebarIcon = '<i class="fa fa-fw fa-' + link.split('||')[1] | trim | default('globe') + '"></i>' %#}
        {% set sidebarIcon = '<svg class="icon" aria-hidden="true"><use xlink:href="#' + link.split('||')[1] | trim + '"></use></svg>' %}
   ```

3. 更改footer中的用户图标使用iconfont

`themes/uestc-msc/layout/_partials/footer.swig` line13 (改好后放到 `source/_data/footer.swig` ):

``` swig
       <!-- <i class="fa fa-{{ theme.footer.icon.name }}"></i> -->
       <svg class="icon" aria-hidden="true"><use xlink:href="#{{ theme.footer.icon.name }}"></use></svg>
   ```

4. 将彩色字体图标的样式添加到 `source/_data/styles.styl` :

``` styl
   //------------------------------------------------------------------------------
   //colorful icons
   //------------------------------------------------------------------------------
   svg.icon {
       width: 1.5em !important;
       height: 1.5em !important;
       vertical-align: -0.4em;
       fill: currentColor;
       overflow: hidden
   }
   ```

   🔗 [参考操作](https://leojhonsong.github.io/About-My-Custom-Settings-of-My-Next-Theme-Blog-and-Problem-Killing/#Colorful-icons-for-social-links-in-sidebar)

##### 实现每篇文章显示作者

🔗 [参考操作](https://bolt.coding.me/blog/2017/03/13/%E5%9F%BA%E4%BA%8E-Hexo-%E5%AE%9E%E7%8E%B0%E5%A4%9A%E4%BD%9C%E8%80%85%E5%8D%9A%E5%AE%A2/)

❗️因为实现得比较简陋, 作者链接处是直接到作者名tag的链接, 如果有两个作者会出现链
接错误问题, 因此目前每篇文章只能有一个作者. 当然这很好改.

目前直接将`themes/uestc-msc/languages/zh-CN.yml`中tag页面的翻译全部替换为作者页
面的翻译来将tag页面伪装为作者页面.

##### 更改文章底部tag的#

修改 `themes/uestc-msc/layout/_macro/post.swig` line271为:

``` swig
            {%- set tag_indicate = '<i class="fa fa-tag"></i>' %}
```

##### 指定图片大小

虽然实际指定的是**width**但因为长宽比是固定的所以可以实现指定图片大小的功能

在`themes/uestc-msc/layout/_layout.swig`的body结束tag前加了一句加载设定图片宽度
脚本的语句.

```javascript
  <script src="/js/hexo_resize_image.js"></script>
```

将指定图片大小的脚本放到了`themes/uestc-msc/source/js/hexo_resize_image.js`, 这
个文件夹的会被放到站点资源.

💡 使用很简单, 只是拓展了一下Markdown的语法. 👇例子:

```markdown
![img](example.png?10)
```
在图片链接后加问号, 问号后是图片宽度和屏幕宽度的比例.
