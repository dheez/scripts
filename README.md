# scripts
Just some scripts I found on github
or wrote myself for fun or to make life easier.  \
putting them on github to easily download them on my
other machines. \
feel free to use and edit for your own usecase!

## yt
dependencies: dmenu, fzf, youtube-dl  \
added -s option to script to read from your .subscribedlist.txt file
in your .config folder. It gets created automatically but is empty.  \
Just echo your favorite youtubers channel names into the txt file!
```bash
echo youtuber >> .config/.subscribedlist.txt
```
Problem with this is, that you have to use the actual channelname of the youtuber (the name that
is in the link!! It's not always the same as the current channel name of the youtuber.)  \
To find out the channel name, go to the yt channel of the youtuber and look inside the link. You can to it!  \
Also, to use the -s option, you have to have dmenu installed.  \
originally (without -s option) by https://github.com/sayan01

## twch
dependencies: dmenu, youtube-dl  \
works similarly to yt, but alot simpler. Using the script opens dmenu and prompts you to type in a twitch streamer name.  \
If the streamer is online, it will play the stream and put him into a txt file which gets read by the script the next time (so you can
more easily choose the streamers.)  \
If the streamer is offline, it does not put the name in the list and tells you that the streamer is offline! simple as that. 

## mntctl
dependencies: dmenu, systemd (this version)  \
just a small script to mount/unmount usb drives. Since I use a Window Manager and don't want to type everything
into the terminal all the time. \
edit the udisksctl lines to fit your use case (if you do not use systemd, like me on my laptop) 

## redyt
dependencies: dmenu, sxiv, wget  \
go to https://github.com/Bugswriter for more information. I just use his script to browse dank memes :D
