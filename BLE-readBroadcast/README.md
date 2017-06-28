# Arduino 101 广播接收
    广播接收是CurieBLE库不具备的功能，我修改了CurieBLE库的源码。修改后的库在./CurieBLE.zip。请解压后替代原来的库，在Windows上，该库的位置是：

    C:\Users\[user name]\AppData\Local\Arduino15\packages\Intel\hardware\arc32\[version]\libraries\CurieBLE

    请在替代前备份原来的库。

    替代完成后，上传 BLE-readBroadcast.ino 到你的Arduino 101。然后打开串口监视器，可以发现Arduino 101在不断搜索广播。此时若另一个上传了BLE-broadcast.ino的Arduino 101上电，可以看到它广播的UUID和Data被打印出来。