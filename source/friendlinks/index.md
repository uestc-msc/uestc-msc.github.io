---
title: friendlinks
date: 2019-08-25 03:09:57
---

<hr />
<style>
  .container {
    width: 100%;
  }

  .links {
    list-style: none;
  }

  .link {
    margin: 10px;
    display: inline-block;
  }

  .card {
    height: 72px;
    width: 300px;
    box-shadow: 0 3px 1px -2px rgba(0,0,0,.2), 0 2px 2px 0 rgba(0,0,0,.14), 0 1px 5px 0 rgba(0,0,0,.12);
    transition: box-shadow .25s cubic-bezier(.4,0,.2,1);
  }

  .card:hover {
    box-shadow: 0 5px 5px -3px rgba(0,0,0,.2),0 8px 10px 1px rgba(0,0,0,.14),0 3px 14px 2px rgba(0,0,0,.12);
  }

  .avatar {
    float: left;
    height: 72px;
    width: 72px;
  }

  img {
    height: 100%;
    width: 100%;
  }

  .titles {
    overflow: hidden;
    height: 72px;
    width: 227px;
    margin-left: 72px;
  }

  .title{
    text-align: center;
    height: 20px;
    width: 100%;
    margin: 0;
    line-height: 20px;
    margin-top: 14px;
  }

  .subtitle {
    text-align: center;
    height: 20px;
    width: 100%;
    margin: 0;
    line-height: 20px;
  }

  small {
    width: 100%;
  }
</style>

<div div="container">
  <ul class="links" id="links"></ul>
</div>

<script>
var xhr = new XMLHttpRequest();
var path = 'index/friendlinks.xml';

xhr.open('GET', path, true);

xhr.onload = function (e) {
  if (xhr.readyState === 4) {
    if (xhr.status === 200) {
      // console.log(xhr.responseText);
      var parser = new DOMParser();
      var xmlDoc = parser.parseFromString(xhr.responseText, 'text/xml');
      // document.write(xmlDoc.getElementsByTagName('link')[0].textContent);
      var ul = document.getElementById('links');

      for (let i = 0; i < xmlDoc.getElementsByTagName('link').length; i++) {
        var li = document.createElement('li');
        // li.setAttribute('class', 'link');
        li.className = 'link';
        var a = document.createElement('a');
        a.href = xmlDoc.getElementsByTagName('url')[i].innerHTML;
        a.target = '_blank';
        a.title = xmlDoc.getElementsByTagName('title')[i].innerHTML;
        var card = document.createElement('div');
        card.className = 'card';
        var avatar = document.createElement('div');
        avatar.className = 'avatar';
        var image = document.createElement('img');
        image.src = xmlDoc.getElementsByTagName('avatar')[i].innerHTML;
        var titles = document.createElement('div');
        titles.className = 'titles';
        var title = document.createElement('p');
        title.className = 'title';
        title.innerText = xmlDoc.getElementsByTagName('title')[i].innerHTML;
        var subtitle = document.createElement('p');
        subtitle.className = 'subtitle';
        var small = document.createElement('small');
        small.innerText = xmlDoc.getElementsByTagName('subtitle')[i].innerHTML;

        subtitle.appendChild(small);
        titles.appendChild(title);
        titles.appendChild(subtitle);

        avatar.appendChild(image);

        card.appendChild(avatar);
        card.appendChild(titles);

        a.appendChild(card);

        li.appendChild(a);
        ul.appendChild(li);
      }
    } else {
      // console.error(xhr.statusText);
    }
  }
};

xhr.onerror = function (e) {
  console.error(xhr.statusText);
};

xhr.send(null);
</script>
