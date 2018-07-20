# Homework 1
[![Build Status](https://travis-ci.org/shaj/Helloworld-otus.svg?branch=master)](https://travis-ci.org/shaj/Helloworld-otus)
[ ![Download](https://api.bintray.com/packages/andreyshaj/otuscpp/helloworld/images/download.svg) ](https://bintray.com/andreyshaj/otuscpp/helloworld/_latestVersion)

### How to install latest gcc on Ubuntu LTS (12.04, 14.04, 16.04)
https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91
```
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 60 --slave /usr/bin/g++ g++ /usr/bin/g++-7 
sudo update-alternatives --config gcc
```
### Клонирование
```
git clone ...
git submodule init
git submodule update
```
### Установка из bintray
```
echo "deb http://dl.bintray.com/andreyshaj/otuscpp trusty main" | sudo tee -a /etc/apt/sources.list
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 379CE192D401AB61
sudo apt update
sudo apt install helloworld
```
