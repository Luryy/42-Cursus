#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <ICharacter.hpp>

class Character : public ICharacter
{
	protected:
		AMateria			*inventory[4];
		std::string			name;

	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &character);
		virtual ~Character();

		Character	&operator=(const Character &character);

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};

#endif
