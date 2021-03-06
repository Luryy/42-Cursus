#!/bin/bash
# CLONE YOUR PROJECT
cd ~
git clone your_ssh_key_repo .ssh
cd .ssh
chmod 600 *
cd ..


git clone your_libft_repo libft
cd libft
norminette *.c *.h

# CLONE ALL GITHUB TESTERS
cd ..
git clone https://github.com/jtoty/Libftest.git
git clone https://github.com/alelievr/libft-unit-test.git
git clone https://github.com/ska42/libft-war-machine.git
git clone https://github.com/Tripouille/libftTester.git

# RUN Libftest
cd Libftest
./grademe.sh
./grademe.sh
cd ..

# RUN libft-unit-test
cd libft-unit-test
make f
cd ..

# RUN libft-war-machine
cd libft-war-machine
./grademe.sh
sed -i '' "s/PATH_LIBFT=../PATH_LIBFT=..\/libft/" my_config.sh
./grademe.sh
cd ..

# RUN libftTester
cd libftTester
# CONFIGURE MAKEFILE MANUALLY: FT_PATH=../libft
sed -i '' "s/\$(PARENT_DIR)/..\/libft/" Makefile
sed -i '' "s/..\/libft\/libf/\$(PARENT_DIR)\/libf/" Makefile
make
cd ..

# CLEANUP
rm -rf libft Libftest libft-unit-test libft-war-machine libftTester
