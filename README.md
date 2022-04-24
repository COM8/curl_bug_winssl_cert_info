# curl_bug_winssl_cert_info

## Building

```bash
git clone https://github.com/COM8/curl_bug_winssl_cert_info.git
cd curl_bug_winssl_cert_info
mkdir build
cd build
cmake ..
cmake --build .
```

## Executing

Form inside the `build/` directory run:
### Windows

```bash
.\Debug\curl_bug_winssl_cert_info.exe
```


This then should produce the following output:
```
curl_easy_perform() failed: Out of memory
```
