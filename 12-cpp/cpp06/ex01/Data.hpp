#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		int	i;

	public:
		Data(void);
		virtual ~Data(void);
		Data(const Data &data);
		Data	&operator=(const Data &data);
		int getI(void) const;
};

# endif
