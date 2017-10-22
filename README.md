# despacito1
Media streaming test

## hls_multistream.c
Call ffmpeg for HLS streaming based on nginx.
Call fork() in c to create multiple stream.
This version use system call to pass ffmpeg instruction to kernel.
For watching the streaming video, connect http://localhost/hls/streamname by Safari or Edge browser, or use html5 video tag.
