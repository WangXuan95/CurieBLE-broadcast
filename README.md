# Arduino 101 广播数据功能

### 概述：
    支持 Arduino 101 广播收发 2字节数据，信道共享，无需建立连接，不同的广播设备用UUID来区分。

    
### 广播发送
    广播发送是CurieBLE库自带的功能，不需要修改库源码。只需上传示例程序../BLE-broadcast/BLE-broadcast.ino 到你的Arduino 101。然后打开手机APP: NRF connect，点击scan，在下方显示的设备中展开"Curie"，在Service Data里可以看到，UUID=0x1234，Data每秒+1。


### 广播接收
    广播接收是CurieBLE库不具备的功能，我修改了CurieBLE库的源码。修改后的库在./CurieBLE.zip。请解压后替代原来的库，在Windows上，该库的位置是：

    C:\Users\[user name]\AppData\Local\Arduino15\packages\Intel\hardware\arc32\[version]\libraries\CurieBLE

    请在替代前备份原来的库。

    替代完成后，上传./BLE-readBroadcast/BLE-readBroadcast.ino 到你的Arduino 101。然后打开串口监视器，可以发现Arduino 101在不断搜索广播。此时若另一个上传了BLE-broadcast.ino的Arduino 101上电，可以看到它广播的UUID和Data被打印出来。

### 更复杂的广播网络

    可以使用3块Arduino101：A, B, C

    给A上传BLE-broadcast.ino。

    给B上传BLE-broadcast.ino。上传之前把第4行的"1234"改成"1235"

    给C上传BLE-readBroadcast.ino。然后打开串口监视器，可以同时收到来自A和B的数据。


### 注意事项
    1、每个Arduino 101可以接收多个广播UUID，但只能广播一个UUID。

    2、广播发送和广播接收例程中，UUID必须相同才可以接收到数据。

    3、若想用多个设备发送广播，则不同设备选用不同的UUID，便于区分不同设备