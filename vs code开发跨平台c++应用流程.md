# 基于Visual Studio Code开发跨平台c++应用流程总结

## 安装相关软件

### 安装编译器
    
* windows安装vs 2017或2019或2022 社区版

* linux安装gcc和g++

    命令行检测是否已安装gcc和g++
    ```
    gcc --version
    g++ --version
    ```

    如未安装，则命令行执行下列命令
    ```
    sudo apt install gcc
    sudo apt install g++
    ```

* macOS在AppStore安装xcode

### 安装visual studio code

网址：[https://code.visualstudio.com/](https://code.visualstudio.com/)
    
* Windows安装

    (1) 下载VSCodeUserSetup-x64-1.88.1.exe

    (2) 运行exe文件进行安装

* Ubuntu安装

    (1) 下载.deb安装包

    (2) 命令行执行下面命令，把<file>替换为实际下载文件的名称
    ```
    sudo apt install ./<file>.deb
    ```

* macOS安装

    (1) 下载VSCode-darwin-universal.zip

    (2) 双击下载的zip文件进行解压，把Visual Studio Code.app文件拖拽到Applications文件夹，使得VSCode在Lanchpad中可用
    
### 安装QT Creator

我们安装qtcreator的主要目的是用于编辑.ui界面文件,.qrc资源文件等

使用这个网址[https://www.qt.io/download-qt-installer](https://www.qt.io/download-qt-installer)，能自动下载对应操作系统的安装程序

或者，这个网址[https://www.qt.io/download](https://www.qt.io/download)有商业版和开源版的下载链接，在网页中选择[Download open source](https://www.qt.io/download-open-source)链接，大概在网页的右上方位置，然后在打开的链接的偏下位置选Qt Online installer，有Windows, macOS, linux三种系统的安装包下载

安装时，设置[国内镜像网站](https://mirrors.ustc.edu.cn/qtproject)安装比较快

* linux命令行安装

    (1) qt-unified-linux-x64-4.7.0-online.run --mirror https://mirrors.ustc.edu.cn/qtproject
    
    (2) 配置环境变量
    ```
    sudo vim /etc/profile
    ```
    在文件末尾增加下面两行，保存退出(:wq!), xxxx替换为相应的用户名
    ```
    export PATH="/home/xxxx/Qt/Tools/QtCreator/bin:$PATH"
    export PATH="/home/xxxx/Qt/6.6.3/gcc_64/bin:$PATH"
    ```
    (3) 使环境变量生效
    ```
    source /etc/profile
    ```

* windows命令行安装

    (1) qt-unified-windows-x64-4.7.0-online.exe --mirror https://mirrors.ustc.edu.cn/qtproject
    
    (2) 配置环境变量(略)

* macOS安装

    (1) 在Founder中双击下载的dmg文件(qt-unified-macOS-x64-4.7.0-online.dmg), 在弹出的文件上右键选择“显示包内容”，依次进入Contents->MacOS, 把qt-unified-macOS-x64-4.7.0-online文件拖拽到终端，在其后加上--mirror https://mirrors.ustc.edu.cn/qtproject
    
    (2) 配置环境变量
    ```
    sudo vim /etc/profile
    ```
    在文件末尾增加下面两行，保存退出(:wq!), xxxx替换为相应的用户名
    ```
    export PATH="/Users/xxxx/Qt6/Qt Creator.app/Contents/MacOS:$PATH"
    export PATH="/Users/xxxx/Qt6/6.6.3/macos/bin:$PATH"
    ```
    (3) 使环境变量生效
    ```
    source /etc/profile
    ```

### 安装cmake

网址：[https://cmake.org/download/](https://cmake.org/download/)

* Windows安装

    (1) 下载cmake-3.29.2-windows-x86_64.msi文件
    
    (2) 在资源管理器中双击此文件安装

* linux安装

    (1) 下载cmake-3.29.2-linux-x86_64.sh文件

    (2) 命令行运行
    ```
    sudo sh cmake-3.29.2-linux-x86_64.sh --prefix=/usr/local --exclude-subdir
    ```
    --exclude-subdir的作用是防止把cmake安装到/usr/local/cmake-3.29.2-linux-x86_64目录中

* macOS安装

    (1) 下载cmake-3.29.2-macos-universal.dmg文件

    (2) 在Finder中双击此文件安装

### 安装git
网址：[https://git-scm.org/download](https://git-scm.org/download)

* Windows安装(略)
    
* ubuntu命令行安装
    ```
    apt-get install git
    ```

* macOS下安装xcode自带git

## 常用第三方库(SDK)

### QT库

    QT库文件可以在前面安装qtcreator时安装某一版本的库(6.7或6.6.3), 也可以后续通过QT Maintennace Tool追加安装，或者拷贝已经下载好的文件

    可以在github下载obs使用的qt库
    https://github.com/obsproject/obs-deps/releases/download/2024-03-19/macos-deps-qt6-2024-03-19-x86_64.tar.xz
    https://github.com/obsproject/obs-deps/releases/download/2024-03-19/macos-deps-qt6-2024-03-19-arm64.tar.xz
    https://github.com/obsproject/obs-deps/releases/download/2024-03-19/macos-deps-qt6-2024-03-19-universal.tar.xz
    https://github.com/obsproject/obs-deps/releases/download/2024-03-19/windows-deps-qt6-2024-03-19-x64.zip

### Vulkan SDK

[https://www.lunarg.com/vulkan-sdk/](https://www.lunarg.com/vulkan-sdk/)

### FFMPEG

[https://ffmpeg.org](https://ffmpeg.org)

## 应用框架举例
```
├── test_projects
│   ├── core                    (公用的静态库和动态库放在这个目录下)
│   │   ├── test_dynamic_lib    (动态库示例)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── common.h
│   │   │   ├── function.cpp
│   │   │   ├── function.h
│   │   ├── test_static_lib     (静态库示例)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── function_static.cpp
│   │   │   ├── function_static.h
│   ├── sdk                     (第三方库放在这个目录下)
│   │   ├── ffmpeg
│   │   │   ├── bin
│   │   │   ├── include
│   │   │   ├── lib
│   │   ├── qt6
│   │   │   ├── bin
│   │   │   ├── include
│   │   │   ├── lib
│   │   ├── vulkan
│   │   │   ├── bin
│   │   │   ├── include
│   │   │   ├── lib
│   ├── test_app1               (第一个应用的目录)
│   │   ├── test_program1       (第一个应用的可执行项目)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── main.cpp
│   │   ├── test_lib1           (第一个应用相关的库)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── test_lib1.cpp
│   │   │   ├── test_lib1.h
│   │   ├── CMakeLists.txt
│   │   ├── CMakePresets.json
│   ├── test_app2               (第二个应用的目录)
│   │   ├── test_program2       (第二个应用的可执行项目)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── main.cpp
│   │   ├── test_lib2           (第二个应用相关的库)
│   │   │   ├── CMakeLists.txt
│   │   │   ├── test_lib2.cpp
│   │   │   ├── test_lib2.h
│   │   ├── CMakeLists.txt
│   │   ├── CMakePresets.json
```

## Q&A
### Q: macOS下配置CMake+QT项目时，有可能弹出类似‘无法打开“moc”，因为无法验证开发者’的对话框提示

A: 打开Terminal，输入下面命令
``` 
sudo spctl --master-disable
```

