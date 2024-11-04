#### Check your WAN ip adress (router)

curl `ipinfo.io/ip`

```
67.218.254.229
```


#### Check if you are connected `ping`


If you do `ping someurl` and get an output it means you are connected to the internet

```
ping google.com
PING google.com (216.58.201.142): 56 data bytes
64 bytes from 216.58.201.142: icmp_seq=0 ttl=56 time=14.518 ms
64 bytes from 216.58.201.142: icmp_seq=1 ttl=56 time=14.411 ms
```

#### IP adress a machine `ipconfig` (ethernet)
To get the ip adress of a machine conected via ethernet using `en0` you can do:

```
ipconfig getifaddr en0
```

This should return a number. For example:
`192.168.1.131`
 
#### IP adress of a machine `ipconfig` (wifi)
```
ipconfig getifaddr en1
```

- Example

```
192.168.1.133
```

#### Turn on/off internet conection

Assuming you are connected to `en0` you can close your internet conection with:

```
sudo ifconfig en0 down
```
You can gain access to the internet again with:

```
sudo ifconfig en0 up
```


#### IP adress of a machine with `ifconfig`
```
ifconfig
```

```
ifconfig en0
```
- Example on a machine connected via wifi. Notice `status: inactive` and there is no ip adress.

```
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=10b<RXCSUM,TXCSUM,VLAN_HWTAGGING,AV>
	ether 78:7b:8a:b3:f5:de 
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect (none)
	status: inactive
```

- Example on a machine connected via wifi. Notice `status: active` and `inet 192.168.1.1333`

```
ifconfig en1
```
```
en1: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	ether a8:be:27:c2:98:c0 
	inet6 fe80::18d4:892d:2679:c84f%en1 prefixlen 64 secured scopeid 0x7 
	inet 192.168.1.133 netmask 0xffffff00 broadcast 192.168.1.255
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect
	status: active
```

#### IP adresses of all devices in a network with `arp -a`

```
arp -a
```

- Example:
```
? (192.168.1.1) at 8c:e1:17:ef:cc:9d on en0 ifscope [ethernet]
? (192.168.1.34) at (incomplete) on en0 ifscope [ethernet]
? (192.168.1.133) at a8:be:27:c2:98:c0 on en0 ifscope [ethernet]
? (192.168.1.139) at ac:9e:17:85:4f:73 on en0 ifscope [ethernet]
? (192.168.1.255) at ff:ff:ff:ff:ff:ff on en0 ifscope [ethernet]
? (224.0.0.251) at 1:0:5e:0:0:fb on en0 ifscope permanent [ethernet]
? (239.255.255.250) at 1:0:5e:7f:ff:fa on en0 ifscope permanent [ethernet]
broadcasthost (255.255.255.255) at ff:ff:ff:ff:ff:ff on en0 ifscope [ethernet]
```

##### Apply regular expresison on the output
We can use `|` to apply `grep` at the output of the  text given by `arp -a` and print
only all the lines that contain `192`. Doing this we can filter rellevant information
about the ip adresses.

```
arp -a | grep "192.*"
```
```
? (192.168.1.1) at 8c:e1:17:ef:cc:9d on en0 ifscope [ethernet]
? (192.168.1.34) at (incomplete) on en0 ifscope [ethernet]
? (192.168.1.133) at a8:be:27:c2:98:c0 on en0 ifscope [ethernet]
? (192.168.1.255) at ff:ff:ff:ff:ff:ff on en0 ifscope [ethernet]
```


#### IP adress of all devices in a network
```
ifconfig
```

- Example

```
lo0: flags=8049<UP,LOOPBACK,RUNNING,MULTICAST> mtu 16384
	options=1203<RXCSUM,TXCSUM,TXSTATUS,SW_TIMESTAMP>
	inet 127.0.0.1 netmask 0xff000000 
	inet6 ::1 prefixlen 128 
	inet6 fe80::1%lo0 prefixlen 64 scopeid 0x1 
	nd6 options=201<PERFORMNUD,DAD>
gif0: flags=8010<POINTOPOINT,MULTICAST> mtu 1280
stf0: flags=0<> mtu 1280
XHC20: flags=0<> mtu 0
XHC0: flags=0<> mtu 0
en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=10b<RXCSUM,TXCSUM,VLAN_HWTAGGING,AV>
	ether 78:7b:8a:b3:f5:de 
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect (none)
	status: inactive
en1: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	ether a8:be:27:c2:98:c0 
	inet6 fe80::18d4:892d:2679:c84f%en1 prefixlen 64 secured scopeid 0x7 
	inet 192.168.1.133 netmask 0xffffff00 broadcast 192.168.1.255
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect
	status: active
p2p0: flags=8843<UP,BROADCAST,RUNNING,SIMPLEX,MULTICAST> mtu 2304
	ether 0a:be:27:c2:98:c0 
	media: autoselect
	status: inactive
awdl0: flags=8943<UP,BROADCAST,RUNNING,PROMISC,SIMPLEX,MULTICAST> mtu 1484
	ether d6:c6:e3:4b:68:c0 
	inet6 fe80::d4c6:e3ff:fe4b:68c0%awdl0 prefixlen 64 scopeid 0x9 
	nd6 options=201<PERFORMNUD,DAD>
	media: autoselect
	status: active
en2: flags=8963<UP,BROADCAST,SMART,RUNNING,PROMISC,SIMPLEX,MULTICAST> mtu 1500
	options=60<TSO4,TSO6>
	ether c2:00:a5:28:b5:00 
	media: autoselect <full-duplex>
	status: inactive
en3: flags=8963<UP,BROADCAST,SMART,RUNNING,PROMISC,SIMPLEX,MULTICAST> mtu 1500
	options=60<TSO4,TSO6>
	ether c2:00:a5:28:b5:01 
	media: autoselect <full-duplex>
	status: inactive
bridge0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
	options=63<RXCSUM,TXCSUM,TSO4,TSO6>
	ether c2:00:a5:28:b5:00 
	Configuration:
		id 0:0:0:0:0:0 priority 0 hellotime 0 fwddelay 0
		maxage 0 holdcnt 0 proto stp maxaddr 100 timeout 1200
		root id 0:0:0:0:0:0 priority 0 ifcost 0 port 0
		ipfilter disabled flags 0x2
	member: en2 flags=3<LEARNING,DISCOVER>
	        ifmaxaddr 0 port 10 priority 0 path cost 0
	member: en3 flags=3<LEARNING,DISCOVER>
	        ifmaxaddr 0 port 11 priority 0 path cost 0
	nd6 options=201<PERFORMNUD,DAD>
	media: <unknown type>
	status: inactive
utun0: flags=8051<UP,POINTOPOINT,RUNNING,MULTICAST> mtu 1380
	inet6 fe80::2051:8661:d939:9b3d%utun0 prefixlen 64 scopeid 0xd 
	inet6 fd04:cf0b:f70f:11aa:2051:8661:d939:9b3d prefixlen 64 
	nd6 options=201<PERFORMNUD,DAD>
utun1: flags=8051<UP,POINTOPOINT,RUNNING,MULTICAST> mtu 2000
	inet6 fe80::15c6:c4c1:f7be:5d40%utun1 prefixlen 64 scopeid 0xe 
	nd6 options=201<PERFORMNUD,DAD>

```
