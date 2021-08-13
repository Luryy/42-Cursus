# CLONE YOUR SSH KEY
cd ~
git clone YOUR_SSH_REPO .ssh
cd .ssh
chmod 600 *
cd ..

# CLONE YOUR PROJECT
cd ~
git clone YOUR_INTRA_PROJECT ft_printf
cd ft_printf
norminette


# echo Test Paulo
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
sh test m
cd ..

# Teste tripoullie
echo Test Tripouille
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make m
make b
cd ..

