# hostname

The hostname is the name of your machine (not username).

- `hostname`: returns the hostname of the machine.

## Why do I care about a `hostname`

In a local network one can ssh into a machine without knowing the ip adress, with hostname.

For example if a machine has `davidmac` as `hostname` one can ping the machine with `ping davidmac.local`.

This is useful, for example, to see the ip adress of the machine.

### Example

I want to know the ip adress of a machine named `macminiserver`. I can do from another machine `ping macminiserver.local`.

```
ping macminiserver.local
PING macminiserver.local (192.168.1.98): 56 data bytes
64 bytes from 192.168.1.98: icmp_seq=0 ttl=64 time=4.992 ms
```




## Change  `hostname` permanently

Run 
```
sudo hostnamectl set-hostname new-hostname
```

Then edit 

```
sudo nano /etc/hosts
```

And ensure there is the `new-hostname`.

Then reboot the machine


