# despacito1
Media streaming test

## hls_multistream.c
Use `ffmpeg` for HLS streaming based on nginx.

call `fork()` in c to create multiple stream.

This version use system call to pass ffmpeg instruction to kernel.

For watching the streaming video, connect `http://localhost/hls/stream_name` by Safari or Edge browser, or use html5 video tag.
