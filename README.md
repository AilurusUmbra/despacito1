# despacito1
Media streaming test edit

## hls_multistream.c
Use `ffmpeg` for HLS streaming based on nginx.

call `fork()` in c to create multiple stream.

This version use system call to pass ffmpeg instruction to kernel.

For watching the streaming video, connect `http://localhost/hls/stream_name` by Safari or Edge browser, or use html5 video tag.


## watch_stream.html

Use `<video>` tag in HTML5 to watch an HLS stream video, and show the current time of playing video by setting `ontimeupdate` event to display currentTime property of video element whenever event is triggered.

You can use several `<video>` tags to watch many videos at the same time.
