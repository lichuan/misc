如果想通过putty或者securecrt连接到远程主机，想用图形界面操作emacs的话， 可以下载
一个xming的windows下的x-server端，安装后，再允许securecrt选forward x11选项，
就可以操作了，如果字体太小，则在linux主机下新建一个.Xresources的文件，再用
xrdb -load ~/.Xresources 进行加载， 字体就正常了。
还有一种方法就是直接在xming中的xlaunch中设置附加参数 -dpi 80
