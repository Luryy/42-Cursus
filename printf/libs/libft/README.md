- You should copy all of your libft to here


- Should update Makefile
Replacing line
```
29 LIBFT_PATH = ../$(LIBFT)
```
To
```
LIBFT_PATH = $(LIBS_PATH)/$(LIBFT)
```

- Should update ft_print.h
Replacing line
```
16 # include "../../libft/libft.h"
```
To
```
# include "../libs/libft/libft.h"
```
