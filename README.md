# scripts
Just some scripts I found on github
or wrote myself for fun or to make life easier.  \
putting them on github to easily download them on my
other machines. \
feel free to use and edit for your own usecase!

## yt
dependencies: dmenu, fzf, youtube-dl, mpv \
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
dependencies: dmenu, youtube-dl, mpv, streamlink  \
works similarly to yt, but alot simpler. Using the script opens dmenu and prompts you to type in a twitch streamer name.  \
If the streamer is online, it will play the stream and put him into a txt file which gets read by the script the next time (so you can
more easily choose the streamers.)  \
If the streamer is offline, it does not put the name in the list and tells you that the streamer is offline! simple as that. \
uses streamlink now, because of annoying ad breaks which take longer than a minute... \
just download streamlink from your package manager. \
you can use it with any media player, I use mpv, u have to edit the script where it says mpv to match your own mediaplayer (for example vlc) \
streamlinks default media player is vlc I think. \

## mntctl
dependencies: dmenu, systemd (this version)  \
just a small script to mount/unmount usb drives. Since I use a Window Manager and don't want to type everything
into the terminal all the time. \
edit the udisksctl lines to fit your use case (if you do not use systemd, like me on my laptop) 

## redyt
dependencies: dmenu, sxiv, wget  \
go to https://github.com/Bugswriter for more information. I just use his script to browse dank memes :D

## vimtex
dependencies: texlive-full, (vim, termite), mupdf \
A script I wrote, which opens vim in a new terminal (in this case termite) and mupdf, everytime you write to your tex file, the mupdf file updates, \
so you get a live view of the pdf file your working on. \
would work for any texteditor and probably any terminal emulator, you just gotta edit the lines in the short script to use your specific programs (for example gedit or something)

## music
dependencies: dmenu, mpv \
simple dmenu script to choose music in your Music directory in your home directory. Obivously you must create one first and put your albums/playlists in it (folders with music files) \
has a shuffle option "-s" and a choose option "-c" in which you choose song. \
default option is playing the songs in order. \
usage: for example music -s or music -c in terminal or dmenu
