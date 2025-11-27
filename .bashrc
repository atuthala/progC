alias new='touch new.txt'

alias cps='clang-format -i /storage/emulated/0/Documents/progCpp/main.cpp && for F in /storage/emulated/0/Documents/progCpp/* ; do cp -ar "$F" ./ ; done && clang++ -w main.cpp -o file.out -fsanitize=address -g -O1 -fno-omit-frame-pointer -fno-optimize-sibling-calls && ./file.out'

alias c='clear'

alias l='ls -la'

alias cpin='rm -r /storage/emulated/0/Documents/progCpp/* && cp -a ./ /storage/emulated/0/Documents/progCpp/'

